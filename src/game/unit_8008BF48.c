#include "types.h"

typedef struct Unk8043CA80Dst {
    /* 0x000 */ u8 pad0[0x484];
    /* 0x484 */ u16 unk484[8];
    /* 0x494 */ u16 unk494[12];
} Unk8043CA80Dst;

typedef struct Unk8043CA80 {
    /* 0x000 */ u8 pad0[0x258];
    /* 0x258 */ u8* unk258;
} Unk8043CA80;

extern Unk8043CA80 lbl_8043CA80;

s32 fn_8000EECC(s32 arg0);
u32 VIGetTvFormat(void);

typedef struct Unk8008BF48 {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ s16 unk8;
    /* 0x000A */ s16 unkA;
    /* 0x000C */ u8 padC[0x1108 - 0xC];
    /* 0x1108 */ u16 unk1108[12];
} Unk8008BF48;

void fn_8008BF48(Unk8008BF48* menu) {
    s32 limit;
    Unk8043CA80Dst* dst;

    if (menu->unkA >= 12) {
        return;
    }
    limit = VIGetTvFormat() == 1 ? (0x6A - menu->unk8) / 8 : (0x80 - menu->unk8) / 10;
    if (limit >= menu->unkA) {
        dst = (Unk8043CA80Dst*)(lbl_8043CA80.unk258 + fn_8000EECC(0x38));
        dst->unk494[menu->unkA] = menu->unk1108[menu->unkA];
        menu->unkA++;
    }
}
