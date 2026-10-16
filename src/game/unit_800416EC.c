#include "types.h"
#include "game/obj.h"

typedef struct Unk416EC {
    /* 0x00 */ u8 pad00[9];
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[4];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x7F - 0x1C];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[8];
    /* 0x88 */ u8 unk88;
} Unk416EC;
extern u8 lbl_803051D8[];
extern void** lbl_80265138[];
void fn_800E946C(Obj*, s32);
void fn_800E9750(Obj*, u16);

s32 fn_80041840(Obj*);

void fn_800416EC(Unk416EC* obj) {
    if (lbl_803051D8[2] & 0x20) {
        obj->unk0A &= ~1;
        obj->unk0A &= 0xFD;
        obj->unk18 = lbl_80265138[obj->unk09][3];
        obj->unk10 = 3;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
    } else {
        s32 result;
        if (obj->unk88 != 0) {
            fn_800E946C((Obj*)obj, 3);
            obj->unk88 = 0;
        }
        result = fn_80041840((Obj*)obj);
        fn_800E9750((Obj*)obj, 0xFFFF);
        if (obj->unk7F == 3 || result != 0) {
            obj->unk18 = lbl_80265138[obj->unk09][2];
            obj->unk10 = 2;
            obj->unk11 = 0;
            obj->unk12 = 0;
            obj->unk13 = 0;
        }
    }
}
