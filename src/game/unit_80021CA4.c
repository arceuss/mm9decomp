#include "types.h"

typedef struct Unk802638A0Entry {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk802638A0Entry;

typedef struct Unk80021CA4Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk80021CA4Pos;

typedef struct Unk80021CA4Child {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
} Unk80021CA4Child;

typedef struct Unk80021CA4 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x38 - 0x1C];
    /* 0x38 */ Unk80021CA4Child* unk38;
    /* 0x3C */ u8 pad3C[0x54 - 0x3C];
    /* 0x54 */ u32 unk54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 unk74;
} Unk80021CA4;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x125];
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x21C - 0x126];
    /* 0x21C */ u8 unk21C[0x2D8 - 0x21C];
    /* 0x2D8 */ u32 unk2D8;
} Unk80304B90;

extern Unk802638A0Entry* lbl_802638A0[];
extern Unk80304B90 lbl_80304B90;
extern void* lbl_804EE984;

void fn_800C7770(void* player);
void fn_800C675C(s32 arg0);
void fn_800E9244(Unk80021CA4* obj);
void fn_800E9424(Unk80021CA4* obj, s32 arg);
void fn_800E946C(Unk80021CA4* obj, u8 arg);
void fn_800E9750(Unk80021CA4* obj, u16 arg);
void fn_80040D50(Unk80021CA4Pos* pos);
BOOL fn_800B58F8(void* player, s32 arg1);
Unk80021CA4Child* fn_8009CF58(s32 kind, Unk80021CA4Pos* pos);
u32 fn_80080484(void* cam, s32* pos, s32 arg);
s32 fn_800A36F8(s32 x, s32 y);

void fn_80021CA4(Unk80021CA4* obj) {
    Unk80021CA4Pos pos;
    s32 dy;

    switch (obj->unk12) {
    case 0:
        if (!(lbl_80304B90.unk2D8 & 1)) {
            fn_800C7770(lbl_804EE984);
            fn_800C675C(0x60);
        }
        fn_800E9424(obj, 0x4E);
        fn_800E946C(obj, 0);
        fn_800E9244(obj);
        pos.x = obj->unk60;
        pos.y = obj->unk64;
        fn_80040D50(&pos);
        if (fn_800B58F8(lbl_804EE984, 2) == 0) {
            obj->unk38 = fn_8009CF58(1, &pos);
        } else {
            obj->unk38 = 0;
            if (!(lbl_80304B90.unk2D8 & 1)) {
                lbl_80304B90.unk2D8 |= 2;
            }
        }
        obj->unk6C = -0x600;
        obj->unk74 = 0x40;
        obj->unk12++;
    case 1:
        obj->unk64 += obj->unk6C;
        obj->unk6C += obj->unk74;
        if (obj->unk38 != 0 && obj->unk38->unk10 >= 2) {
            if (!(lbl_80304B90.unk2D8 & 1)) {
                lbl_80304B90.unk2D8 |= 2;
            }
            obj->unk38 = 0;
        }
        dy = fn_800A36F8(obj->unk60, obj->unk64);
        if (dy != 0) {
            obj->unk64 += dy;
            obj->unk12++;
        }
        break;
    case 2:
        fn_800E946C(obj, 0x1C);
        obj->unk54 |= 0x400;
        if ((obj->unk54 >> 10) & 1) {
            obj->unk0A |= 0x10;
        } else {
            obj->unk0A &= 0xEF;
        }
        obj->unk68 = 0x160;
        obj->unk16 = 0;
        obj->unk12++;
    case 3:
        if (fn_80080484(lbl_80304B90.unk21C, &obj->unk60, 1) <= 0x1400) {
            obj->unk60 += obj->unk68;
        }
        if (obj->unk38 != 0 && obj->unk38->unk10 >= 2) {
            if (!(lbl_80304B90.unk2D8 & 1)) {
                lbl_80304B90.unk2D8 |= 2;
            }
            obj->unk38 = 0;
        }
        if (obj->unk38 == 0 &&
            fn_80080484(lbl_80304B90.unk21C, &obj->unk60, 1) > 0x1400) {
            obj->unk12++;
        }
        break;
    case 4:
        lbl_80304B90.unk125 |= 2;
        lbl_80304B90.unk2D8 &= 0xFFFD;
        obj->unk18 = lbl_802638A0[obj->unk9]->unk10;
        obj->unk10 = 4;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
