#include "types.h"
#include "game/obj.h"

typedef struct Unk42B9C {
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
} Unk42B9C;
extern u8 lbl_803051D8[];
extern void** lbl_80265138[];
void fn_800E946C(Obj*, s32);
void fn_800E9750(Obj*, u16);

void fn_80042B9C(Unk42B9C* obj) {
    if (lbl_803051D8[2] & 0x20) {
        obj->unk0A &= ~1;
        obj->unk0A &= 0xFD;
        obj->unk18 = lbl_80265138[obj->unk09][3];
        obj->unk10 = 3;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
    } else {
        switch (obj->unk12) {
        case 0:
            fn_800E946C((Obj*)obj, 8);
            obj->unk12++;
        case 1:
            if (obj->unk7F == 4) {
                obj->unk0A &= ~1;
                obj->unk0A &= 0xFD;
                obj->unk18 = lbl_80265138[obj->unk09][3];
                obj->unk10 = 3;
                obj->unk11 = 0;
                obj->unk12 = 0;
                obj->unk13 = 0;
                return;
            }
            break;
        }
        fn_800E9750((Obj*)obj, 0xFFFF);
    }
}
