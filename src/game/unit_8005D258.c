#include "types.h"

typedef struct Unk8005D258 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x7D - 0x6C];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 pad7E[0xA0 - 0x7E];
    /* 0xA0 */ u32 unkA0;
} Unk8005D258;

typedef struct Unk804EE984 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 unk60;
} Unk804EE984;

extern Unk804EE984* lbl_804EE984;

void fn_800E946C(Unk8005D258* obj, u8 id);
void fn_800E9750(Unk8005D258* obj, u16 arg1);
void fn_800E9758(Unk8005D258* obj);
s32 fn_800A3CD4(s32 x, s32 y);
s32 fn_800A3FAC(s32 x, s32 y);
s32 fn_800A36F8(s32 x, s32 y);

void fn_8005D258(Unk8005D258* obj) {
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if ((obj->unkA0 & 1) || (obj->unkA0 & 0x2000)) {
            obj->step++;
        }
        break;
    case 2:
        fn_800E946C(obj, 1);
        obj->unk16 = 0x1E;
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        obj->unk16--;
        if (obj->unk16 == 0) {
            if (!(obj->flagsA & 0x10)) {
                if (obj->unk60 > lbl_804EE984->unk60) {
                    obj->step++;
                } else {
                    obj->state = 4;
                    obj->step = 2;
                }
            } else {
                if (obj->unk60 < lbl_804EE984->unk60) {
                    obj->step++;
                } else {
                    obj->state = 4;
                    obj->step = 2;
                }
            }
        }
        break;
    case 4:
        fn_800E946C(obj, 2);
        obj->unk68 = (((obj->flagsA >> 3) & 2) - 1) * 0xC0;
        obj->unk16 = 0x3C;
        obj->unk17 = 4;
        obj->step++;
    case 5:
        fn_800E9758(obj);
        if (obj->unk17 == 0) {
            obj->unk7D = !obj->unk7D;
            obj->unk17 = 4;
        } else {
            obj->unk17--;
        }
        obj->unk60 += obj->unk68;
        if (fn_800A3CD4(obj->unk60 + 0x1800, obj->unk64) != 0) {
            obj->step++;
            break;
        }
        if (fn_800A3FAC(obj->unk60 - 0x1800, obj->unk64) != 0) {
            obj->step++;
            break;
        }
        if (obj->unk68 < 0) {
            if (fn_800A36F8(obj->unk60 - 0x1800, obj->unk64 + 0x800) == 0) {
                obj->step++;
                break;
            }
        } else {
            if (fn_800A36F8(obj->unk60 + 0x1800, obj->unk64 + 0x800) == 0) {
                obj->step++;
                break;
            }
        }
        if (obj->unk68 < 0) {
            if (obj->unk60 - lbl_804EE984->unk60 <= 0x2800 && obj->unk60 > lbl_804EE984->unk60) {
                obj->state = 4;
                obj->step = 0;
                break;
            }
        } else {
            if (lbl_804EE984->unk60 - obj->unk60 <= 0x2800 && obj->unk60 < lbl_804EE984->unk60) {
                obj->state = 4;
                obj->step = 0;
                break;
            }
        }
        obj->unk16--;
        if (obj->unk16 == 0) {
            obj->step++;
        }
        break;
    case 6:
        fn_800E946C(obj, 1);
        obj->unk16 = 0x3C;
        obj->step++;
    case 7:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk68 < 0) {
            if (obj->unk60 - lbl_804EE984->unk60 <= 0x2800 && obj->unk60 > lbl_804EE984->unk60) {
                obj->state = 4;
                obj->step = 0;
                break;
            }
        } else {
            if (lbl_804EE984->unk60 - obj->unk60 <= 0x2800 && obj->unk60 < lbl_804EE984->unk60) {
                obj->state = 4;
                obj->step = 0;
                break;
            }
        }
        obj->unk16--;
        if (obj->unk16 == 0) {
            obj->state = 3;
            obj->step = 0;
        }
        break;
    }
}
