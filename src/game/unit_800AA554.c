#include "types.h"

typedef struct Unk800AA554Ent {
    u32 off : 31;
    u32 flag : 1;
} Unk800AA554Ent;

typedef struct Unk800AA554Arc {
    /* 0x0 */ u32 count;
    /* 0x4 */ Unk800AA554Ent ent[1];
} Unk800AA554Arc;

typedef struct Unk800AA554Name {
    /* 0x00 */ u8 pad0[0x50];
} Unk800AA554Name;

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x2028];
    /* 0x2028 */ u32 count;
    /* 0x202C */ Unk800AA554Arc* arcs[0x100];
    /* 0x242C */ u8 pad242C[0x2430 - 0x242C];
    /* 0x2430 */ Unk800AA554Name names[0x100];
} Unk80383E70;

extern Unk80383E70 lbl_80383E70;

s32 fn_8017530C(const char* a, void* b);
void fn_8009C100(void* dst, void* src, u32 size);

u32 fn_800AA554(const char* name, u32 idx, Unk800AA554Arc* src) {
    u32 i;
    u32 cnt;
    Unk800AA554Arc** slot;
    Unk800AA554Name* e;
    u8* data;
    u8* dst;
    u32 n;
    Unk800AA554Ent* p;
    u32 off;
    u32 len;

    if (*name == '.') {
        name++;
    }
    if (*name == '/') {
        name++;
    }
    cnt = lbl_80383E70.count;
    for (i = 0, e = lbl_80383E70.names; i < cnt; i++, e++) {
        if (fn_8017530C(name, e) == 0) {
            break;
        }
    }
    slot = &lbl_80383E70.arcs[i];
    fn_8009C100(*slot, src, (((*slot)->count + 1) * 4) + 4);
    dst = (u8*)*slot;
    data = (u8*)src + src->ent[0].off;
    if (idx == 0xFFFF) {
        n = src->count;
        idx = 0;
    } else {
        n = idx + 1;
        if (src->ent[n].off - src->ent[(u16)idx].off == 0) {
            return 0;
        }
    }
    for (p = &src->ent[idx]; idx < n; idx++, p++) {
        off = p->off;
        len = src->ent[idx + 1].off - off;
        fn_8009C100(dst + off, data, len);
        data += (len + 3) & ~3;
    }
    src->ent[n].off = (u32)data;
    return data - (u8*)src;
}
