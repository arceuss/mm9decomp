#include "types.h"

typedef struct Unk800CBE84 {
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
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 gravity;
} Unk800CBE84;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern void** lbl_80280390[];
extern void* lbl_804EE984;

void fn_800E946C(Unk800CBE84* obj, u8 anim);
void fn_800E9750(Unk800CBE84* obj, u16 arg1);
BOOL fn_800B6010(void* player, Unk800CBE84* obj);
void fn_800D5234(s32 id);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
void fn_800E9244(Unk800CBE84* obj);

static inline void SetMode(Unk800CBE84* obj, u8 mode) {
    obj->unk18 = lbl_80280390[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800CBE84(Unk800CBE84* obj) {
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (fn_800B6010(lbl_804EE984, obj)) {
            obj->step++;
        }
        break;
    case 2:
        obj->y += 0x300;
        obj->timer = 8;
        obj->step++;
    case 3:
        if (obj->timer == 0) {
            obj->y -= 0x300;
            obj->step++;
        } else {
            obj->timer--;
        }
        break;
    case 4:
        obj->vy = 0x180;
        obj->gravity = 0x20;
        fn_800D5234(0x39);
        obj->step++;
    case 5:
        fn_800E9750(obj, 0xFFFF);
        obj->y += obj->vy;
        obj->vy += obj->gravity;
        if (obj->vy > 0x5C0) {
            obj->vy = 0x5C0;
        }
        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) >= 0x800) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
        }
        break;
    }
}
