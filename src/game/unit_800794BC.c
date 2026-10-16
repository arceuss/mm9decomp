#include "types.h"

typedef struct Unk800794BC {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 gravity;
} Unk800794BC;

typedef struct Unk804EE984 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 x;
} Unk804EE984;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern Unk804EE984* lbl_804EE984;
extern void** lbl_80270168[];

void fn_800E9244(Unk800794BC* obj);
void fn_800E946C(Unk800794BC* obj, s32 anim);
void fn_800E9750(Unk800794BC* obj, u16 arg1);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);

static inline void SetMode(Unk800794BC* obj, u8 mode) {
    obj->unk18 = lbl_80270168[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800794BC(Unk800794BC* obj) {
    s32 d;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 8);
        obj->vy = -0x400;
        obj->gravity = 0x60;
        if (obj->x < lbl_804EE984->x) {
            d = lbl_804EE984->x - 0x400 - obj->x;
        } else {
            d = lbl_804EE984->x + 0x400 - obj->x;
        }
        obj->vx = -((d << 8) / (((obj->vy << 8) / obj->gravity) * 2));
        if (__abs(obj->vx) > 0x400) {
            if (obj->vx < 0) {
                obj->vx = -0x400;
            } else {
                obj->vx = 0x400;
            }
        }
        obj->step++;
    case 1:
        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0x800) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
            break;
        }
        obj->x += obj->vx;
        obj->y += obj->vy;
        obj->vy += obj->gravity;
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
