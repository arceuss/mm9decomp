#include "types.h"

typedef struct Unk800C04E4 {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x24 - 0x17];
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u8 pad26[0x60 - 0x26];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0x68 - 0x64];
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x70 - 0x6C];
    /* 0x70 */ s32 unk70;
} Unk800C04E4;

void fn_800E9424(Unk800C04E4* obj, s32 id);
void fn_800E946C(Unk800C04E4* obj, s32 id);
void fn_800E9750(Unk800C04E4* obj, u16 arg1);

void fn_800C04E4(Unk800C04E4* obj) {
    switch (obj->step) {
    case 0:
        if (obj->unk24 != 0x106) {
            fn_800E9424(obj, 0x106);
        }
        obj->unk16 = 0;
        fn_800E946C(obj, 0);
        obj->step++;
    case 1:
        obj->unk60 += obj->unk68;
        obj->unk68 += obj->unk70;
        if (obj->unk68 > 0x600) {
            obj->unk68 = 0x600;
        } else if (obj->unk68 < -0x600) {
            obj->unk68 = -0x600;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
