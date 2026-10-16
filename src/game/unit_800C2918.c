#include "types.h"

typedef struct Unk800C2918 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ struct Unk800C2918* parent;
    /* 0x38 */ u8 pad38[0x50 - 0x38];
    /* 0x50 */ u32 unk50_hi : 30;
    /* 0x50 */ u32 unk50_lo : 2;
    /* 0x54 */ u8 pad54[0x64 - 0x54];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 unk74;
} Unk800C2918;

void fn_800E9424(Unk800C2918* obj, s32 id);
void fn_800E946C(Unk800C2918* obj, s32 id);
void fn_800E9750(Unk800C2918* obj, u16 arg1);

void fn_800C2918(Unk800C2918* obj) {
    Unk800C2918* parent = obj->parent;

    switch (obj->step) {
    case 0:
        fn_800E9424(obj, 0x10B);
        obj->unk16 = 0;
        fn_800E946C(obj, 0);
        obj->unk50_lo = 2;
        obj->unk6C = 0x400;
        obj->unk74 = 0;
        obj->step++;
    case 1:
        obj->unk64 += obj->unk6C;
        if (obj->unk64 > parent->unk64 - 0x1800) {
            obj->state = 1;
            obj->step = 0;
        }
        obj->unk6C += obj->unk74;
        if (obj->unk6C > 0x400) {
            obj->unk6C = 0x400;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
