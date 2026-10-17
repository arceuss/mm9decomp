#include "types.h"

typedef struct Unk80270168Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} Unk80270168Entry;

typedef struct Unk8007CE30 {
    /* 0x00 */ u8 pad00[0x9];
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ u8 unk60[0x40 - 0x0];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xAB - 0xA4];
    /* 0xAB */ u8 unkABhi : 4;
    /* 0xAB */ u8 unkAB : 4;
    /* 0xAC */ u8 padAC[0xD0 - 0xAC];
    /* 0xD0 */ u8 unkD0;
} Unk8007CE30;

extern Unk80270168Entry* lbl_80270168[18];
extern u8 lbl_803051D8[0x38];
extern u8 lbl_80304B90[];
extern void (*lbl_804ECCE8[2])(Unk8007CE30* obj);

void fn_800E9244(Unk8007CE30* obj);
u32 fn_80080484(void* a, void* b, s32 c);

BOOL fn_8007CE30(Unk8007CE30* obj) {
    BOOL hit = FALSE;

    if (lbl_803051D8[2] & 0x20) {
        obj->unk0A &= 0xFE;
        obj->unk0A &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_80270168[obj->unk09]->unkC;
        obj->unk10 = 3;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        return TRUE;
    }
    if (obj->unk11 != 1 && obj->unkAB == 3) {
        obj->unk11 = 1;
        obj->unk12 = 0;
    } else if (obj->unk11 != 2 && obj->unkAB == 5) {
        obj->unk11 = 2;
        obj->unk12 = 0;
    } else if ((obj->unkA0 & 0x100) && !(obj->unkA0 & 0x1000)) {
        obj->unk18 = lbl_80270168[obj->unk09]->unk8;
        obj->unk10 = 2;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        hit = TRUE;
    } else if (obj->unkA0 & 0x80000) {
        obj->unk18 = lbl_80270168[obj->unk09]->unk8;
        obj->unk10 = 2;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        hit = TRUE;
    } else if (fn_80080484(lbl_80304B90 + 0x21C, obj->unk60, 1) >= 0x800) {
        obj->unk18 = lbl_80270168[obj->unk09]->unk8;
        obj->unk10 = 2;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        hit = TRUE;
    } else if (obj->unkD0 != 0) {
        obj->unk18 = lbl_80270168[obj->unk09]->unk8;
        obj->unk10 = 2;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        hit = TRUE;
    }
    if (hit) {
        lbl_804ECCE8[obj->unk11](obj);
    }
    return hit;
}
