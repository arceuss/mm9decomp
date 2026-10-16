#include "types.h"

typedef struct Unk800103A0 {
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
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 vy;
    /* 0x70 */ s32 targetY;
} Unk800103A0;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x125];
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x21C - 0x126];
    /* 0x21C */ u8 unk21C[0x2D8 - 0x21C];
    /* 0x2D8 */ u32 unk2D8;
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern void** lbl_802638A0[];

void fn_800E9244(Unk800103A0* obj);
void fn_800E9750(Unk800103A0* obj, u16 arg1);
void fn_800E9CB8(Unk800103A0* obj);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);

static inline void SetMode(Unk800103A0* obj, u8 mode) {
    obj->unk18 = lbl_802638A0[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800103A0(Unk800103A0* obj) {
    switch (obj->step) {
    case 0:
        obj->vy = -(obj->y - obj->targetY) / 120;
        fn_800E9244(obj);
        obj->timer = 120;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        obj->y += obj->vy;
        if (obj->timer == 0) {
            obj->y = obj->targetY;
            obj->step++;
        } else {
            obj->timer--;
        }
        break;
    case 2:
        fn_800E9CB8(obj);
        if (!(lbl_80304B90.unk2D8 & 1)) {
            lbl_80304B90.unk2D8 |= 2;
        }
        obj->timer = 60;
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) != 0) {
            lbl_80304B90.unk125 |= 2;
            lbl_80304B90.unk2D8 &= 0xFFFD;
            if (obj->timer == 0) {
                obj->flagsA &= ~1;
                obj->flagsA &= 0xFD;
                fn_800E9244(obj);
                SetMode(obj, 3);
            } else {
                obj->timer--;
            }
        }
        break;
    }
}
