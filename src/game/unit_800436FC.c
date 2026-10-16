#include "types.h"
#include "game/obj.h"

typedef struct Unk436FC {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x7F - 0x15];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[8];
    /* 0x88 */ u8 unk88[4];
} Unk436FC;
extern u8 lbl_804ECA5C[4];
extern u8 lbl_802651C0[];
void fn_800E946C(Obj*, s32);
void fn_8009996C(void*, void*);
void fn_800E9750(Obj*, u16);

void fn_800436FC(Unk436FC* obj) {
    switch (obj->unk12) {
    case 0:
        fn_800E946C((Obj*)obj, lbl_804ECA5C[obj->unk14]);
        fn_8009996C(obj->unk88, lbl_802651C0);
        obj->unk12++;
    case 1:
        fn_800E9750((Obj*)obj, 0xFFFF);
        if (obj->unk7F == 3) {
            obj->unk11 = 0;
            obj->unk12 = 0;
        }
        break;
    }
}
