#include "types.h"

typedef struct Unk8039B180 {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 pad6[0x8 - 0x6];
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} Unk8039B180;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 pad1[0x38 - 0x1];
} Unk803051D8;

typedef struct Unk8038E140 {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ u32 unk24[1];
} Unk8038E140;

extern Unk8039B180 lbl_8039B180;
extern Unk803051D8 lbl_803051D8;
extern Unk8038E140 lbl_8038E140;
extern s32 lbl_80281E08[];

void fn_800E5424(u16 id);

void fn_800E67A8(void) {
    s32 id;

    if (lbl_8039B180.unk4 == 0 && (lbl_803051D8.unk0 & 0x10)) {
        lbl_8039B180.unk4 = 1;
        id = lbl_80281E08[lbl_8039B180.unk5];
        if (id != 0x27 && lbl_8039B180.unk0 < lbl_8038E140.unk24[id]) {
            lbl_803051D8.unk0 |= 0x20;
            fn_800E5424(id);
        }
    }
    if (lbl_8039B180.unk4 != 0) {
        lbl_8039B180.unk8 = 0x5800;
        lbl_8039B180.unkC = 0x6A00;
    } else {
        lbl_8039B180.unk8 = 0xA000;
        lbl_8039B180.unkC = 0xC00;
    }
}
