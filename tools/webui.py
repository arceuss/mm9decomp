#!/usr/bin/env python3

###
# Local progress dashboard for the decomp. Standard library only.
#
# Usage:
#   python tools/webui.py [--port 8099] [--host 127.0.0.1]
# then open http://127.0.0.1:8099/
#
# Reads build/WR9E/report.json (refresh it with `ninja`), config/WR9E/symbols.txt,
# src/game/ and the worker logs in build/opencode/*.log. The page polls every few
# seconds, so new source files and worker output show up without reloading.
###

import argparse
import json
import re
import subprocess
import sys
import threading
import time
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from typing import Any, Dict, List, Optional
from urllib.parse import parse_qs, urlparse

ROOT = Path(__file__).resolve().parent.parent
VERSION = "WR9E"
BUILD = ROOT / "build" / VERSION
SYMBOLS = ROOT / "config" / VERSION / "symbols.txt"
SRC_GAME = ROOT / "src" / "game"
LOG_DIR = ROOT / "build" / "opencode"

TEXT_START = 0x8000BF80
TEXT_END = 0x80253614
# Game code ends where the RVL SDK starts (EXI, SetExiInterruptMask). See docs/STATUS.md.
GAME_END = 0x800EB1CC

_build_lock = threading.Lock()
_build_state: Dict[str, Any] = {"running": False, "output": "", "finished": None, "ok": None}

# Parked non-matching attempts live in build/<worker>/nonmatching/unit_<ADDR>.c.
# Their match % comes from funcdiff, computed in the background and cached by
# (path, mtime) so the status poll stays cheap.
_score_lock = threading.Lock()
_scores: Dict[str, Tuple[float, float]] = {}  # path -> (mtime, percent)
_score_queue: List[Path] = []


def attempts() -> Dict[str, List[Path]]:
    out: Dict[str, List[Path]] = {}
    for p in (ROOT / "build").glob("*/nonmatching/unit_*.c"):
        out.setdefault("fn_" + p.stem[len("unit_"):], []).append(p)
    return out


def attempt_percent(p: Path) -> Optional[float]:
    with _score_lock:
        hit = _scores.get(str(p))
        mtime = p.stat().st_mtime
        if hit and hit[0] == mtime:
            return hit[1]
        if p not in _score_queue:
            _score_queue.append(p)
    return None


def _score_worker() -> None:
    while True:
        with _score_lock:
            p = _score_queue.pop(0) if _score_queue else None
        if p is None:
            time.sleep(2)
            continue
        try:
            mtime = p.stat().st_mtime
            r = subprocess.run([sys.executable, "tools/funcdiff.py", str(p), "fn_" + p.stem[len("unit_"):]],
                               cwd=ROOT, capture_output=True, text=True, timeout=120)
            m = re.search(r": ([0-9.]+)% \(", r.stdout)
            with _score_lock:
                _scores[str(p)] = (mtime, float(m.group(1)) if m else 0.0)
        except (OSError, subprocess.TimeoutExpired):
            pass


threading.Thread(target=_score_worker, daemon=True).start()


def read_symbols() -> List[Dict[str, Any]]:
    pat = re.compile(r"^(\S+) = \.text:0x([0-9A-F]+); // type:function size:0x([0-9A-F]+)", re.M)
    out = []
    for m in pat.finditer(SYMBOLS.read_text()):
        out.append({"name": m.group(1), "addr": int(m.group(2), 16), "size": int(m.group(3), 16)})
    out.sort(key=lambda f: f["addr"])
    return out


def read_report() -> Optional[Dict[str, Any]]:
    p = BUILD / "report.json"
    if not p.exists():
        return None
    try:
        return json.loads(p.read_text())
    except (OSError, ValueError):
        return None


