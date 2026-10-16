#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80012988 {
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
    /* 0x34 */ struct Unk80012988* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xAB - 0xA4];
    /* 0xAB */ u8 unkAB;
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xB6 - 0xB0];
    /* 0xB6 */ s16 unkB6;
    /* 0xB8 */ u8 padB8[0xC8 - 0xB8];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xDA - 0xCD];
    /* 0xDA */ u8 unkDA;
    /* 0xDB */ u8 padDB[0xE8 - 0xDB];
    /* 0xE8 */ u8 unkE8;
    /* 0xE9 */ u8 unkE9;
    /* 0xEA */ u8 unkEA;
    /* 0xEB */ u8 unkEB;
    /* 0xEC */ u8 unkEC;
    /* 0xED */ u8 unkED;
    /* 0xEE */ u8 unkEE;
    /* 0xEF */ u8 unkEF;
    /* 0xF0 */ u8 unkF0;
    /* 0xF1 */ u8 unkF1;
    /* 0xF2 */ u8 unkF2;
    /* 0xF3 */ u8 unkF3;
    /* 0xF4 */ u8 unkF4;
    /* 0xF5 */ u8 unkF5;
    /* 0xF6 */ u8 unkF6;
    /* 0xF7 */ u8 unkF7;
} Unk80012988;

extern Unk80280390Entry* lbl_802638A0[];

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern void (*lbl_804EC740[1])(Unk80012988* obj);
extern void (*lbl_802624C8[4])(Unk80012988* obj);
extern void (*lbl_802624D8[4])(Unk80012988* obj);

void fn_800C75D0(void);

static inline BOOL Hit(Unk80012988* obj) {
    if ((obj->unkA0 & 0x200) || obj->unkB6 == 0) {
        obj->unk18 = lbl_802638A0[obj->unk9]->unk8;
        obj->unk10 = 2;
        obj->unk13 = 0;
        obj->state = 0;
        obj->step = 0;
        return TRUE;
    }
    return FALSE;
}

extern const u8 lbl_804EE670[8];
extern u8 lbl_804EC6E8[8];
extern void (*lbl_804EC700[2])(Unk80012988* obj);
extern void (*lbl_804EC6F0[2])(Unk80012988* obj);
extern void (*lbl_804EC6F8[2])(Unk80012988* obj);

void fn_800E91F0(Unk80012988* obj, void* arg1, s32 arg2);
void fn_80012974(void*);
void fn_8000F134(void* arg0);
void fn_800C7594(s32 arg0);

void fn_80012988(Unk80012988* obj) {
    obj->unk18 = lbl_802638A0[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = lbl_804EE670[obj->unk14];
    fn_800E91F0(obj, NULL, 0);
    obj->unkAC = fn_80012974;
    obj->flagsA &= ~1;
    fn_8000F134(lbl_804EC6E8);
    obj->unkE8 = 0;
    obj->unkE9 = 0;
    obj->unkEA = 0;
    obj->unkEB = 0;
    obj->unkEC = 0;
    obj->unkED = 0;
    obj->unkEE = 0;
    obj->unkEF = 0;
    obj->unkF0 = 0xFF;
    obj->unkF1 = 0;
    obj->unkF4 = 0;
    obj->unkF5 = 0;
    obj->unkF6 = 0;
    obj->unkF7 = 0;
    obj->unkF2 = 0;
    fn_800C7594(3);
    if (obj->state != 0) {
        fn_800C75D0();
        if (Hit(obj)) {
            lbl_804EC700[obj->state](obj);
            return;
        }
    }
    if (++obj->unkF2 == 0x96) {
        obj->unkF2 = 0;
    }
    lbl_804EC6F0[obj->state](obj);
    lbl_804EC6F8[obj->state](obj);
}
