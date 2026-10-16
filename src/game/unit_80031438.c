#include "types.h"

extern void memcpy(void* dst, void* src, u32 size);
u32 fn_80179B84(u8* s);
u8* fn_80179C8C(u8* s, u8* p);
void fn_80179C00(u8* d, u8* s);

void fn_80031438(u8* obj, void* src, void* rep, void* after) {
    u8* dstcur;
    u8* p;
    u32 len;
    u8* found;
    u32 r;

    dstcur = (u8*)*(u32*)(obj + 0x26C);
    p = src;
    len = fn_80179B84(after) * 2;
    do {
        found = fn_80179C8C(p, rep);
        if (found != 0) {
            r = (u32)found - (u32)p;
            if (r != 0) {
                memcpy(dstcur, p, r);
                dstcur += r & ~1;
            }
            memcpy(dstcur, after, len);
            p = found;
            dstcur += len;
            p += fn_80179B84(src) * 2;
        }
    } while (found != 0);
    *(u16*)dstcur = 0;
    if (fn_80179B84(p) != 0) {
        fn_80179C00(dstcur, p);
    }
}
