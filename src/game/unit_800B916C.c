#include "types.h"

typedef struct UnkB916C {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
} UnkB916C;

extern s32 fn_800B91E0();

s32 fn_800B916C(u8* obj, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 flags) {
    UnkB916C buf;
    s32 r;
    buf = *(UnkB916C*)obj;
    r = fn_800B91E0(&buf, a2, a3, a4, a5, a6, (flags & 0xFFF7FFFF) | 0x80000);
    if (((flags >> 19) & 1) && r) {
        *(UnkB916C*)obj = buf;
    }
    return r;
}
