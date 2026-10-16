#include "types.h"

typedef struct Unk800D7830Parent {
    /* 0x0000 */ u8 pad0[0x100B];
    /* 0x100B */ u8 unk100B;
} Unk800D7830Parent;

typedef struct Unk800D7830 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x15 - 0x13];
    /* 0x15 */ u8 part;
    /* 0x16 */ u8 shown;
    /* 0x17 */ u8 shown2;
    /* 0x18 */ u8 pad18[0x34 - 0x18];
    /* 0x34 */ Unk800D7830Parent* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x7F - 0x68];
    /* 0x7F */ u8 unk7F;
} Unk800D7830;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x2247];
    /* 0x2247 */ u8 unk2247;
    /* 0x2248 */ u8 unk2248;
    /* 0x2249 */ u8 pad2249[0x2298 - 0x2249];
} Unk803140C0;

extern Unk803140C0 lbl_803140C0;

void fn_800E946C(Unk800D7830* obj, u8 anim);
void fn_800E9750(Unk800D7830* obj, u16 arg1);

static inline void FaceRight(Unk800D7830* obj) {
    obj->flipX = 1;
    if (obj->flipX) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
}

void fn_800D7830(Unk800D7830* obj) {
    Unk803140C0* work = &lbl_803140C0;
    Unk800D7830Parent* parent = obj->parent;
    s32 v;

    switch (obj->step) {
    case 0:
        if (obj->part == 0) {
            if (work->unk2247 & 0x20) {
                fn_800E946C(obj, 0x24);
            } else {
                fn_800E946C(obj, 0xD);
            }
            obj->x = 0xA800;
            obj->y = 0xB000;
            obj->shown2 = (work->unk2247 >> 5) & 1;
        } else if (obj->part == 1) {
            if (parent->unk100B != 0) {
                fn_800E946C(obj, 8);
            } else {
                fn_800E946C(obj, 6);
            }
            FaceRight(obj);
            obj->x = 0x5000;
            obj->y = 0xB000;
            obj->shown = parent->unk100B;
        } else if (obj->part == 2) {
            fn_800E946C(obj, 0);
            FaceRight(obj);
            obj->x = 0x3000;
            obj->y = 0xB000;
        }
        obj->step++;
    case 1:
        if (obj->part == 1 && obj->shown != parent->unk100B) {
            obj->shown = work->unk2248 & 1;
            obj->step++;
        }
        if (obj->part == 0) {
            v = (u32)(-(work->unk2247 & 0x20) | (work->unk2247 & 0x20)) >> 31;
            if (obj->shown2 != v) {
                obj->shown2 = v;
                obj->step = 4;
            }
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 2:
        if (parent->unk100B != 0) {
            fn_800E946C(obj, 9);
        } else {
            fn_800E946C(obj, 7);
        }
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7F == 3) {
            obj->step = 0;
        }
        break;
    case 4:
        if (work->unk2247 & 0x20) {
            fn_800E946C(obj, 0x22);
        } else {
            fn_800E946C(obj, 0x23);
        }
        obj->step++;
    case 5:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7F == 3) {
            obj->step = 0;
        }
        break;
    }
}
