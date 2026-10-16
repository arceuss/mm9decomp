#include "types.h"

typedef struct Unk99918 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u8 pad04[0x08 - 0x04];
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u8 pad0C[0x18 - 0x0C];
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 pad21[0x24 - 0x21];
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u32 unk28;
    /* 0x2C */ u8 pad2C[0x2E - 0x2C];
    /* 0x2E */ u16 unk2E;
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u8 pad32[0x36 - 0x32];
    /* 0x36 */ u8 unk36;
    /* 0x37 */ u8 pad37[0x3B - 0x37];
    /* 0x3B */ u8 unk3B;
} Unk99918;

extern u8 lbl_80274528[];

void fn_80099918(Unk99918* p, u32 a2, u32 a3, u16 a4) {
    p->unk20 = 0;
    p->unk18 = 0;
    p->unk1C = 0;
    p->unk08 = a3;
    p->unk30 = a4;
    p->unk2E = a4;
    p->unk24 = 0;
    p->unk28 = 0;
    *(u32*)((u8*)p + 0x20) = 0;
    if (a2 == 0) {
        p->unk00 = (u32)lbl_80274528;
    } else {
        p->unk00 = a2;
    }
    p->unk3B = 0;
    p->unk36 = 0;
}
