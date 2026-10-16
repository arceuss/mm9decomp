#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk8007D4FC {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x54 - 0x1C];
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
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 gravity;
} Unk8007D4FC;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_800E9244(Unk8007D4FC* obj);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
extern void** lbl_80270168[];
extern void (*lbl_804ECCF0[2])(Unk8007D4FC* obj);
void fn_80040AD0(s32 arg0, Vec2i* pos, s32 arg2, s32 arg3);
void fn_800E9758(Unk8007D4FC* obj);

void fn_8007D4FC(Unk8007D4FC* obj) {
    u8 f;

    switch (obj->step) {
    case 0:
        obj->flagsA |= 1;
        fn_800E9244(obj);
        obj->gravity = -0x20;
        obj->vy = 0;
        obj->timer = 0x10;
        obj->step++;
    case 1:
        obj->y += obj->vy;
        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) != 0) {
            obj->unk18 = lbl_80270168[obj->kind][2];
            obj->unk10 = 2;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
            lbl_804ECCF0[obj->state](obj);
            break;
        }
        obj->vy += obj->gravity;
        if (obj->vy < -0x700) {
            obj->vy = -0x700;
        }
        if (--obj->timer == 0) {
            f = !((obj->flagsA >> 4) & 1);
            if (f) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->bits54.flip = f;
            obj->timer = 0x10;
        }
        fn_800E9758(obj);
        break;
    }
}
