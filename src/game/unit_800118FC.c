#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800118FC {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2A - 0x22];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ struct Unk800118FC* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_0 : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_22 : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0xAC - 0x78];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800118FC;

extern Unk80280390Entry* lbl_802638A0[];

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[0x300 - 0x21C];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern void (*lbl_804EC6B8[2])(Unk800118FC* obj);

void fn_800E9244(Unk800118FC* obj);
s32 fn_80080484(void* arg0, s32* pos, s32 arg2);
void fn_800E9758(Unk800118FC* obj);

void fn_800118FC(Unk800118FC* obj) {
    switch (obj->step) {
    case 0:
        fn_800E9244(obj);
        obj->unk16 = 0x10;
        obj->unk74 = -0x20;
        obj->unk6C = 0;
        obj->step++;
    case 1:
        obj->unk64 += obj->unk6C;
        if (fn_80080484(lbl_80304B90.unk21C, &obj->unk60, 1)) {
            obj->unk18 = lbl_802638A0[obj->unk9]->unk8;
            obj->unk10 = 2;
            obj->unk13 = 0;
            obj->state = 1;
            obj->step = 0;
            lbl_804EC6B8[obj->state](obj);
            return;
        }
        obj->unk6C += obj->unk74;
        if (obj->unk6C < -0x700) {
            obj->unk6C = -0x700;
        }
        if (--obj->unk16 == 0) {
            obj->flipX = !((obj->flagsA >> 4) & 1);
            if (obj->flipX) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->unk16 = 0x10;
        }
        fn_800E9758(obj);
        break;
    }
}
