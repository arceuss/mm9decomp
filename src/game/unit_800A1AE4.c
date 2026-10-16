#include "types.h"

typedef struct Unk8031BF70 {
    /* 0x00000 */ u8 pad000[0x4CEDC];
    /* 0x4CEDC */ u32 unk4CEDC;
    /* 0x4CEE0 */ u32 unk4CEE0;
    /* 0x4CEE4 */ u32 unk4CEE4;
    /* 0x4CEE8 */ u32 unk4CEE8;
    /* 0x4CEEC */ u32 unk4CEEC;
} Unk8031BF70;

extern u16 lbl_80253778[];
extern s32 lbl_8036CF50[];
extern u8 lbl_8038B2F8[];
extern Unk8031BF70 lbl_8031BF70;

extern void fn_8009EF24(s32, s32, void*);

void fn_800A1AE4(void) {
    u16 local[6];
    u16* p = lbl_80253778;
    local[0] = *p++;
    local[1] = *p++;
    local[2] = *p++;
    local[3] = *p++;
    local[4] = *p++;
    local[5] = *p++;
    if (lbl_8036CF50[0] != 0) {
        fn_8009EF24(0x11D, 0x20, local);
    }
    lbl_8031BF70.unk4CEDC = 0;
    *(u16*)(lbl_8038B2F8 + 0x26BC) = 0;
}
