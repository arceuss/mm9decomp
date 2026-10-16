#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80012B54 {
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
    /* 0x34 */ struct Unk80012B54* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 flagsA0;
    /* 0xA4 */ u8 padA4[0xAC - 0xA4];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xB6 - 0xB0];
    /* 0xB6 */ s16 unkB6;
    /* 0xB8 */ u8 padB8[0xF2 - 0xB8];
    /* 0xF2 */ u8 unkF2;
} Unk80012B54;

extern Unk80280390Entry* lbl_802638A0[];

extern void (*lbl_804EC700[2])(Unk80012B54* obj);
extern void (*lbl_804EC6F0[2])(Unk80012B54* obj);
extern void (*lbl_804EC6F8[2])(Unk80012B54* obj);

void fn_800C75D0(void);

void fn_80012B54(Unk80012B54* obj) {
    BOOL dying;

    if (obj->state != 0) {
        fn_800C75D0();
        if ((obj->flagsA0 & 0x200) || obj->unkB6 == 0) {
            obj->unk18 = lbl_802638A0[obj->unk9]->unk8;
            obj->unk10 = 2;
            obj->unk13 = 0;
            obj->state = 0;
            obj->step = 0;
            dying = TRUE;
        } else {
            dying = FALSE;
        }
        if (dying) {
            lbl_804EC700[obj->state](obj);
            return;
        }
    }
    if (++obj->unkF2 == 150) {
        obj->unkF2 = 0;
    }
    lbl_804EC6F0[obj->state](obj);
    lbl_804EC6F8[obj->state](obj);
}
