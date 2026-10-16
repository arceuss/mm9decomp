#include "types.h"

typedef struct Unk8009CFF8 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB;
    /* 0x0C */ u8 flagsC;
    /* 0x0D */ u8 padD[0x10 - 0xD];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0xAC - 0x1C];
    /* 0xAC */ void (*unkAC)(void*);
} Unk8009CFF8;

extern s32* lbl_804ECDE0[3];
extern u8 lbl_804ECDD8[8];

void fn_800E9424(Unk8009CFF8* obj, s32 arg1);
void fn_800E946C(Unk8009CFF8* obj, u8 arg1);
void fn_800E91F0(Unk8009CFF8* obj, s32 arg1, s32 arg2);
void fn_8009D468(void*);
void fn_8009D0B8(Unk8009CFF8* obj);

void fn_8009CFF8(Unk8009CFF8* obj) {
    obj->unk18 = lbl_804ECDE0[obj->unk9][1];
    obj->unk10 = 1;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
    obj->flagsA |= 1;
    fn_800E9424(obj, 0x51);
    fn_800E946C(obj, lbl_804ECDD8[obj->unk14]);
    obj->flagsA |= 2;
    fn_800E91F0(obj, 0, 0);
    obj->unkAC = fn_8009D468;
    obj->flagsC |= 0x10;
    fn_8009D0B8(obj);
}
