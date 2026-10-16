#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8006CCA4 {
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
    /* 0x34 */ struct Unk8006CCA4* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAB - 0x68];
    /* 0xAB */ u8 unkAB_hi : 4;
    /* 0xAB */ u8 unkAB_lo : 4;
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk8006CCA4;

extern Unk80280390Entry* lbl_80265138[];

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern void (*lbl_802684B8[])(Unk8006CCA4* obj);

void fn_80042D30(Unk8006CCA4* obj);
void fn_80040AD0(s32 arg0, s32* pos, s32 arg2, s32 arg3);
void fn_800E9244(Unk8006CCA4* obj);
void fn_80042CF8(Unk8006CCA4* obj, s32 arg1);

static inline BOOL CheckHit(Unk8006CCA4* obj) {
    if (obj->unk14 == 0 && obj->state != 1 && obj->unkAB_lo == 3) {
        obj->state = 1;
        obj->step = 0;
        return FALSE;
    }
    return FALSE;
}

void fn_8006CCA4(Unk8006CCA4* obj) {
    s32 pos[2];

    if (lbl_803051D8.unk2 & 0x20) {
        fn_80042D30(obj);
    } else if (CheckHit(obj)) {
        pos[0] = obj->unk60;
        pos[1] = obj->unk64;
        fn_80040AD0(2, pos, 0, 0);
        fn_800E9244(obj);
        obj->flagsA &= ~1;
        fn_80042CF8(obj, 4);
    } else {
        lbl_802684B8[obj->state](obj);
    }
}
