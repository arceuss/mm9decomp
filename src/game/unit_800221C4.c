#include "types.h"

typedef struct Unk800221C4 {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 pad12[0x14 - 0x12];
    /* 0x14 */ u8 unk14;
} Unk800221C4;

typedef void (*StateObjFunc)(Unk800221C4* obj);

extern StateObjFunc lbl_804EC800[1];
extern StateObjFunc lbl_802637A0[];
extern StateObjFunc lbl_802637B0[];

void fn_800C75D0(Unk800221C4* obj);
u8 fn_80022A08(Unk800221C4* obj);

void fn_800221C4(Unk800221C4* obj) {
    if (obj->unk11 > 1) {
        if (obj->unk14 == 0) {
            fn_800C75D0(obj);
        }
        if (fn_80022A08(obj) != 0) {
            lbl_804EC800[obj->unk11](obj);
            return;
        }
    }
    lbl_802637A0[obj->unk11](obj);
    lbl_802637B0[obj->unk11](obj);
}
