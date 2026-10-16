#include "types.h"
#include "game/obj.h"

typedef struct Unk800629C0 {
    /* 0x00 */ u8 pad00[0x60];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 unkC9;
} Unk800629C0;

u32 fn_8009E894(s32, s32);
s32 fn_800A3FAC(s32, s32);
s32 fn_800A3CD4(s32, s32);

BOOL fn_800629C0(Unk800629C0* obj) {
    s32 x;
    s32 y;
    s32 d;
    s32 r;
    u8 t;

    if (obj->unkC9 == 3) {
        x = obj->unk60 - 0x500;
        y = obj->unk64 + 0x700;
    } else {
        x = obj->unk60 - 0x500;
        y = obj->unk64 - 0x700;
    }
    if ((fn_8009E894(x, y) & 0xF) != 1 && (fn_8009E894(x + 0xa00, y) & 0xF) != 1) {
        obj->unk64 += (obj->unkC9 == 3) ? 0x200 : -0x200;
        if (obj->unkC8 == 0) {
            if (obj->unkC9 == 3) {
                d = 0x500;
            } else {
                d = -0x500;
            }
            r = fn_800A3FAC(obj->unk60 - 0xa00, obj->unk64 + d);
            if (r > 0) {
                obj->unk60 += r - 0x500;
            }
            t = obj->unkC9;
            obj->unkC9 = 1;
            obj->unkC8 = 2 + (t == 3);
        } else {
            if (obj->unkC9 == 3) {
                d = 0x500;
            } else {
                d = -0x500;
            }
            r = fn_800A3CD4(obj->unk60 + 0xa00, obj->unk64 + d);
            if (r < 0) {
                obj->unk60 += r + 0x500;
            }
            t = obj->unkC9;
            obj->unkC9 = 0;
            obj->unkC8 = 2 + (t == 3);
        }
        return TRUE;
    }
    return FALSE;
}
