#include "types.h"

typedef struct Unk800BE650Parent {
    /* 0x000 */ u8 pad0[0x128];
    /* 0x128 */ u32 unk128;
    /* 0x12C */ u8 pad12C[0x1F8 - 0x12C];
    /* 0x1F8 */ u8 unk1F8;
} Unk800BE650Parent;

typedef struct Unk800BE650 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x24 - 0x1C];
    /* 0x24 */ u16 sprite;
    /* 0x26 */ u8 pad26[0x34 - 0x26];
    /* 0x34 */ Unk800BE650Parent* parent;
    /* 0x38 */ u8 pad38[0x88 - 0x38];
    /* 0x88 */ u8 unk88[0xC8 - 0x88];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 padC9[0xCB - 0xC9];
    /* 0xCB */ u8 timer;
} Unk800BE650;

extern u8 lbl_804ECF20[4][2];
extern void* lbl_804ECF10[2];
extern void** lbl_8027F228[];

void fn_800E9424(Unk800BE650* obj, u16 id);
void fn_800E946C(Unk800BE650* obj, u8 anim);
void fn_8009996C(void* arg0, void* arg1);
void fn_800E9244(Unk800BE650* obj);
void fn_800E9750(Unk800BE650* obj, u16 arg1);

static inline void SetMode(Unk800BE650* obj, u8 mode) {
    obj->unk18 = lbl_8027F228[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

static inline void SetHP(Unk800BE650Parent* p, u8 amount) {
    s32 hp = p->unk1F8;

    hp -= amount;
    if (hp < 0) {
        hp = 0;
    }
    p->unk1F8 = hp;
}

void fn_800BE650(Unk800BE650* obj) {
    u32 v;
    Unk800BE650Parent* parent;

    parent = obj->parent;

    switch (obj->step) {
    case 0:
        v = obj->unk14;
        if (obj->sprite != 0x103) {
            fn_800E9424(obj, 0x103);
        }
        obj->unk16 = 1;
        fn_800E946C(obj, lbl_804ECF20[v][1]);
        fn_8009996C(obj->unk88, lbl_804ECF10[obj->unk14]);
        obj->timer = 0xF0;
        obj->step++;
    case 1:
        parent->unk128 |= 4;
        if (--obj->timer == 0) {
            SetMode(obj, 2);
            SetMode(obj, 4);
            fn_800E9244(obj);
            obj->flagsA &= ~1;
            SetHP(obj->parent, obj->unkC8);
            return;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
