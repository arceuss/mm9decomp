#include "game/work_8031BF70.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D2E8C {
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
    /* 0x34 */ struct Unk800D2E8C* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0xAC - 0x70];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800D2E8C;

extern Unk80280390Entry* lbl_80280390[];

typedef struct Unk804EE984 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x60 - 0xB];
    /* 0x60 */ s32 unk60;
} Unk804EE984;

extern Unk804EE984* lbl_804EE984;

void fn_800B63C4(Unk804EE984* p, s32 arg);
BOOL fn_800B590C(Unk804EE984* p, s32 arg);
void fn_800B60CC(Unk804EE984* p, s32 arg);
void fn_800B6464(Unk804EE984* p);
void fn_800B6474(Unk804EE984* p);
void fn_800B60D4(Unk804EE984* p, s32 arg);
void fn_800B60DC(Unk804EE984* p, s32 arg);

void fn_800D2E8C(Unk800D2E8C* obj) {
    switch (obj->step) {
    case 0:
        obj->unk68 = 0;
        obj->unk6C = lbl_804EE984->unk60;
        obj->step++;
    case 1:
        fn_800B63C4(lbl_804EE984, 1);
        if (obj->unk6C != 0 && obj->unk6C == lbl_804EE984->unk60) {
            obj->unk68 = 0;
        }
        if (fn_800B590C(lbl_804EE984, 1)) {
            obj->unk68 += (lbl_804EE984->flagsA & 0x10) ? -0x80 : 0x80;
        }
        obj->unk6C = lbl_804EE984->unk60;
        fn_800B60CC(lbl_804EE984, obj->unk68);
        if (obj->unk14 == 0) {
            fn_800B6464(lbl_804EE984);
            fn_800B60D4(lbl_804EE984, -0x48);
        } else {
            fn_800B6474(lbl_804EE984);
            lbl_8031BF70.unk4AEC4 = ((obj->unk64 >> 12) / 14 * 14) << 12;
            lbl_8031BF70.unk4AECC = lbl_8031BF70.unk4AEC4 + 0xE400;
            fn_800B60D4(lbl_804EE984, -0x48);
        }
        fn_800B60DC(lbl_804EE984, 0x80);
        break;
    }
}
