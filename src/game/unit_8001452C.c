#include "types.h"

typedef struct Unk804EE984 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 unk60;
} Unk804EE984;

extern Unk804EE984* lbl_804EE984;

typedef struct Unk8001452C {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[0x12 - 0xB];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x54 - 0x17];
    /* 0x54 */ u32 unk54a : 10;
               u32 unk54b : 11;
               u32 unk54Flag : 1;
               u32 unk54c : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0xDA - 0x64];
    /* 0xDA */ u8 unkDA;
} Unk8001452C;

void fn_800E946C(Unk8001452C* obj, s32 arg);
void fn_800E9750(Unk8001452C* obj, u16 arg);
void fn_8001493C(Unk8001452C* obj);

void fn_8001452C(Unk8001452C* obj) {
    switch (obj->unk12) {
    case 0:
        fn_800E946C(obj, 1);
        obj->unk54Flag = (lbl_804EE984->unk60 - obj->unk60) > 0;
        if (obj->unk54Flag) {
            obj->unk0A |= 0x10;
        } else {
            obj->unk0A &= 0xEF;
        }
        obj->unk16 = 60;
        obj->unk12++;
    case 1:
        if (obj->unk16 == 0) {
            obj->unk12++;
        } else {
            obj->unk16--;
        }
        break;
    case 2:
        fn_800E946C(obj, 4);
        obj->unk16 = 16;
        obj->unk12++;
    case 3:
        if (obj->unk16 == 0) {
            obj->unkDA = 0;
            fn_8001493C(obj);
        } else {
            obj->unk16--;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