def status() -> Dict[str, Any]:
    funcs = read_symbols()
    report = read_report()

    # function name -> (fuzzy match %, linked) for every function that has source in the build
    built: Dict[str, Any] = {}
    linked_units = 0
    units = []
    if report:
        for u in report.get("units", []):
            meta = u.get("metadata", {})
            if meta.get("auto_generated") or not meta.get("source_path"):
                continue
            m = u.get("measures", {})
            complete = bool(meta.get("complete"))
            linked_units += complete
            for f in u.get("functions", []):
                built[f["name"]] = (f.get("fuzzy_match_percent", 0.0), complete)
            units.append({
                "name": u["name"].split("/", 1)[-1],
                "source": meta.get("source_path"),
                "fuzzy": m.get("fuzzy_match_percent", 0.0),
                "code": int(m.get("total_code", 0)),
                "linked": complete,
            })

    src_files = sorted(SRC_GAME.glob("unit_*.c"), key=lambda p: p.stat().st_mtime, reverse=True)
    src_fns = {"fn_" + p.stem[len("unit_"):] for p in src_files}
    tried = attempts()

    game = {"funcs": 0, "bytes": 0, "matched_funcs": 0, "matched_bytes": 0,
            "unlinked_funcs": 0, "unlinked_bytes": 0, "pending_funcs": 0, "pending_bytes": 0,
            "tried_funcs": 0, "tried_bytes": 0}
    fmap = []
    tried_rows = []
    for f in funcs:
        if f["addr"] < TEXT_START:
            continue
        in_game = f["addr"] < GAME_END
        if f["name"] in built:
            pct, linked = built[f["name"]]
            st = ("match" if linked else "unlinked") if pct == 100.0 else "partial"
        elif f["name"] in src_fns:
            st = "pending"  # file in src/game, not in the build yet (unchecked)
        elif f["name"] in tried:
            st = "tried"
        else:
            st = "none"
        if st == "tried":
            best = None
            rows = []
            for p in tried[f["name"]]:
                pct = attempt_percent(p)
                rows.append({"path": str(p.relative_to(ROOT)).replace("\\", "/"),
                             "who": p.parent.parent.name, "pct": pct, "mtime": p.stat().st_mtime})
                if pct is not None and (best is None or pct > best):
                    best = pct
            tried_rows.append({"name": f["name"], "addr": f["addr"], "size": f["size"],
                               "best": best, "attempts": rows})
        if in_game:
            game["funcs"] += 1
            game["bytes"] += f["size"]
            if st in ("match", "unlinked", "pending", "tried"):
                key = {"match": "matched", "unlinked": "unlinked", "pending": "pending", "tried": "tried"}[st]
                game[key + "_funcs"] += 1
                game[key + "_bytes"] += f["size"]
        fmap.append([f["name"], f["addr"], f["size"], st, in_game])
    ok_file = BUILD / "ok"
    dol = BUILD / "mm9-game.dol"
    dol_ok = ok_file.exists() and dol.exists() and ok_file.stat().st_mtime >= dol.stat().st_mtime

    return {
        "time": time.time(),
        "report_time": (BUILD / "report.json").stat().st_mtime if report else None,
        "all": report.get("measures") if report else None,
        "game": game,
        "linked_units": linked_units,
        "units": units,
        "dol_ok": dol_ok,
        "recent_src": [{"file": p.name, "mtime": p.stat().st_mtime} for p in src_files[:40]],
        "src_count": len(src_files),
        "logs": [{"name": p.name, "size": p.stat().st_size, "mtime": p.stat().st_mtime}
                 for p in sorted(LOG_DIR.glob("*.log"), key=lambda p: p.stat().st_mtime, reverse=True)]
                if LOG_DIR.exists() else [],
        "map": fmap,
        "tried": tried_rows,
        "range": [TEXT_START, TEXT_END, GAME_END],
        "build": {k: v for k, v in _build_state.items() if k != "output"},
    }


def log_tail(name: str, max_bytes: int = 60000) -> str:
    p = (LOG_DIR / name).resolve()
    if p.parent != LOG_DIR.resolve() or not p.exists():
        return "no such log"
    data = p.read_bytes()[-max_bytes:]
    text = data.decode("utf-8", "replace")
    return re.sub(r"\x1b\[[0-9;?]*[A-Za-z]", "", text)  # drop terminal colour codes


