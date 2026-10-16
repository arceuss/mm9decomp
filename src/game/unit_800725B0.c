#include "types.h"

typedef struct Unk80304B68 {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u8 pad4[0x16 - 0x4];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x1C - 0x17];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
} Unk80304B68;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2D8];
    /* 0x2D8 */ u32 unk2D8;
} Unk80304B90;

typedef struct Unk8038E140 {
    /* 0x00 */ u8 pad0[0xA0];
    /* 0xA0 */ u32 unkA0;
} Unk8038E140;

extern Unk80304B68 lbl_80304B68;
extern Unk80304B90 lbl_80304B90;
extern Unk8038E140 lbl_8038E140;
extern u8 lbl_803051D8[0x38];
extern u32 lbl_8036CF50[0xEFE0 / 4];
extern u8 lbl_804ECCB8[8];

void fn_800E5424(s32 arg0);

void fn_800725B0(void) {
    if (lbl_80304B68.unk16 == 0 && (lbl_80304B90.unk2D8 & 1)) {
        lbl_80304B68.unk16 = 1;
        if (lbl_80304B68.unk0 > lbl_8038E140.unkA0) {
            lbl_803051D8[0] |= 0x20;
            fn_800E5424(0x1F);
        }
    }
    if (lbl_80304B68.unk16 != 0) {
        lbl_80304B68.unk1C = 0x5800;
        lbl_80304B68.unk20 = 0x6A00;
    } else {
        lbl_80304B68.unk20 = 0xC00;
        lbl_80304B68.unk1C = lbl_804ECCB8[lbl_8036CF50[0]] << 8;
    }
}
