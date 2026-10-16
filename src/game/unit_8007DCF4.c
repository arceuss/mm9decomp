#include "types.h"

typedef struct Unk8007DCF4Obj {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0xA0 - 0xB];
    /* 0xA0 */ u32 unkA0;
} Unk8007DCF4Obj;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ Unk8007DCF4Obj* unk8;
    /* 0x00C */ u8 padC[0x124 - 0xC];
    /* 0x124 */ u8 unk124[0x148 - 0x124];
    /* 0x148 */ void* unk148;
    /* 0x14C */ u8 pad14C[0x2B0 - 0x14C];
    /* 0x2B0 */ s32 unk2B0;
    /* 0x2B4 */ u8 pad2B4[0x2D8 - 0x2B4];
    /* 0x2D8 */ u32 unk2D8;
    /* 0x2DC */ u8 pad2DC[0x300 - 0x2DC];
} Unk80304B90;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 pad1[0x38 - 0x1];
} Unk803051D8;

extern Unk80304B90 lbl_80304B90;
extern Unk803051D8 lbl_803051D8;
extern u8 lbl_80272A08[];
extern u8 lbl_80272A78[];
extern u8 lbl_80272988[];
extern u8 lbl_802729C0[];

void fn_8008123C(void* machine, void* state);

static inline void CheckHit(void) {
    Unk8007DCF4Obj* player = lbl_80304B90.unk8;

    if ((player->flagsA & 4) && (player->unkA0 & 0x200)) {
        lbl_80304B90.unk2D8 |= 1;
    }
}

BOOL fn_8007DCF4(void) {
    void* state;

    CheckHit();
    if (lbl_80304B90.unk2D8 & 1) {
        state = lbl_80304B90.unk148;
        if (state == lbl_80272A08 || state == lbl_80272A78 || state == lbl_80272988 || state == lbl_802729C0) {
            return TRUE;
        }
        if (lbl_803051D8.unk0 & 4) {
            fn_8008123C(lbl_80304B90.unk124, lbl_80272A08);
        } else if (lbl_803051D8.unk0 & 8) {
            fn_8008123C(lbl_80304B90.unk124, lbl_80272A78);
        } else if (lbl_80304B90.unk2B0 != 0) {
            fn_8008123C(lbl_80304B90.unk124, lbl_802729C0);
        } else {
            fn_8008123C(lbl_80304B90.unk124, lbl_80272988);
        }
        return TRUE;
    }
    return FALSE;
}
