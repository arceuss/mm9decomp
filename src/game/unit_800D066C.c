#include "types.h"

typedef struct Unk800D066C {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x60 - 0x15];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0xCC - 0x64];
    /* 0xCC */ s32 unkCC;
    /* 0xD0 */ s32 unkD0;
} Unk800D066C;

extern u8 lbl_8031BF70[];

void fn_800D066C(Unk800D066C* obj) {
    u32 g = *(u32*)(lbl_8031BF70 + 0x4CED8);
    s32 d = obj->unkD0;
    s32 v = g % (d * 2);

    switch (obj->unk14 & 0xF) {
    case 0:
        if (v > d) {
            v = 2 * d - v;
        }
        obj->unk60 = obj->unkCC - ((v - (d >> 1)) << 8);
        return;
    case 1:
        if (v > d) {
            v = 2 * d - v;
        }
        obj->unk60 = obj->unkCC + ((v - (d >> 1)) << 8);
        return;
    case 2:
        if (v > d) {
            v -= d;
            if (v - (d >> 1) > 0) {
                v = d - v;
            }
            obj->unk60 = obj->unkCC - (v << 8);
        } else {
            if (v - (d >> 1) > 0) {
                v = d - v;
            }
            obj->unk60 = obj->unkCC + (v << 8);
        }
        return;
    case 3:
        if (v > d) {
            v -= d;
            if (v - (d >> 1) > 0) {
                v = d - v;
            }
            obj->unk60 = obj->unkCC + (v << 8);
        } else {
            if (v - (d >> 1) > 0) {
                v = d - v;
            }
            obj->unk60 = obj->unkCC - (v << 8);
        }
        return;
    }
}
