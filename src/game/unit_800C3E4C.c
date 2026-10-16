#include "types.h"

typedef struct Unk800C3E4C {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 unk6C;
} Unk800C3E4C;

s32 fn_800A39F0(s32 x, s32 y);
s32 fn_800A36F8(s32 x, s32 y);

s32 fn_800C3E4C(Unk800C3E4C* obj) {
    if (obj->unk6C < 0) {
        s32 a = fn_800A39F0(obj->unk60 - 0x7FF, obj->unk64 - 0x7FF);
        s32 b = fn_800A39F0(obj->unk60 + 0x7FF, obj->unk64 - 0x7FF);

        if (a > 0 || b > 0) {
            if (a > b) {
                obj->unk64 += a;
            } else {
                obj->unk64 += b;
            }
            return 1;
        }
    } else if (obj->unk6C > 0) {
        s32 a = fn_800A36F8(obj->unk60 - 0x7FF, obj->unk64 + 0x7FF);
        s32 b = fn_800A36F8(obj->unk60 + 0x7FF, obj->unk64 + 0x7FF);

        if (a < 0 || b < 0) {
            if (a < b) {
                obj->unk64 += a;
            } else {
                obj->unk64 += b;
            }
            return 1;
        }
    }
    return 0;
}
