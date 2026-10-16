#include "types.h"

extern s32 fn_8009E894();

s32 fn_800B95CC(u8* obj, u8* p) {
    s32 x = *(s16*)(p + 2) + (*(s32*)(obj + 4) + *(u16*)(p + 6));
    s32 r = fn_8009E894(*(s32*)(obj + 0), x);
    return (-(s32)((r >> 10) & 1)) & 0x64;
}
