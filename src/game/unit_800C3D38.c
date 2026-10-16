#include "types.h"

typedef struct Unk800C3D38 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
} Unk800C3D38;

s32 fn_800A3FAC(s32 x, s32 y);
s32 fn_800A3CD4(s32 x, s32 y);

s32 fn_800C3D38(Unk800C3D38* obj) {
    if (obj->unk68 < 0) {
        s32 a = fn_800A3FAC(obj->unk60 - 0x7FF, obj->unk64 + 0x7FF);
        s32 b = fn_800A3FAC(obj->unk60 - 0x7FF, obj->unk64 - 0x7FF);

        if (a > 0 || b > 0) {
            if (a > b) {
                obj->unk60 += a;
            } else {
                obj->unk60 += b;
            }
            return 1;
        }
    } else if (obj->unk68 > 0) {
        s32 a = fn_800A3CD4(obj->unk60 + 0x7FF, obj->unk64 + 0x7FF);
        s32 b = fn_800A3CD4(obj->unk60 + 0x7FF, obj->unk64 - 0x7FF);

        if (a < 0 || b < 0) {
            if (a < b) {
                obj->unk60 += a;
            } else {
                obj->unk60 += b;
            }
            return 1;
        }
    }
    return 0;
}
