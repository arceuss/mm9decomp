#include "types.h"

typedef struct UnkB2640Global {
    /* 0x00 */ u8 pad00[0x0A];
    /* 0x0A */ s16 unk0A;
} UnkB2640Global;

extern UnkB2640Global* lbl_804EE8C0;
extern u32 lbl_8027E6E8[];

typedef struct UnkB2640 {
    /* 0x000 */ u8 pad000[0xF5];
    /* 0x0F5 */ u8 unkF5;
    /* 0x0F6 */ u8 pad0F6[0x154 - 0xF6];
    /* 0x154 */ u16 unk154;
    /* 0x156 */ u8 pad156[0x1F8 - 0x156];
    /* 0x1F8 */ u8 unk1F8;
} UnkB2640;

s32 fn_800BE0F0(UnkB2640*, u32, s32, s32, s32);
s32 fn_800B2640(UnkB2640* obj) {
    s32 r;
    u16 v;
    r = -1;
    if (obj->unk1F8 != 1 && lbl_804EE8C0->unk0A >= 1) {
        v = obj->unk154;
        if (v >= 0x400) {
            if (fn_800BE0F0(obj, lbl_8027E6E8[obj->unkF5], 0, 1, 3) != 0) {
                obj->unk154 = v - 0x400;
                r = 6;
            }
        }
    }
    return r;
}
