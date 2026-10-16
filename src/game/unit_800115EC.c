#include "types.h"

typedef struct Unk800115EC {
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
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x88 - 0x70];
    /* 0x88 */ u8 unk88[0xA0 - 0x88];
    /* 0xA0 */ u32 hitFlags;
    /* 0xA4 */ u8 padA4[0xE6 - 0xA4];
    /* 0xE6 */ u8 unkE6;
} Unk800115EC;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x125];
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x21C - 0x126];
    /* 0x21C */ u8 unk21C[0x2D8 - 0x21C];
    /* 0x2D8 */ u32 unk2D8;
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern void** lbl_802638A0[];
extern u8 lbl_80262148[];

void fn_800E9244(Unk800115EC* obj);
void fn_800E946C(Unk800115EC* obj, u8 anim);
void fn_800E9750(Unk800115EC* obj, u16 arg1);
void fn_8009996C(void* arg0, void* arg1);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);

static inline void SetMode(Unk800115EC* obj, u8 mode) {
    obj->unk18 = lbl_802638A0[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

static inline void Die(Unk800115EC* obj) {
    obj->unkE6 = 1;
    obj->unk18 = lbl_802638A0[obj->kind][2];
    obj->unk10 = 2;
    obj->unk13 = 0;
    obj->state = 1;
    obj->step = 0;
}

void fn_800115EC(Unk800115EC* obj) {
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 4);
        fn_8009996C(obj->unk88, lbl_80262148);
        obj->flagsA |= 1;
        obj->step++;
    case 1:
        if (obj->hitFlags & 0x80000) {
            Die(obj);
            break;
        }
        obj->x += obj->vx;
        obj->y += obj->vy;
        if (obj->unk10 >= 2) {
            Die(obj);
            break;
        }
        fn_80080484(lbl_80304B90.unk21C, &obj->x, 1);
        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0x1000) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
            break;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
