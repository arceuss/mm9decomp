#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
    /* 0x3008 */ u8 pad3008[0x3028 - 0x3008];
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;

typedef struct Unk8037C3D8 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 idx;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x14 - 0xA];
    /* 0x14 */ s32 top;
    /* 0x18 */ s32 scale;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20[0x2C];
    /* 0x4C */ u8* unk4C;
} Unk8037C3D8;

extern Unk8037C3D8 lbl_8037C3D8;
extern u8 lbl_80301280[];
extern u8 lbl_804ECDF8[8];

typedef struct Unk80301280W {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u16 unk16;
} Unk80301280W;

extern void fn_8000ECB8(s32 a, s32 b, s32 c, s8 d, s8 e);
extern void fn_800A5BE0(void* work, s32 arg1, s32 arg2, u32 arg3);
extern s16 fn_800A5ED4(u8* text);

void fn_800A70F8(void) {
    u32 base;
    s32 t;

    if (lbl_8037C3D8.unk0 != 0 || lbl_8037C3D8.unk5 != 0) {
        base = (u32)lbl_80316D78.unk3004 + 0xC28000;
        fn_8000ECB8(0x24, (*(u32*)(base + 4) >> 1) + base, lbl_804ECDF8[lbl_8037C3D8.idx], 2, 0);
        fn_800A5BE0(lbl_8037C3D8.unk20, (s32)lbl_8037C3D8.unk4C, 0, 0);
        if (lbl_8037C3D8.unk9 == 2) {
            t = 1;
        } else {
            t = fn_800A5ED4(lbl_8037C3D8.unk4C);
        }
        (*(Unk80301280W**)(lbl_80301280 + 0x40))->unk14 = (u16)((((lbl_8037C3D8.unk3 + 1) << 2) & ~7) - 0x80);
        (*(Unk80301280W**)(lbl_80301280 + 0x40))->unk16 = (u16)(-(((lbl_8037C3D8.top - (((t + 1) << 2) & ~7)) + 7) & ~7));
    }
}
