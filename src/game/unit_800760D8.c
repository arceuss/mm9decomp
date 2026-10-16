#include "types.h"

typedef struct Unk800760D8 {
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
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 gravity;
    /* 0x78 */ u8 pad78[0x88 - 0x78];
    /* 0x88 */ u8 unk88[0xA0 - 0x88];
    /* 0xA0 */ u32 hitFlags;
    /* 0xA4 */ u8 padA4[0xD0 - 0xA4];
    /* 0xD0 */ u8 unkD0;
} Unk800760D8;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern void** lbl_80270168[];
extern u8 lbl_8026FD68[];

void fn_800E9244(Unk800760D8* obj);
void fn_800E946C(Unk800760D8* obj, s32 anim);
void fn_800E9750(Unk800760D8* obj, u16 arg1);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
u16 fn_800A3458(s32 x, s32 y);
void fn_8009996C(void* arg0, void* arg1);
void fn_80040AD0(s32 arg0, s32* pos, s32 arg2, s32 arg3);
void fn_800D5234(s32 id);

static inline void SetMode(Unk800760D8* obj, u8 mode) {
    obj->unk18 = lbl_80270168[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800760D8(Unk800760D8* obj) {
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 8);
        obj->gravity = 0x40;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0xA00) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
            break;
        }
        obj->x += obj->vx;
        obj->y += obj->vy;
        obj->vy += obj->gravity;
        if (fn_800A3458(obj->x, obj->y) != 0 || (obj->hitFlags & 4)) {
            obj->step++;
        }
        break;
    case 2:
        obj->flagsA &= ~1;
        obj->timer = 0xC;
        fn_8009996C(obj->unk88, lbl_8026FD68);
        fn_80040AD0(3, &obj->x, 0, 0);
        fn_800D5234(0x13);
        obj->unkD0 = 1;
        obj->step++;
    case 3:
        if (--obj->timer == 0) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
        }
        break;
    }
}