def funcdiff(fn: str, path: str = "") -> str:
    if not re.fullmatch(r"fn_[0-9A-F]{8}", fn):
        return "bad function name"
    if path:
        # only parked attempts may be diffed by path, nothing else on disk
        src = (ROOT / path).resolve()
        if src not in [p.resolve() for p in attempts().get(fn, [])]:
            return f"{path} isn't a parked attempt for {fn}"
        if not src.exists():
            return f"{path} doesn't exist"
    else:
        src = SRC_GAME / f"unit_{fn[3:]}.c"
        if not src.exists():
            alts = attempts().get(fn)
            if not alts:
                return f"{src.relative_to(ROOT)} doesn't exist and nobody has tried {fn} yet"
            src = max(alts, key=lambda p: p.stat().st_mtime)
    r = subprocess.run([sys.executable, "tools/funcdiff.py", str(src), fn],
                       cwd=ROOT, capture_output=True, text=True)
    head = f"source: {src.relative_to(ROOT)}\n"
    return head + r.stdout + r.stderr


def source_text(fn: str, path: str = "") -> str:
    if not re.fullmatch(r"fn_[0-9A-F]{8}", fn):
        return ""
    cands = [SRC_GAME / f"unit_{fn[3:]}.c"] + sorted(attempts().get(fn, []), key=lambda p: -p.stat().st_mtime)
    if path:
        cands = [p for p in cands if p.resolve() == (ROOT / path).resolve()]
    for p in cands:
        if p.exists():
            return p.read_text(errors="replace")
    return ""


def run_build() -> None:
    with _build_lock:
        if _build_state["running"]:
            return
        _build_state.update(running=True, output="", ok=None)

    def work() -> None:
        out = []
        ok = True
        steps = ([sys.executable, "tools/twins.py"], [sys.executable, "tools/sync_units.py"],
                 [sys.executable, "configure.py"], ["ninja"])
        for cmd in steps:
            r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
            out.append(f"$ {' '.join(cmd)}\n{r.stdout}{r.stderr}")
            if r.returncode != 0:
                ok = False
                break
        _build_state.update(running=False, output="\n".join(out), ok=ok, finished=time.time())

    threading.Thread(target=work, daemon=True).start()


