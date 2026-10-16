#include "types.h"

void* memcpy(void* dst, const void* src, size_t n);
size_t fn_80179B84(const u16* str);
u16* fn_80179C8C(const u16* str, const u16* find);
u16* fn_80179C00(u16* dst, const u16* src);

void fn_80025C58(u16* dst, u16* src, u16* find, u16* repl) {
    u16* hit;
    size_t len;
    size_t n;
    u16* p;
    u16* out;
    u16* start;

    out = dst;
    p = src;
    start = src;
    len = fn_80179B84(repl);

    while ((hit = fn_80179C8C(p, find)) != NULL) {
        if ((n = (u32)hit - (u32)start) != 0) {
            memcpy(out, start, n);
            out += n / sizeof(u16);
        }
        memcpy(out, repl, len * sizeof(u16));
        out += len;
        p = hit + fn_80179B84(find);
        start = p;
    }
    *out = 0;
    if (fn_80179B84(start) != 0) {
        fn_80179C00(dst, start);
    }
}
