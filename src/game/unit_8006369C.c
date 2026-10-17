#include "types.h"

typedef struct Unk8006369C {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0xC - 0xB];
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 padD[0x10 - 0xD];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ struct Unk8006369C* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_0 : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_22 : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0x68 - 0x64];
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x88 - 0x6C];
    /* 0x88 */ u8 unk88[4];
    /* 0x8C */ u8 pad8C[0xC8 - 0x8C];
    /* 0xC8 */ s32 unkC8;
} Unk8006369C;

typedef struct Unk8006369CBase {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 pad11[0x34 - 0x11];
    /* 0x34 */ Unk8006369C* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
} Unk8006369CBase;

typedef struct Unk80304B90 {
    /* 0x0000 */ u8 pad0[0x21C];
    /* 0x021C */ u8 cam[4];
} Unk80304B90;

extern Unk8006369CBase* lbl_804EE984;
extern u8 lbl_80267A28[];
extern Unk80304B90 lbl_80304B90;

void fn_80042D30(Unk8006369C* obj);
void fn_800E946C(Unk8006369C* obj, u8 id);
void fn_800E9750(Unk8006369C* obj, u16 arg1);
void fn_8009996C(void* p, void* data);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);

void fn_8006369C(Unk8006369C* obj) {
    Unk8006369C* parent = obj->parent;
    Unk8006369C* grandparent = parent->parent;
    s32 dir;

    if (grandparent->unk10 >= 2) {
        fn_80042D30(obj);
        return;
    }
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 3);
        fn_8009996C(obj->unk88, lbl_80267A28);
        obj->unk16 = 0x14;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unkC8 == 0) {
            dir = lbl_804EE984->unk60 - obj->unk60 > 0;
            if (dir) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->flipX = dir;
            if (obj->unk16 == 0) {
                obj->step++;
            } else {
                obj->unk16--;
            }
        }
        break;
    case 2:
        dir = lbl_804EE984->unk60 - obj->unk60 > 0;
        if (dir) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->flipX = dir;
        obj->unk68 = (((obj->flagsA >> 3) & 2) - 1) << 10;
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        obj->unk60 += obj->unk68;
        if (fn_80080484(lbl_80304B90.cam, &obj->unk60, 1) > 0x1000) {
            fn_80042D30(obj);
        }
        break;
    }
}
