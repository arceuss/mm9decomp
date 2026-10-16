#include "types.h"

typedef struct Unk803BB320 {
    /* 0x00 */ u32 base;
    /* 0x04 */ u32 cur;
    /* 0x08 */ u32 size;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10[4];
    /* 0x20 */ u32 unk20[4];
    /* 0x30 */ u32 unk30[4];
    /* 0x40 */ u32 unk40;
    /* 0x44 */ u32 unk44;
    /* 0x48 */ u32 unk48[4];
} Unk803BB320;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u32 unk3004;
} Unk80316D78;

extern Unk803BB320 lbl_803BB320;
extern Unk80316D78 lbl_80316D78;

void fn_800E7E24(s32 arg0, s32 arg1, s32 arg2);
void fn_800E7EA4(void);
void fn_800BA570(void);

void fn_800E7D3C(void) {
    s32 i;

    lbl_803BB320.base = lbl_80316D78.unk3004 + 0xA00000;
    lbl_803BB320.cur = lbl_803BB320.base;
    lbl_803BB320.size = 0x10000;
    lbl_803BB320.unk40 = 0;
    lbl_803BB320.unk44 = 0;
    for (i = 0; i < 4; i++) {
        lbl_803BB320.unk10[i] = 0;
        lbl_803BB320.unk48[i] = 0;
        lbl_803BB320.unk20[i] = 0;
        lbl_803BB320.unk30[i] = 0;
    }
    fn_800E7E24(0, 0x10, 0);
    fn_800E7E24(1, 0x100, 0);
    fn_800E7E24(2, 0x40, 4);
    fn_800E7E24(3, 0x20, 4);
    fn_800E7EA4();
    lbl_803BB320.unkC = 0x20;
    fn_800BA570();
}
