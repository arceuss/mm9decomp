#include "types.h"

typedef struct Unk800EABC0 {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[4];
    /* 0x18 */ s32 unk18;
} Unk800EABC0;

extern s32* lbl_8027EB98[];
extern s32* lbl_802638A0[];
extern s32* lbl_80270168[];
extern s32* lbl_80265138[];
extern s32* lbl_80280390[];
extern s32* lbl_804ECDE0[];
extern s32* lbl_8027F228[];
void fn_800E9244(Unk800EABC0* obj);
void fn_80042D30(Unk800EABC0* obj);

void fn_800EABC0(Unk800EABC0* obj) {
    switch (obj->unk8) {
    case 0:
        obj->unkA &= ~1;
        obj->unkA &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_8027EB98[obj->unk9][3];
        obj->unk10 = 3;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        break;
    case 5:
        obj->unkA &= ~1;
        obj->unkA &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_802638A0[obj->unk9][3];
        obj->unk10 = 3;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        break;
    case 6:
        fn_80042D30(obj);
        break;
    case 7:
        obj->unkA &= ~1;
        obj->unkA &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_80270168[obj->unk9][3];
        obj->unk10 = 3;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        break;
    case 8:
        obj->unkA &= ~1;
        obj->unkA &= 0xFD;
        obj->unk18 = lbl_80265138[obj->unk9][3];
        obj->unk10 = 3;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        break;
    case 9:
        obj->unkA &= ~1;
        obj->unkA &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_80280390[obj->unk9][3];
        obj->unk10 = 3;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        break;
    case 10:
        obj->unkA &= ~1;
        obj->unkA &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_804ECDE0[obj->unk9][3];
        obj->unk10 = 3;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        break;
    case 1:
        obj->unkA &= ~1;
        obj->unkA &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_8027F228[obj->unk9][3];
        obj->unk10 = 3;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        break;
    }
}
