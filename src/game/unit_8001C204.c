#include "types.h"

typedef struct Unk8001C204 {
    /* 0x00 */ u8 pad00[0x09];
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 pad0B[0x10 - 0x0B];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 state;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x18 - 0x17];
    /* 0x18 */ u32 unk18;
} Unk8001C204;

typedef struct Unk802638A0 {
    u8 pad00[0xC];
    /* 0x0C */ u32 unk0C;
} Unk802638A0;

extern Unk802638A0* lbl_802638A0[];

void fn_800E9244(Unk8001C204* obj);
void fn_800E9AA0(Unk8001C204* obj, s32 a, s32 b);
void fn_800E9C90(Unk8001C204* obj);
void fn_800E9758(Unk8001C204* obj);

void fn_8001C204(Unk8001C204* obj) {
    switch (obj->state) {
    case 0:
        fn_800E9244(obj);
        fn_800E9AA0(obj, 1, 0);
        obj->unk16 = 0x1e;
        obj->state++;
    case 1:
        fn_800E9C90(obj);
        if (obj->unk16 == 0) {
            obj->state++;
        } else {
            obj->unk16--;
        }
        break;
    case 2:
        fn_800E9AA0(obj, 2, 0);
        obj->unk16 = 0xc;
        obj->state++;
    case 3:
        fn_800E9C90(obj);
        if (obj->unk16 == 0) {
            u8 v = obj->flagsA & 0xFE;
            obj->flagsA = v & 0xFD;
            fn_800E9244(obj);
            obj->unk18 = lbl_802638A0[obj->unk09]->unk0C;
            obj->unk10 = 3;
            obj->unk11 = 0;
            obj->state = 0;
            obj->unk13 = 0;
            return;
        }
        obj->unk16--;
        break;
    }
    fn_800E9758(obj);
}
