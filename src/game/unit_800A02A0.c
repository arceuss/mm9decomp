#include "types.h"

extern u16 lbl_80253718[];
extern s32 lbl_8036CF50[];
extern u8 lbl_8038B2F8[];

extern void fn_8009EF24(s32, s32, void*);

void fn_800A02A0(void) {
    u16 local[6];
    u16* p = lbl_80253718;
    local[0] = *p++;
    local[1] = *p++;
    local[2] = *p++;
    local[3] = *p++;
    local[4] = *p++;
    local[5] = *p++;
    if (lbl_8036CF50[0] != 0) {
        fn_8009EF24(0xDD, 0x73, local);
    }
    *(u16*)(lbl_8038B2F8 + 0x26BC) = 0;
}
