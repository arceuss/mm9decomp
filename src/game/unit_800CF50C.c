#include "types.h"

typedef struct Unk800CF50C {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x12 - 0xC];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 phase;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x30 - 0x17];
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u8 pad32[0x3C - 0x32];
    /* 0x3C */ void* unk3C;
    /* 0x40 */ u8 pad40[0x78 - 0x40];
    /* 0x78 */ u8 anim[0x7F - 0x78];
    /* 0x7F */ u8 animState;
} Unk800CF50C;

typedef struct Unk8031BF70 {
    /* 0x00000 */ u8 pad0[0x4CED8];
    /* 0x4CED8 */ u32 frame;
} Unk8031BF70;

extern Unk8031BF70 lbl_8031BF70;
extern u8 lbl_804ED068[8];
extern u8 lbl_804ED060[8];

void fn_800E946C(Unk800CF50C* obj, u8 anim);
void fn_800D5234(s32 id);
void fn_800C9F8C(void* anim);
void fn_800E9750(Unk800CF50C* obj, u16 arg1);

void fn_800CF50C(Unk800CF50C* obj) {
    s32 n;
    u32 t;

    switch (obj->step) {
    case 0:
        obj->flagsA &= ~1;
        obj->flagsB &= 0xEF;
        obj->timer = 0x80;
        obj->step++;
    case 1:
        obj->timer--;
        if ((u8)lbl_8031BF70.frame == obj->phase << 6) {
            obj->timer = 0x80;
            obj->step = 4;
        } else if (obj->timer == 0) {
            obj->step = 2;
        }
        break;
    case 2:
        obj->flagsA &= ~1;
        obj->flagsB &= 0xEF;
        obj->step++;
    case 3:
        t = 0x80 - (u8)((u8)lbl_8031BF70.frame - (obj->phase << 6) + 0x100);
        if (t < 0x80) {
            obj->timer = t;
            obj->step = 4;
        }
        break;
    case 4:
        fn_800E946C(obj, lbl_804ED068[obj->unk15 & 0xF]);
        n = 0x80 - obj->timer;
        if (--n < 8) {
            fn_800D5234(0x34);
        }
        while (obj->animState != 3 && n > 0) {
            fn_800C9F8C(obj->anim);
            n--;
        }
        obj->flagsA |= 1;
        obj->flagsB |= 0x10;
        obj->unk3C = lbl_804ED060;
        obj->unk30 = 1;
        obj->step++;
    case 5:
        if (--obj->timer == 0) {
            obj->step = 2;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
