#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk802819B0Entry;

typedef struct Unk800E03C4Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800E03C4Pos;

typedef struct Unk800E03C4Parent {
    /* 0x0000 */ u8 pad0[0xFF4];
    /* 0x0FF4 */ u8 cue;
    /* 0x0FF5 */ u8 done;
} Unk800E03C4Parent;

typedef struct Unk800E03C4 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 set;
    /* 0x15 */ u8 idx;
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800E03C4Parent* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
} Unk800E03C4;

extern Unk802819B0Entry* lbl_802819B0[];
extern Unk800E03C4Pos lbl_802810E0[][18];

void fn_800E946C(Unk800E03C4* obj, u8 anim);
void fn_800E9750(Unk800E03C4* obj, u16 arg1);
void fn_800E9758(Unk800E03C4* obj);

static inline void Face(Unk800E03C4* obj, u32 flip) {
    obj->flipX = flip;
    if (obj->flipX) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
}

void fn_800E03C4(Unk800E03C4* obj) {
    Unk800E03C4Parent* parent = obj->parent;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0x1C);
        Face(obj, 1);
        obj->x = lbl_802810E0[obj->set][obj->idx].x;
        obj->y = lbl_802810E0[obj->set][obj->idx].y;
        obj->vx = 0x160;
        obj->step++;
    case 1:
        obj->x += obj->vx;
        if (obj->x >= 0xA000) {
            obj->x = 0xA000;
            parent->done = 1;
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 2:
        fn_800E946C(obj, 1);
        Face(obj, 0);
        obj->step++;
    case 3:
        if (parent->cue == 0x11) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 4:
        fn_800E946C(obj, 1);
    case 5:
        if (parent->cue == 0x14) {
            obj->step++;
        }
        fn_800E9758(obj);
        break;
    case 6:
        fn_800E946C(obj, 3);
        Face(obj, 1);
        obj->timer = 0;
        obj->step++;
    case 7:
        if (++obj->timer >= 0x74) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 8:
        fn_800E946C(obj, 2);
        obj->vx = -0x160;
        obj->step++;
    case 9:
        obj->x += obj->vx;
        if (parent->cue == 0x15) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 10:
        fn_800E946C(obj, 2);
        obj->step++;
    case 11:
        if (parent->cue == 0x1D) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 12:
        fn_800E946C(obj, 4);
        Face(obj, 0);
        fn_800E946C(obj, 2);
        obj->vy = -0x400;
        obj->step++;
    case 13:
        obj->y += obj->vy;
        obj->vy += 0x40;
        if (obj->vy >= 0x700) {
            obj->vy = 0x700;
        }
        if (obj->y >= 0xA000) {
            parent->done = 1;
            obj->y = 0xA000;
            obj->vy = -0x100;
            obj->step++;
        }
        break;
    case 14:
        if (parent->cue == 0x1E) {
            break;
        }
        fn_800E946C(obj, 3);
        Face(obj, 0);
        obj->vx = -0x160;
        obj->step++;
    case 15:
        obj->x += obj->vx;
        if (obj->x <= -0x2000) {
            obj->unk18 = lbl_802819B0[obj->kind]->unk8;
            obj->unk10 = 2;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
