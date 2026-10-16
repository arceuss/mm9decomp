#include "types.h"

extern u8 lbl_803051D8[0x38];
extern u16 lbl_802639A0[];
extern u8 lbl_8036CF50[];
extern u8 lbl_804EC82C[0xC];
extern u8 lbl_80263970[0x10];

void fn_80024C78(u8* obj) {
    u32 w;
    u32 hp;
    u16 div;
    u8 d;

    w = *(u32*)(obj + 0x38);
    hp = *(u32*)(obj + 0x34);
    if ((*(u8*)(lbl_803051D8 + 3) & 4) != 0) {
        obj[0x0A] |= 1;
        return;
    }
    obj[0x0A] &= 0x7F;
    d = lbl_802639A0[obj[0x15] * 2 >> 1];
}
