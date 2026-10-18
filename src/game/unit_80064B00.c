#include "types.h"

typedef struct Unk80064B00Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk80064B00Pos;

typedef struct Unk80064B00Parent {
    /* 0x00 */ u8 pad0[0xF2];
    /* 0xF2 */ u8 unkF2;
    /* 0xF3 */ u8 padF3;
    /* 0xF4 */ u8 unkF4[4];
} Unk80064B00Parent;

typedef struct Unk80064B00 {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x34 - 0x18];
    /* 0x34 */ Unk80064B00Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 pad7D[0x7F - 0x7D];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0xC8 - 0x80];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk80064B00;

extern u32 lbl_804EE988;
extern void* lbl_804EE738;

void fn_800E946C(Unk80064B00* obj, u8 id);
Unk80064B00* fn_800E8C44(void* list);
void fn_80042DA0(Unk80064B00* obj, s32 kind);
void fn_800D5234(s32 se);
void fn_800E9750(Unk80064B00* obj, u16 arg1);

static inline s32 Busy(Unk80064B00* obj, Unk80064B00Parent* parent) {
    s32 r = 0;

    switch (obj->unkCC) {
    case 0:
        if (parent->unkF4[0] != 0) {
            r = 1;
        }
        break;
    case 1:
        if (parent->unkF4[1] != 0) {
            r = 1;
        }
        break;
    case 2:
        if (parent->unkF4[2] != 0) {
            r = 1;
        }
        break;
    case 3:
        if (parent->unkF4[3] != 0) {
            r = 1;
        }
        break;
    }
    return r;
}

static inline void Spawn(Unk80064B00Parent* parent, s32 x, s32 y, u8 kind) {
    Unk80064B00* child = fn_800E8C44(lbl_804EE738);

    if (child != NULL) {
        fn_80042DA0(child, 0x21);
        child->parent = parent;
        child->x = x;
        child->y = y;
        child->unk14 = kind;
        child->unkC8 = 0;
        child->unkCC = 0;
    }
}

void fn_80064B00(Unk80064B00* obj) {
    Unk80064B00Parent* parent = obj->parent;
    u32 rnd;
    u32 v;
    s32 x;
    s32 y;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 5);
        rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
        lbl_804EE988 = rnd & 0x7FFFFFFF;
        v = (rnd >> 16) & 0x7FFF;
        obj->step++;
        v %= 60;
        obj->timer = v + 60;
    case 1:
        if (Busy(obj, parent)) {
            obj->step = 6;
        }
        if (obj->timer == 0) {
            obj->step++;
        } else {
            obj->timer--;
        }
        break;
    case 2:
        fn_800E946C(obj, 7);
        obj->timer = 0x3C;
        obj->step++;
    case 3:
        if (obj->timer == 0) {
            obj->step++;
        } else {
            obj->timer--;
        }
        break;
    case 4:
        fn_800E946C(obj, 8);
        Spawn(parent, obj->x - 0x800, obj->y - 0xA00, 2);
        fn_800D5234(0x3D);
        obj->step++;
    case 5:
        if (obj->unk7F == 3) {
            if (Busy(obj, parent)) {
                obj->step++;
            } else {
                obj->step = 0;
            }
        }
        break;
    case 6:
        fn_800E946C(obj, 5);
        obj->unk13 = 0x5A;
        obj->timer = 0;
        obj->unk17 = 0;
        obj->step++;
    case 7:
        if (obj->unk13 == 0) {
            if (obj->unk17 == 0) {
                if (obj->unk7C != 5) {
                    fn_800E946C(obj, 5);
                }
            } else {
                obj->unk17--;
            }
            if (parent->unkF2 == obj->unkCC * 0x1E) {
                fn_800E946C(obj, 0xB);
                obj->timer = 0x5A;
                obj->unk17 = 5;
                Spawn(parent, obj->x - 0x800, obj->y - 0xA00, 3);
                fn_800D5234(0x3D);
            } else {
                obj->timer--;
            }
        } else {
            obj->unk13--;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
