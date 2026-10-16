#include "types.h"

extern u8 lbl_8038B2F8[];

void fn_800858C0(u8* p) {
    *(u8*)(*(u32*)(lbl_8038B2F8 + 0x184) + 0x2500) = *(s16*)(p + 4);
    if (*(s16*)(p + 4) > 0) {
        *(u16*)(p + 4) = *(s16*)(p + 4) - 1;
        return;
    }
    *(u8*)(p + 0xFF4) = 2;
    *(u8*)(p + 0x100A) = 1;
    *(u8*)(p + 1) = 2;
}
