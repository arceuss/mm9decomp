#include "types.h"

typedef struct Unk80062B4C {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 unkC9;
} Unk80062B4C;

u16 fn_8009E894(s32 x, s32 y);
s32 fn_800A36F8(s32 x, s32 y);
s32 fn_800A39F0(s32 x, s32 y);

BOOL fn_80062B4C(Unk80062B4C* obj) {
    s32 x;
    s32 y;
    s32 d;

    if (obj->unkC9 == 0) {
        x = obj->x + 0x700;
        y = obj->y - 0x500;
    } else {
        x = obj->x - 0x700;
        y = obj->y - 0x500;
    }
    if ((u32)(fn_8009E894(x, y) & 0xF) != 1 && (u32)(fn_8009E894(x, y + 0xA00) & 0xF) != 1) {
        obj->x += obj->unkC9 == 0 ? 0x200 : -0x200;
        if (obj->unkC8 == 2) {
            d = fn_800A36F8(obj->x + (obj->unkC9 == 0 ? 0x500 : -0x500), obj->y + 0xA00);
            if (d < 0) {
                obj->y = d + obj->y + 0x500;
            }
            obj->unkC8 = obj->unkC9 != 0;
            obj->unkC9 = 3;
        } else {
            d = fn_800A39F0(obj->x + (obj->unkC9 == 0 ? 0x500 : -0x500), obj->y - 0xA00);
            if (d > 0) {
                obj->y = d + obj->y - 0x500;
            }
            obj->unkC8 = obj->unkC9 != 0;
            obj->unkC9 = 2;
        }
        return TRUE;
    }
    return FALSE;
}
