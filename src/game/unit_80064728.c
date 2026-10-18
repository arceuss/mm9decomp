#include "types.h"

typedef struct Unk80064728Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk80064728Pos;

typedef struct Unk80064728Parent {
    /* 0x00 */ u8 pad0[0xF2];
    /* 0xF2 */ u8 unkF2;
    /* 0xF3 */ u8 padF3;
    /* 0xF4 */ u8 unkF4[4];
} Unk80064728Parent;

typedef struct Unk80064728 {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x34 - 0x18];
    /* 0x34 */ Unk80064728Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 pad7D[0xC8 - 0x7D];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk80064728;

extern u32 lbl_804EE988;
extern u8 lbl_804ECBF0[8];
extern void* lbl_804EE738;

void fn_800E946C(Unk80064728* obj, u8 id);
void fn_80072AFC(Unk80064728Pos* pos, s32 a, s32 b);
Unk80064728* fn_800E8C44(void* list);
void fn_80042DA0(Unk80064728* obj, s32 kind);
void fn_800D5234(s32 se);
void fn_800E9750(Unk80064728* obj, u16 arg1);

static inline s32 Busy(Unk80064728* obj, Unk80064728Parent* parent) {
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

void fn_80064728(Unk80064728* obj) {
    Unk80064728Parent* parent = obj->parent;
    Unk80064728Pos pos;
    u32 rnd;
    s32 x;
    s32 y;
    Unk80064728* child;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        rnd = lbl_804EE988 * 0x343FD;
        rnd += 0x269EC3;
        lbl_804EE988 = rnd & 0x7FFFFFFF;
        rnd = ((rnd >> 16) & 0x7FFF) % 3;
        obj->step++;
        obj->timer = lbl_804ECBF0[(u8)rnd];
    case 1:
        if (Busy(obj, parent)) {
            obj->step = 4;
        } else if (obj->timer == 0) {
            obj->step++;
        } else {
            obj->timer--;
        }
        break;
    case 2:
        obj->timer = 0;
        obj->unk17 = 0;
        obj->unk13 = 0;
        obj->step++;
    case 3:
        if (obj->unk7C == 4) {
            if (obj->unk13 == 0) {
                fn_800E946C(obj, 0);
                if (obj->unk17 == 3) {
                    if (Busy(obj, parent)) {
                        obj->step++;
                    } else {
                        obj->step = 0;
                    }
                    break;
                }
            } else {
                obj->unk13--;
            }
        }
        if (obj->timer == 0) {
            fn_800E946C(obj, 4);
            pos.x = obj->x - 0x800;
            pos.y = obj->y - 0x700;
            fn_80072AFC(&pos, 0x200, 0);
            obj->timer = 0x28;
            obj->unk17++;
            obj->unk13 = 5;
        } else {
            obj->timer--;
        }
        break;
    case 4:
        fn_800E946C(obj, 0);
        obj->unk13 = 0x5A;
        obj->timer = 0;
        obj->unk17 = 0;
        obj->step++;
    case 5:
        if (obj->unk13 == 0) {
            if (obj->unk17 == 0) {
                if (obj->unk7C != 0) {
                    fn_800E946C(obj, 0);
                }
            } else {
                obj->unk17--;
            }
            if (parent->unkF2 == obj->unkCC * 0x1E) {
                fn_800E946C(obj, 4);
                obj->timer = 0x5A;
                x = obj->x - 0x800;
                y = obj->y - 0xA00;
                obj->unk17 = 5;
                child = fn_800E8C44(lbl_804EE738);
                if (child != NULL) {
                    fn_80042DA0(child, 0x21);
                    child->parent = parent;
                    child->x = x;
                    child->y = y;
                    child->unk14 = 3;
                    child->unkC8 = 0;
                    child->unkCC = 0;
                }
                fn_800D5234(0x3D);
            }
        } else {
            obj->unk13--;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
