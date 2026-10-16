#include "types.h"

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

typedef struct Unk8027F3C8Entry {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk8027F3C8Entry;

typedef struct Unk800C3B24Owner {
    /* 0x000 */ u8 pad0[0x10C];
    /* 0x10C */ u8 unk10C;
} Unk800C3B24Owner;

typedef struct Unk800C3B24 {
    /* 0x00 */ u8 pad0[9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800C3B24Owner* unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ u8 unk60[0xC8 - 0x60];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 padC9[0xCA - 0xC9];
    /* 0xCA */ u8 unkCA;
    /* 0xCB */ u8 padCB;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 unkCD;
} Unk800C3B24;

extern Unk8027F3C8Entry* lbl_8027F3C8[];
extern Unk803051D8 lbl_803051D8;
extern u8 lbl_80304B90[];

u32 fn_80080484(u8* a, u8* b, int c);
void fn_800C3354(Unk800C3B24* obj);
void fn_800E9244(Unk800C3B24* obj);

s32 fn_800C3B24(Unk800C3B24* obj) {
    if (obj->unkCA != obj->unk34->unk10C) {
        obj->unkA &= 0xFE;
        obj->unkA &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_8027F3C8[obj->unk9]->unkC;
        obj->unk10 = 3;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        return 1;
    }
    if (lbl_803051D8.unk2 & 0x20) {
        obj->unk18 = lbl_8027F3C8[obj->unk9]->unk8;
        obj->unk10 = 2;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        fn_800C3354(obj);
        return 1;
    }
    if (obj->unkC8 != 0 && obj->unkCC == 0) {
        obj->unk18 = lbl_8027F3C8[obj->unk9]->unk8;
        obj->unk10 = 2;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        fn_800C3354(obj);
        return 1;
    }
    if (obj->unkCD != 0) {
        obj->unk18 = lbl_8027F3C8[obj->unk9]->unk8;
        obj->unk10 = 2;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        fn_800C3354(obj);
        return 1;
    }
    if (fn_80080484(lbl_80304B90 + 0x21C, obj->unk60, 1) > 0x800) {
        obj->unk18 = lbl_8027F3C8[obj->unk9]->unk8;
        obj->unk10 = 2;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        fn_800C3354(obj);
        return 1;
    }
    return 0;
}
