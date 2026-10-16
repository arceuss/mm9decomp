#include "types.h"

typedef struct Unk80065B38 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x54 - 0x13];
    /* 0x54 */ struct {
        u32 hi : 21;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0xA0 - 0x70];
    /* 0xA0 */ u32 hitFlags;
    /* 0xA4 */ u8 padA4[0xC8 - 0xA4];
    /* 0xC8 */ u8 kind;
} Unk80065B38;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern u8 lbl_804ECC00[8];
extern Unk80304B90 lbl_80304B90;

void fn_800E946C(Unk80065B38* obj, u8 anim);
void fn_800E9750(Unk80065B38* obj, u16 arg1);
void fn_800D5234(s32 id);
void fn_800E9244(Unk80065B38* obj);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
void fn_80042D30(Unk80065B38* obj);

void fn_80065B38(Unk80065B38* obj) {
    u32 f;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, lbl_804ECC00[obj->kind]);
        f = obj->vx > 0;
        if (f) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->bits54.flip = f;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        obj->x += obj->vx;
        obj->y += obj->vy;
        if (obj->hitFlags & 0x1000) {
            fn_800D5234(0x3E);
            obj->vy = -0x390;
            obj->vx = (((obj->vx >> 31) << 1) + 1) * -0x4C0;
            f = ((obj->flagsA >> 4) & 1) ^ 1;
            if (f) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->bits54.flip = f;
            fn_800E9244(obj);
        }
        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) >= 0x1000) {
            fn_80042D30(obj);
        }
        break;
    }
}
