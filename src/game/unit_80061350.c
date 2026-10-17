#include "types.h"

typedef struct Unk80061350 {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x34 - 0x18];
    /* 0x34 */ struct Unk80061350* parent;
    /* 0x38 */ u8 pad38[0x50 - 0x38];
    /* 0x50 */ u32 unk50_hi : 30;
    /* 0x50 */ u32 unk50_lo : 2;
    /* 0x54 */ u32 unk54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7F - 0x68];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0x88 - 0x80];
    /* 0x88 */ u8 unk88[1];
    /* 0x89 */ u8 pad89[0xC9 - 0x89];
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 padCA[0xCC - 0xCA];
    /* 0xCC */ u32 unkCC;
    /* 0xD0 */ u8 padD0[0xDA - 0xD0];
    /* 0xDA */ u8 unkDA;
} Unk80061350;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x125];
    /* 0x125 */ u8 unk125;
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern Unk80061350* lbl_804EE738;
extern u8 lbl_80267710[];
extern u8 lbl_80267758[];

void fn_800E946C(Unk80061350* obj, u8 arg1);
void fn_800E9750(Unk80061350* obj, u16 arg1);
void fn_8009996C(void* handle, void* table);
void fn_800D5234(u32 id);
void fn_80042DA0(Unk80061350* obj, s32 arg1);
Unk80061350* fn_800E8C44(Unk80061350* pool);

void fn_80061350(Unk80061350* obj) {
    Unk80061350* parent = obj->parent;

    if (!(lbl_80304B90.unk125 & 1)) {
        if (obj->unkC9 == 0) {
            obj->unkC9 = obj->unkC9 + 1;
            fn_8009996C(obj->unk88, lbl_80267710);
        }
    } else if (obj->unkC9 != 0) {
        obj->unkC9 = 0;
        fn_8009996C(obj->unk88, NULL);
    }
    obj->unk64 = parent->unk64 + 0x2800;
    switch (obj->unk12) {
    case 0:
        fn_800E946C(obj, 0x16);
        obj->unk54 &= ~0x200;
        obj->unk50_lo = 2;
        obj->unk12 = obj->unk12 + 1;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (parent->unkDA == 1) {
            obj->unk12 = obj->unk12 + 1;
        }
        break;
    case 2:
        fn_800E946C(obj, 0x17);
        obj->unk16 = 0x14;
        obj->unk12 = obj->unk12 + 1;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7F == 3) {
            fn_8009996C(obj->unk88, lbl_80267758);
        }
        if (obj->unk16 == 0) {
            obj->unk12 = obj->unk12 + 1;
        } else {
            obj->unk16 = obj->unk16 - 1;
        }
        break;
    case 4:
        obj->unk16 = 0;
        obj->unk17 = 0;
        obj->unk12 = obj->unk12 + 1;
    case 5:
        if (obj->unk16 == 0) {
            s32 x;
            s32 y;
            Unk80061350* p;

            fn_800E946C(obj, 0x18);
            x = obj->unk60 - 0x1A00;
            y = obj->unk64;
            p = fn_800E8C44(lbl_804EE738);
            if (p != NULL) {
                fn_80042DA0(p, 0x1E);
                p->parent = parent;
                p->unk60 = x;
                p->unk64 = y;
                p->unk14 = 8;
                p->unkCC = 0;
            }
            fn_800D5234(0x4A);
            obj->unk16 = 0x14;
            obj->unk17 = obj->unk17 + 1;
            if (obj->unk17 == 4) {
                obj->unk12 = obj->unk12 + 1;
            }
        } else {
            obj->unk16 = obj->unk16 - 1;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 6:
        obj->unk16 = 0x1E;
        obj->unk12 = obj->unk12 + 1;
    case 7:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk16 == 0) {
            obj->unk12 = obj->unk12 + 1;
        } else {
            obj->unk16 = obj->unk16 - 1;
        }
        break;
    case 8:
        fn_800E946C(obj, 0x19);
        fn_8009996C(obj->unk88, lbl_80267710);
        obj->unk12 = obj->unk12 + 1;
    case 9:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7F == 3) {
            parent->unkDA = 2;
            obj->unk12 = 0;
        }
        break;
    }
}
