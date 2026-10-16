#include "types.h"

typedef struct Unk800D75F4Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800D75F4Pos;

typedef struct Unk800D75F4Parent {
    /* 0x0000 */ u8 pad0[0x1008];
    /* 0x1008 */ u8 level;
    /* 0x1009 */ u8 pad1009;
    /* 0x100A */ u8 unk100A;
} Unk800D75F4Parent;

typedef struct Unk800D75F4 {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 shown;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ Unk800D75F4Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 anim;
} Unk800D75F4;

typedef struct Unk8036CF50 {
    /* 0x0 */ s32 stage;
    /* 0x4 */ u8 pad4[0xEFE0 - 0x4];
} Unk8036CF50;

extern Unk8036CF50 lbl_8036CF50;
extern Unk800D75F4Pos lbl_80280970[];

void fn_800E946C(Unk800D75F4* obj, u8 anim);
void fn_800E9750(Unk800D75F4* obj, u16 arg1);
void fn_800E9758(Unk800D75F4* obj);

static inline void StageAnim(Unk800D75F4* obj) {
    switch (lbl_8036CF50.stage) {
    case 0:
        fn_800E946C(obj, 0xA);
        break;
    case 1:
        fn_800E946C(obj, 0xA);
        break;
    case 2:
        fn_800E946C(obj, 0x13);
        break;
    case 3:
        fn_800E946C(obj, 0xF);
        break;
    case 4:
        fn_800E946C(obj, 0x15);
        break;
    case 5:
        fn_800E946C(obj, 0x11);
        break;
    }
}

void fn_800D75F4(Unk800D75F4* obj) {
    Unk800D75F4Parent* parent = obj->parent;

    switch (obj->step) {
    case 0:
        if (parent->level >= 10) {
            StageAnim(obj);
        } else {
            fn_800E946C(obj, 5);
        }
        obj->shown = parent->level;
        obj->step++;
    case 1:
        if (parent->level != obj->shown) {
            if (parent->level >= 10 && obj->shown < 10) {
                StageAnim(obj);
            } else if (parent->level < 10 && obj->shown >= 10) {
                fn_800E946C(obj, 5);
            }
            obj->shown = parent->level;
        }
        obj->x = lbl_80280970[parent->level].x;
        obj->y = lbl_80280970[parent->level].y;
        if (parent->unk100A == 0) {
            fn_800E9750(obj, 0xFFFF);
        } else {
            fn_800E946C(obj, obj->anim);
            fn_800E9758(obj);
        }
        break;
    }
}
