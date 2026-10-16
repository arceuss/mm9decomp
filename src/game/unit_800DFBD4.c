#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk802819B0Entry;

typedef struct Unk800DFBD4Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800DFBD4Pos;

typedef struct Unk800DFBD4Parent {
    /* 0x0000 */ u8 pad0[0xFF4];
    /* 0x0FF4 */ u8 cue;
    /* 0x0FF5 */ u8 done;
} Unk800DFBD4Parent;

typedef struct Unk800DFBD4 {
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
    /* 0x17 */ u8 count;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x2A - 0x1C];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ void* parent;
    /* 0x38 */ u8 pad38[0x50 - 0x38];
    /* 0x50 */ u32 unk50;
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ Unk800DFBD4Pos pos;
    /* 0x68 */ s32 vx;
} Unk800DFBD4;

extern Unk802819B0Entry* lbl_802819B0[];
extern Unk800DFBD4Pos lbl_802810E0[][18];
extern void* lbl_804EE948;

void fn_800E946C(Unk800DFBD4* obj, u8 anim);
void fn_800E9750(Unk800DFBD4* obj, u16 arg1);
void fn_800D5234(s32 se);
BOOL fn_800D5520(s32 se);
Unk800DFBD4* fn_800E8C44(void* pool);

static inline void Smoke(Unk800DFBD4* obj, s32 x, s32 y) {
    Unk800DFBD4Pos p;
    Unk800DFBD4* child;

    p.x = x;
    p.y = y;
    child = fn_800E8C44(lbl_804EE948);

    if (child != NULL) {
        child->unk2E = 0x10;
        child->kind = 0xA;
        child->unk18 = lbl_802819B0[0xA]->unk0;
        child->unk2A = 0;
        child->unk2C = 0;
        child->unk2F = 0;
        child->set = 0x10;
        child->idx = 0x11;
        child->pos = p;
        child->parent = obj;
    }
}

static inline void Puff(Unk800DFBD4* obj) {
    if (++obj->count & 0x10) {
        obj->count = 0;
        Smoke(obj, obj->pos.x - 0x800, obj->pos.y - 0x1000);
        Smoke(obj, obj->pos.x + 0x800, obj->pos.y - 0x1800);
    }
}

static inline void Rev(Unk800DFBD4* obj) {
    if (!fn_800D5520(0x18)) {
        fn_800D5234(0x18);
        obj->count++;
    }
}

void fn_800DFBD4(Unk800DFBD4* obj) {
    Unk800DFBD4Parent* parent = obj->parent;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->flipX = 1;
        obj->unk50 |= 3;
        if (obj->flipX) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->pos.x = lbl_802810E0[obj->set][obj->idx].x;
        obj->pos.y = lbl_802810E0[obj->set][obj->idx].y;
        obj->vx = -0x160;
        obj->step++;
    case 1:
        obj->pos.x += obj->vx;
        if (parent->cue == 0x15) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 2:
        obj->step++;
    case 3:
        if (parent->cue == 0x1A) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 4:
        fn_800E946C(obj, 1);
        obj->step++;
    case 5:
        if (parent->cue == 0x1B) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 6:
        fn_800E946C(obj, 2);
        obj->timer = 0;
        obj->pos.x += 0x800;
        obj->count = 0;
        fn_800D5234(0x18);
        obj->step++;
    case 7:
        if (obj->count == 0) {
            Rev(obj);
        } else if (obj->count == 1) {
            Rev(obj);
        } else if (obj->count == 2) {
            Rev(obj);
        }
        if (++obj->timer >= 0x78) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 8:
        fn_800E946C(obj, 4);
        obj->timer = 0;
        obj->count = 0;
        obj->step++;
    case 9:
        if (++obj->timer >= 0x3C) {
            obj->step++;
        }
        Puff(obj);
        fn_800E9750(obj, 0xFFFF);
        break;
    case 10:
        fn_800E946C(obj, 3);
        obj->step++;
    case 11:
        if (parent->cue == 0x24) {
            obj->unk18 = lbl_802819B0[obj->kind]->unk8;
            obj->unk10 = 2;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
        }
        Puff(obj);
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
