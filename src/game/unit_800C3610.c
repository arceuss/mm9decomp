#include "types.h"

typedef struct Unk800C3610 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x24 - 0x17];
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u8 pad26[0x54 - 0x26];
    /* 0x54 */ u32 flags54_hi : 21;
    /* 0x54 */ u32 flags54_b10 : 1;
    /* 0x54 */ u32 flags54_lo : 10;
    /* 0x58 */ u8 pad58[0x7F - 0x58];
    /* 0x7F */ u8 unk7F;
} Unk800C3610;

void fn_800D5234(s32 id);
void fn_800E9424(Unk800C3610* obj, s32 id);
void fn_800E946C(Unk800C3610* obj, s32 id);
void fn_800E9244(Unk800C3610* obj);
void fn_800E9750(Unk800C3610* obj, u16 arg1);

void fn_800C3610(Unk800C3610* obj) {
    switch (obj->step) {
    case 0:
        fn_800D5234(0x15);
        if (obj->unk24 != 0x108) {
            fn_800E9424(obj, 0x108);
        }
        obj->unk16 = 1;
        fn_800E946C(obj, 1);
        obj->flagsA &= 0xEF;
        obj->flags54_b10 = 0;
        fn_800E9244(obj);
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7F == 3) {
            obj->state = 2;
            obj->step = 0;
        }
        break;
    }
}
