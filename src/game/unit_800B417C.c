#include "types.h"

typedef struct UnkB417C {
    /* 0x000 */ u8 pad000[0x9];
    /* 0x009 */ u8 unk009;
    /* 0x00A */ u8 unk00A;
    /* 0x00B */ u8 pad00B[0x11 - 0xB];
    /* 0x011 */ u8 unk011;
    /* 0x012 */ u8 unk012;
    /* 0x013 */ u8 unk013;
    /* 0x014 */ u8 pad014[0xA0 - 0x14];
    /* 0x0A0 */ u32 unk0A0;
    /* 0x0A4 */ u8 pad0A4[0x0E6 - 0xA4];
    /* 0x0E6 */ s16 unk0E6;
    /* 0x0E8 */ u8 pad0E8[0x0EC - 0xE8];
    /* 0x0EC */ u8 unk0EC;
    /* 0x0ED */ u8 unk0ED;
    /* 0x0EE */ u8 unk0EE;
    /* 0x0EF */ u8 unk0EF;
    /* 0x0F0 */ u8 unk0F0;
    /* 0x0F1 */ u8 unk0F1;
    /* 0x0F2 */ u8 unk0F2;
    /* 0x0F3 */ u8 unk0F3;
    /* 0x0F4 */ u8 unk0F4;
    /* 0x0F5 */ u8 unk0F5;
    /* 0x0F6 */ u8 pad0F6[0xFD - 0xF6];
    /* 0x0FD */ u8 unk0FD;
    /* 0x0FE */ u8 pad0FE[0x104 - 0xFE];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x115 - 0x108];
    /* 0x115 */ u8 unk115;
    /* 0x116 */ u8 pad116;
    /* 0x117 */ u8 unk117;
    /* 0x118 */ u8 unk118;
    /* 0x119 */ u8 pad119[0x1F0 - 0x119];
    /* 0x1F0 */ u16 unk1F0;
} UnkB417C;

extern u8 lbl_803051D8[];

u16 fn_800A502C(u16 id);

static inline s32 Shift(UnkB417C* obj, u8 v) {
    obj->unk0EC = obj->unk011;
    obj->unk011 = v;
    obj->unk0ED = obj->unk012;
    obj->unk012 = 0;
    obj->unk0EE = obj->unk013;
    obj->unk013 = 0;
    obj->unk0F2 = obj->unk0EF;
    obj->unk0EF = 0;
    obj->unk0F3 = obj->unk0F0;
    obj->unk0F0 = 0;
    obj->unk0F4 = obj->unk0F1;
    obj->unk0F1 = 0;
    obj->unk0F5 = v;
    return v;
}

s32 fn_800B417C(UnkB417C* obj) {
    u8 state;
    u32 m;
    u32 next;
    u32 f;
    u8 g;

    state = obj->unk011;
    next = state;

    if (state != 7) {
        f = obj->unk115;
        if (((1 << state) & 0x707F) && (f & 0x3C)) {
            if ((f & 8) && !(f & 0x34) && (obj->unk104 & 0x10) && lbl_803051D8[0xC] != 0) {
                return Shift(obj, 5);
            }
            return Shift(obj, 7);
        }
        m = (1 << state) & 0x405F;
        if (m) {
            if (obj->unk0A0 & 0x400) {
                return Shift(obj, 0xD);
            }
            obj->unk117 = 0;
            obj->unk0FD = 0xFF;
        }
        if (((1 << state) & 0x13) && fn_800A502C(obj->unk1F0) == 0xFFFF) {
            g = obj->unk118;
            if (g & 7) {
                next = 0xE;
            }
            if (next == 0xE && next != state && (g & 8)) {
                f &= ~1;
            }
        }
        if (m && (f & 1)) {
            return Shift(obj, 6);
        }
        if (next == 0xE && next != state) {
            return Shift(obj, 0xE);
        }
    }
    return state;
}
