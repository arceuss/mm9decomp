#include "types.h"

extern u8 lbl_8038B2F8[];

void fn_8008587C(u8* p) {
    *(u8*)(*(u32*)(lbl_8038B2F8 + 0x184) + 0x2500) = *(s16*)(p + 4);
    if (*(s16*)(p + 4) < 0x20) {
        *(u16*)(p + 4) = *(s16*)(p + 4) + 1;
        return;
    }
    *(u8*)(*(u32*)(lbl_8038B2F8 + 0x184) + 0x2500) = 0x20;
    *(u8*)(p + 0xFF4) = 3;
}
