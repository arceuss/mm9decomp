#include "types.h"

typedef struct Unk8037C3D8 {
    /* 0x00 */ u8 pad0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[0x10 - 0x2];
    /* 0x10 */ u8 unk10[0x20 - 0x10];
    /* 0x20 */ u8 unk20[0x50 - 0x20];
} Unk8037C3D8;

typedef struct Unk8043CA80 {
    /* 0x000 */ u8 pad0[0x258];
    /* 0x258 */ u8* unk258;
    /* 0x25C */ u8 pad25C[0x268 - 0x25C];
} Unk8043CA80;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ u32* unk40;
    /* 0x44 */ u8 pad44[0x48 - 0x44];
} Unk80301280;

extern Unk8037C3D8 lbl_8037C3D8;
extern Unk8043CA80 lbl_8043CA80;
extern Unk80301280 lbl_80301280;
extern u16 lbl_804ECDF0[4];

s32 fn_8000EECC(s32 arg0);
void fn_8009C110(void* dst, void* src, s32 size);
void fn_800A5B2C(void* p);

s32 fn_800A76C8(void) {
    u32 row = lbl_804ECDF0[lbl_8037C3D8.unk1] - 0x10;

    fn_8009C110(lbl_8037C3D8.unk10, lbl_8043CA80.unk258 + fn_8000EECC(0x24) + 0x1E + (row >> 3) * 0x40, 4);
    fn_800A5B2C(lbl_8037C3D8.unk20);
    *lbl_80301280.unk40 &= ~0x200;
    return 1;
}
