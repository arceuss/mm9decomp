#include "types.h"

typedef struct Unk800755A8 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x54 - 0x1C];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 unk54_b10 : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x88 - 0x70];
    /* 0x88 */ u8 unk88[1];
    /* 0x89 */ u8 pad89[0xA0 - 0x89];
    /* 0xA0 */ u32 unkA0;
} Unk800755A8;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern void** lbl_80270168[];
extern u8 lbl_8026FCE8[];

u32 fn_80080484(void* cam, s32* pos, s32 arg2);
void fn_800E9244(Unk800755A8* obj);
void fn_800E946C(Unk800755A8* obj, u8 arg1);
void fn_800E9750(Unk800755A8* obj, u16 arg1);
void fn_8009996C(void* handle, void* table);

static inline void SetMode(Unk800755A8* obj, u8 mode) {
    obj->unk18 = lbl_80270168[obj->kind][mode];
    obj->unk10 = mode;
    obj->unk11 = 0;
    obj->unk12 = 0;
    obj->unk13 = 0;
}

void fn_800755A8(Unk800755A8* obj) {
    u8 flip;

    if (fn_80080484(lbl_80304B90.unk21C, &obj->unk60, 1) > 0x800) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    switch (obj->unk12) {
    case 0:
        fn_800E946C(obj, 0);
        obj->unk12 = obj->unk12 + 1;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unkA0 & 0x100) {
            if (obj->unk17 == 0) {
                obj->unk68 = obj->unk68 * -3 / 2;
                obj->unk6C = obj->unk6C * -3 / 2;
            } else {
                obj->unk68 = -obj->unk68;
                obj->unk6C = -obj->unk6C;
            }
            fn_8009996C(obj->unk88, lbl_8026FCE8);
            flip = !(obj->flagsA & 0x10);
            if (flip) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->unk54_b10 = flip;
            obj->unk17 = obj->unk17 + 1;
        }
        obj->unk60 += obj->unk68;
        obj->unk64 += obj->unk6C;
        break;
    case 2:
        obj->unk16 = 0x78;
        obj->unk12 = obj->unk12 + 1;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unkA0 & 0x100) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
            return;
        }
        if (obj->unk16 < 0x10) {
            if (obj->unk16 & 2) {
                obj->flagsA &= ~1;
            } else {
                obj->flagsA |= 1;
            }
        }
        if (--obj->unk16 == 0) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
            return;
        }
        break;
    }
}
