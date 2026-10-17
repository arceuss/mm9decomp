#include "types.h"

typedef struct Unk80060E88 {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ struct Unk80060E88* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_0 : 22;
    /* 0x54 */ u32 unk54_22 : 1;
    /* 0x54 */ u32 unk54_23 : 9;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7D - 0x68];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 pad7E;
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0x88 - 0x80];
    /* 0x88 */ u8 unk88[4];
    /* 0x8C */ u8 pad8C[0xC9 - 0x8C];
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 padCA[0xCC - 0xCA];
    /* 0xCC */ s32 unkCC;
    /* 0xD0 */ u8 padD0[0xD9 - 0xD0];
    /* 0xD9 */ u8 unkD9;
} Unk80060E88;

typedef struct Unk80304B90 {
    /* 0x0000 */ u8 pad0[0x125];
    /* 0x0125 */ u8 unk125;
} Unk80304B90;

extern u8 lbl_80267580[];
extern Unk80304B90 lbl_80304B90;
extern void* lbl_804EE738;

void fn_800E946C(Unk80060E88* obj, u8 id);
void fn_800E9750(Unk80060E88* obj, u16 arg1);
void fn_8009996C(void* p, void* data);
Unk80060E88* fn_800E8C44(void* pool);
void fn_80042DA0(Unk80060E88* e, s32 a);

void fn_80060E88(Unk80060E88* obj) {
    u8* const p = lbl_80267580;
    Unk80060E88* parent = obj->parent;

    obj->unk64 = parent->unk64 + 0x4000;
    if (!(lbl_80304B90.unk125 & 1)) {
        if (obj->unkC9 == 0) {
            obj->unkC9++;
            fn_8009996C(obj->unk88, p + 0xE8);
        }
    } else if (obj->unkC9 != 0) {
        obj->unkC9 = 0;
        fn_8009996C(obj->unk88, NULL);
    }
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0x10);
        obj->unk54_22 = 0;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unkCC == 0) {
            if (parent->unkD9 == 1) {
                obj->step++;
            }
        } else {
            if (parent->unkD9 == 2) {
                obj->step++;
            }
        }
        break;
    case 2:
        fn_800E946C(obj, 0x11);
        fn_8009996C(obj->unk88, p + 0x118);
        obj->unk16 = 0x14;
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7D == 1) {
            fn_8009996C(obj->unk88, p + 0x148);
        }
        if (obj->unk16 == 0) {
            obj->step++;
        } else {
            obj->unk16--;
        }
        break;
    case 4: {
        s32 x = obj->unk60;
        s32 y = obj->unk64 + 0x800;
        Unk80060E88* e = fn_800E8C44(lbl_804EE738);

        if (e != NULL) {
            fn_80042DA0(e, 0x1E);
            e->parent = parent;
            e->unk60 = x;
            e->unk64 = y;
            e->unk14 = 5;
            e->unkCC = 0;
        }
        obj->unk16 = 0x14;
        obj->step++;
    }
    case 5:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk16 == 0) {
            obj->step++;
        } else {
            obj->unk16--;
        }
        break;
    case 6:
        fn_800E946C(obj, 0x12);
        fn_8009996C(obj->unk88, p + 0x118);
        obj->step++;
    case 7:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7F == 3) {
            fn_8009996C(obj->unk88, p + 0xE8);
            obj->step = 0;
        }
        break;
    }
}
