#include "types.h"
#include "game/work_8031BF70.h"

extern s32 lbl_8036CF50[];
extern u16 lbl_80253708[0x10];
extern u8 lbl_8038B2F8[0x26C0];

void fn_8009EF24(s32 x, s32 y, u16* data);

void fn_8009FFD0(void) {
    u16 v[6];
    u16* p = lbl_80253708;
    v[0] = *p++;
    v[1] = *p++;
    v[2] = *p++;
    v[3] = *p++;
    v[4] = *p++;
    v[5] = *p++;
    if (*lbl_8036CF50 != 0) {
        fn_8009EF24(0x10d, 0x2b, v);
    }
    lbl_8031BF70.unk4CEDC = 0;
    *(u16*)(lbl_8038B2F8 + 0x26BC) = 0;
}