class Handler(BaseHTTPRequestHandler):
    def log_message(self, fmt: str, *args: Any) -> None:
        pass  # polling would flood the console

    def send(self, body: str, ctype: str = "application/json", code: int = 200) -> None:
        data = body.encode("utf-8")
        self.send_response(code)
        self.send_header("Content-Type", ctype + "; charset=utf-8")
        self.send_header("Content-Length", str(len(data)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.wfile.write(data)

    def do_GET(self) -> None:
        url = urlparse(self.path)
        q = parse_qs(url.query)
        if url.path == "/":
            self.send(PAGE, "text/html")
        elif url.path == "/api/status":
            self.send(json.dumps(status()))
        elif url.path == "/api/log":
            self.send(json.dumps({"text": log_tail(q.get("name", [""])[0])}))
        elif url.path == "/api/diff":
            self.send(json.dumps({"text": funcdiff(q.get("fn", [""])[0], q.get("path", [""])[0])}))
        elif url.path == "/api/source":
            self.send(json.dumps({"text": source_text(q.get("fn", [""])[0], q.get("path", [""])[0])}))
        elif url.path == "/api/build":
            self.send(json.dumps(_build_state))
        else:
            self.send(json.dumps({"error": "not found"}), code=404)

    def do_POST(self) -> None:
        if urlparse(self.path).path == "/api/build":
            run_build()
            self.send(json.dumps({"started": True}))
        else:
            self.send(json.dumps({"error": "not found"}), code=404)


PAGE = """<!doctype html>
<html><head><meta charset="utf-8"><title>mm9 decomp</title>
<style>
body{font:14px system-ui,sans-serif;margin:0;background:#15171c;color:#dde}
header{padding:10px 16px;background:#1d2027;display:flex;gap:24px;align-items:baseline;flex-wrap:wrap}
h1{font-size:18px;margin:0}
.grid{display:grid;grid-template-columns:1fr 1fr;gap:12px;padding:12px}
.card{background:#1d2027;border-radius:6px;padding:10px 12px;min-width:0}
.card h2{font-size:14px;margin:0 0 8px;color:#9ab}
.big{font-size:22px;font-weight:600}
.bar{height:10px;background:#2b2f38;border-radius:5px;overflow:hidden;margin:4px 0 8px;display:flex}
.bar i{display:block;height:100%}
.ok{color:#5c5}.bad{color:#e55}.muted{color:#889}
canvas{display:block;background:#101216;border-radius:4px;cursor:pointer}
#tip{display:none;position:absolute;pointer-events:none;background:#000d;border:1px solid #3a3f4a;border-radius:4px;padding:4px 6px;font-size:12px;white-space:nowrap;z-index:2}
pre{background:#101216;padding:8px;border-radius:4px;max-height:420px;overflow:auto;white-space:pre-wrap;font:12px ui-monospace,Consolas,monospace;margin:0}
table{border-collapse:collapse;width:100%;font-size:12px}td,th{padding:2px 6px;text-align:left;border-bottom:1px solid #2b2f38}
button,select,input{background:#2b2f38;color:#dde;border:1px solid #3a3f4a;border-radius:4px;padding:3px 8px}
a{color:#8bf;cursor:pointer}
.full{grid-column:1/3}
.legend span{display:inline-block;width:10px;height:10px;margin:0 4px 0 12px;vertical-align:middle}
</style></head><body>
<header><h1>Mega Man 9 matching decomp</h1>
<span id="dol"></span><span id="updated" class="muted"></span>
<button id="buildbtn">twins + sync + configure + ninja</button><span id="buildst" class="muted"></span></header>
<div class="grid">
 <div class="card"><h2>Game code (0x8000BF80..0x800EB1CC)</h2><div id="game"></div></div>
 <div class="card"><h2>Whole DOL (objdiff report)</h2><div id="all"></div></div>
 <div class="card full"><h2>Function map</h2>
  <select id="mapmode"><option value="game">game code, one cell per function</option>
  <option value="gamesize">game code, cells scaled by size</option><option value="all">whole .text, one cell per function</option></select>
  <select id="mapcell"><option value="7">small cells</option><option value="10" selected>medium cells</option><option value="14">large cells</option></select>
  <span class="muted">address order, left to right; click a cell to diff it</span>
  <div style="position:relative;margin-top:6px"><canvas id="map"></canvas><div id="tip"></div></div>
  <div class="legend muted"><span style="background:#4c4"></span>matched + linked
  <span style="background:#3a9"></span>matched, not linked
  <span style="background:#db3"></span>in src/game, not in build yet
  <span style="background:#c55"></span>tried, not matching
  <span style="background:#e74"></span>source, not matching
  <span style="background:#39414f"></span>game, untouched
  <span style="background:#22262e"></span>library</div>
  </div>
 <div class="card"><h2>Function diff (funcdiff)</h2>
  <input id="fn" placeholder="fn_8004DCBC" size="14"><button id="diffbtn">diff</button>
  <span id="srcsel"></span>
  <pre id="diff" style="margin-top:6px">click a function in the map, a list, or a recent file</pre>
  <pre id="src" class="muted" style="margin-top:6px;max-height:300px"></pre></div>
 <div class="card"><h2>Near misses (tried, not matching)</h2>
  <div class="muted" style="margin-bottom:4px">best attempt per function, from build/*/nonmatching; % is objdiff's, scored in the background</div>
  <div id="tried" style="max-height:560px;overflow:auto"></div></div>
 <div class="card full"><h2>Functions</h2>
  <select id="ffilter"><option value="todo">unmatched (untouched + tried)</option><option value="none">untouched</option>
  <option value="tried">tried, not matching</option><option value="match">matched</option><option value="all">all game</option></select>
  <select id="fsort"><option value="addr">by address</option><option value="size">smallest first</option><option value="sized">largest first</option></select>
  <input id="fsearch" placeholder="filter name/address" size="18">
  <span id="fcount" class="muted"></span>
  <div id="funcs" style="max-height:420px;overflow:auto;margin-top:6px"></div></div>
 <div class="card"><h2>Recent source files</h2><div id="recent" style="max-height:470px;overflow:auto"></div></div>
 <div class="card"><h2>Attempts by worker</h2><div id="who"></div></div>
 <div class="card full"><h2>Worker logs (build/opencode)</h2>
  <select id="logsel"></select> <label><input type="checkbox" id="follow" checked> follow</label>
  <pre id="log" style="margin-top:6px;max-height:520px"></pre></div>
 <div class="card full"><h2>Build output</h2><pre id="buildout" class="muted">not run from here yet</pre></div>
</div>
<script>
const $=id=>document.getElementById(id);
const pct=(a,b)=>b?(100*a/b).toFixed(3)+'%':'-';
const hex=n=>'0x'+n.toString(16).toUpperCase().padStart(8,'0');
const ago=t=>{const s=Math.round(Date.now()/1000-t);return s<60?s+'s ago':s<3600?Math.round(s/60)+'m ago':Math.round(s/3600)+'h ago'};
let S=null;
function bar(parts,total){return '<div class="bar">'+parts.map(([v,c])=>`<i style="width:${100*v/total}%;background:${c}"></i>`).join('')+'</div>'}
function render(){
 const g=S.game;
 $('game').innerHTML=`<div class="big">${pct(g.matched_bytes+g.unlinked_bytes,g.bytes)}</div>`+
  bar([[g.matched_bytes,'#4c4'],[g.unlinked_bytes,'#3a9'],[g.pending_bytes,'#db3'],[g.tried_bytes,'#c55']],g.bytes)+
  `matched+linked: <b>${g.matched_funcs}</b> / ${g.funcs} functions, ${g.matched_bytes} / ${g.bytes} bytes<br>`+
  `matched, not linked (jump table alignment): ${g.unlinked_funcs} functions, ${g.unlinked_bytes} bytes<br>`+
  `in src/game, not in build yet (unchecked): ${g.pending_funcs} functions, ${g.pending_bytes} bytes<br>`+
  `tried, not matching: ${g.tried_funcs} functions, ${g.tried_bytes} bytes<br>`+
  `untouched: ${g.funcs-g.matched_funcs-g.unlinked_funcs-g.pending_funcs-g.tried_funcs} functions<br>`+
  `source files in src/game: ${S.src_count} &middot; linked units: ${S.linked_units}`;
 renderTried(); renderFuncs(); renderWho();
 const a=S.all;
 $('all').innerHTML=a?`<div class="big">${(+a.matched_code_percent).toFixed(3)}%</div>`+
  bar([[+a.matched_code,'#4c4']],+a.total_code)+
  `code ${a.matched_code} / ${a.total_code} bytes &middot; ${a.matched_functions} / ${a.total_functions} functions<br>`+
  `units ${a.complete_units} / ${a.total_units} complete<br><span class="muted">report ${S.report_time?ago(S.report_time):'missing'} (refresh with ninja)</span>`
  :'<span class="bad">build/WR9E/report.json missing, run ninja</span>';
 $('dol').innerHTML=S.dol_ok?'<span class="ok">rebuilt DOL: SHA-1 OK</span>':'<span class="bad">rebuilt DOL: not verified</span>';
 $('updated').textContent='updated '+new Date(S.time*1000).toLocaleTimeString();
 $('recent').innerHTML='<table>'+S.recent_src.map(r=>{const fn='fn_'+r.file.slice(5,13);
  return `<tr><td><a onclick="diff('${fn}')">${r.file}</a></td><td class="muted">${ago(r.mtime)}</td></tr>`}).join('')+'</table>';
 const sel=$('logsel'),cur=sel.value;
 sel.innerHTML=S.logs.map(l=>`<option ${l.name==cur?'selected':''}>${l.name}</option>`).join('');
 const b=S.build;$('buildst').textContent=b.running?'building...':b.ok===null?'':(b.ok?'last build ok':'last build FAILED');
 drawMap();
}
// Each function owns whole cells, so every one of them is hoverable/clickable no
// matter how small it is. Size mode gives a function ceil(size/0x80) cells.
let mapCells=[], mapCols=1, mapSel=null;
function mapEntries(){
 const mode=$('mapmode').value;
 return mode=='all'?S.map:S.map.filter(m=>m[4]);
}
function drawMap(){
 const mode=$('mapmode').value,cs=+$('mapcell').value,c=$('map'),W=c.parentNode.clientWidth;
 mapCols=Math.max(1,Math.floor(W/cs));mapCells=[];
 for(const m of mapEntries()){
  const n=mode=='gamesize'?Math.max(1,Math.ceil(m[2]/0x80)):1;
  for(let i=0;i<n;i++)mapCells.push(m);
 }
 const rows=Math.ceil(mapCells.length/mapCols),H=rows*cs;
 c.width=W;c.height=H;c.style.width=W+'px';c.style.height=H+'px';
 const x=c.getContext('2d'),col={match:'#4c4',unlinked:'#3a9',pending:'#db3',tried:'#c55',partial:'#e74',none:'#39414f'};
 const gap=cs>=9?1:0;
 mapCells.forEach((m,i)=>{
  const cx=(i%mapCols)*cs,cy=Math.floor(i/mapCols)*cs;
  x.fillStyle=m[4]?col[m[3]]:(m[3]=='none'?'#22262e':col[m[3]]);
  x.fillRect(cx,cy,cs-gap,cs-gap);
  if(mapSel&&m[0]==mapSel){x.strokeStyle='#fff';x.lineWidth=1.5;x.strokeRect(cx+0.75,cy+0.75,cs-gap-1.5,cs-gap-1.5)}
 });
}
function cellAt(e){const r=$('map').getBoundingClientRect(),cs=+$('mapcell').value;
 const col=Math.floor((e.clientX-r.left)/cs),row=Math.floor((e.clientY-r.top)/cs);
 if(col<0||col>=mapCols)return null;return mapCells[row*mapCols+col]||null}
const stLabel={match:'matched + linked',unlinked:'matched, not linked',pending:'in src/game, not in build',tried:'tried, not matching',partial:'source, not matching',none:'untouched'};
$('map').onmousemove=e=>{const m=cellAt(e),t=$('tip');
 if(!m){t.style.display='none';return}
 const best=(S.tried.find(r=>r.name==m[0])||{}).best;
 t.innerHTML=`<b>${m[0]}</b> ${hex(m[1])}<br>size 0x${m[2].toString(16)} &middot; ${stLabel[m[3]]}${best!=null?' &middot; best '+best.toFixed(1)+'%':''}`;
 const r=$('map').getBoundingClientRect();t.style.display='block';
 t.style.left=Math.min(e.clientX-r.left+14,r.width-230)+'px';t.style.top=(e.clientY-r.top+14)+'px'};
$('map').onmouseleave=()=>{$('tip').style.display='none'};
$('map').onclick=e=>{const m=cellAt(e);if(m){mapSel=m[0];drawMap();diff(m[0])}};
for(const id of ['mapmode','mapcell'])$(id).onchange=()=>S&&drawMap();
const fmtp=p=>p==null?'<span class="muted">scoring…</span>':p.toFixed(2)+'%';
function pcol(p){return p==null?'':p>=95?'color:#db3':p>=85?'color:#e96':'color:#c55'}
function renderTried(){
 const rows=[...S.tried].sort((a,b)=>(b.best??-1)-(a.best??-1));
 $('tried').innerHTML=rows.length?'<table><tr><th>function</th><th>size</th><th>best</th><th>attempts</th></tr>'+rows.map(r=>
  `<tr><td><a onclick="diff('${r.name}')">${r.name}</a></td><td>0x${r.size.toString(16)}</td><td style="${pcol(r.best)}">${fmtp(r.best)}</td><td>`+
  r.attempts.map(a=>`<a onclick="diff('${r.name}','${a.path}')" title="${a.path}">${a.who}</a> <span class="muted">${a.pct==null?'…':a.pct.toFixed(1)}</span>`).join(' &middot; ')+
  '</td></tr>').join('')+'</table>':'<span class="muted">nothing parked yet</span>';
}
function renderWho(){
 const w={};for(const r of S.tried)for(const a of r.attempts){w[a.who]=w[a.who]||{n:0,near:0};w[a.who].n++;if(a.pct!=null&&a.pct>=95)w[a.who].near++}
 const k=Object.keys(w).sort();
 $('who').innerHTML=k.length?'<table><tr><th>worker dir</th><th>parked attempts</th><th>&ge;95%</th></tr>'+k.map(n=>`<tr><td>build/${n}</td><td>${w[n].n}</td><td>${w[n].near}</td></tr>`).join('')+'</table>'
  :'<span class="muted">no parked attempts</span>';
}
function renderFuncs(){
 const f=$('ffilter').value,s=$('fsort').value,q=$('fsearch').value.trim().toUpperCase().replace(/^0X/,'');
 const best={};for(const r of S.tried)best[r.name]=r.best;
 let rows=S.map.filter(m=>m[4]).filter(m=>f=='all'||(f=='todo'?(m[3]=='none'||m[3]=='tried'):f=='match'?(m[3]=='match'||m[3]=='unlinked'):m[3]==f));
 if(q)rows=rows.filter(m=>m[0].toUpperCase().includes(q));
 if(s=='size')rows.sort((a,b)=>a[2]-b[2]);else if(s=='sized')rows.sort((a,b)=>b[2]-a[2]);
 $('fcount').textContent=`${rows.length} functions`+(rows.length>400?' (showing 400)':'');
 const lab={match:'matched',unlinked:'matched, not linked',pending:'not in build',tried:'tried',partial:'source, not matching',none:'untouched'};
 $('funcs').innerHTML='<table><tr><th>function</th><th>address</th><th>size</th><th>status</th><th>best attempt</th></tr>'+rows.slice(0,400).map(m=>
  `<tr><td><a onclick="diff('${m[0]}')">${m[0]}</a></td><td>${hex(m[1])}</td><td>0x${m[2].toString(16)}</td><td>${lab[m[3]]}</td><td style="${pcol(best[m[0]])}">${m[0] in best?fmtp(best[m[0]]):''}</td></tr>`).join('')+'</table>';
}
for(const id of ['ffilter','fsort'])$(id).onchange=()=>S&&renderFuncs();
$('fsearch').oninput=()=>S&&renderFuncs();
async function diff(fn,path){$('fn').value=fn;$('diff').textContent='running funcdiff...';$('src').textContent='';
 if(mapSel!=fn&&S){mapSel=fn;drawMap()}
 const qs='fn='+fn+(path?'&path='+encodeURIComponent(path):'');
 const [d,s]=await Promise.all([fetch('/api/diff?'+qs).then(r=>r.json()),fetch('/api/source?'+qs).then(r=>r.json())]);
 $('diff').textContent=d.text;$('src').textContent=s.text||'(no source yet)';
 const t=S&&S.tried.find(r=>r.name==fn);
 $('srcsel').innerHTML=t?'attempts: '+t.attempts.map(a=>`<a onclick="diff('${fn}','${a.path}')">${a.who}</a>`).join(' &middot; '):'';
}
$('diffbtn').onclick=()=>diff($('fn').value.trim());
async function poll(){try{S=await (await fetch('/api/status')).json();render();await pollLog();
 if(S.build.running||$('buildout').dataset.want){const b=await (await fetch('/api/build')).json();
 $('buildout').textContent=b.output||'building...';if(!b.running)delete $('buildout').dataset.want}}catch(e){}
 setTimeout(poll,4000)}
async function pollLog(){const n=$('logsel').value;if(!n)return;
 const r=await (await fetch('/api/log?name='+encodeURIComponent(n))).json(),p=$('log');
 p.textContent=r.text;if($('follow').checked)p.scrollTop=p.scrollHeight}
$('logsel').onchange=pollLog;
$('buildbtn').onclick=async()=>{await fetch('/api/build',{method:'POST'});$('buildout').dataset.want=1;$('buildout').textContent='building...'};
addEventListener('resize',()=>S&&drawMap());
poll();
</script></body></html>
"""


def main() -> None:
    parser = argparse.ArgumentParser(description="decomp progress dashboard")
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=8099)
    args = parser.parse_args()
    server = ThreadingHTTPServer((args.host, args.port), Handler)
    print(f"mm9 decomp dashboard on http://{args.host}:{args.port}/")
    server.serve_forever()


if __name__ == "__main__":
    main()
