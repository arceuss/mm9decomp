#include "types.h"

typedef struct Unk8001AB20 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x54 - 0x17];
    /* 0x54 */ struct {
        u32 hi : 21;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x88 - 0x78];
    /* 0x88 */ u8 unk88[4];
} Unk8001AB20;

extern Unk8001AB20* lbl_804EE984;
extern u8 lbl_80262AC0[];

void fn_800E946C(Unk8001AB20* obj, u8 anim);
void fn_800E9750(Unk8001AB20* obj, u16 arg1);
void fn_8009996C(void* dst, void* src);
s32 fn_800A3FAC(s32 x, s32 y);
s32 fn_800A3CD4(s32 x, s32 y);
s32 fn_800A36F8(s32 x, s32 y);
void fn_8001C340(Unk8001AB20* obj);

void fn_8001AB20(Unk8001AB20* obj) {
    u8* const msg = lbl_80262AC0;
    s32 d;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        fn_8009996C(obj->unk88, msg + 0x98);
        d = lbl_804EE984->x - obj->x;
        obj->bits54.flip = (u32)(-d & ~d) >> 31;
        if (obj->bits54.flip) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->unk16 = 0x10;
        obj->step++;
    case 1:
        if (obj->unk16 == 0) {
            obj->step++;
        } else {
            obj->unk16--;
        }
        break;
    case 2:
        fn_800E946C(obj, 2);
        fn_8009996C(obj->unk88, msg + 0xC8);
        obj->unk68 = (((obj->flagsA >> 3) & 2) - 1) * 0x400;
        obj->unk6C = 0;
        obj->unk74 = -0x400;
        obj->unk70 = -0x80;
        obj->step++;
    case 3:
        obj->x += obj->unk68;
        obj->unk64 += obj->unk6C;
        obj->unk6C += obj->unk74 >> 8;
        obj->unk74 += obj->unk70;
        if (!(obj->flagsA & 0x10)) {
            d = fn_800A3FAC(obj->x - 0x1000, obj->unk64);
            if (d != 0) {
                obj->x += d;
                obj->step++;
            }
        } else {
            d = fn_800A3CD4(obj->x + 0x1000, obj->unk64);
            if (d != 0) {
                obj->x += d;
                obj->step++;
            }
        }
        break;
    case 4:
        fn_800E946C(obj, 1);
        fn_8009996C(obj->unk88, msg + 0x98);
        obj->unk6C = 0;
        obj->unk74 = 0x20;
        obj->step++;
    case 5:
        obj->unk64 += obj->unk6C;
        obj->unk6C += obj->unk74;
        d = fn_800A36F8(obj->x, obj->unk64);
        if (d != 0) {
            obj->unk64 += d;
            obj->step++;
        }
        break;
    case 6:
        fn_800E946C(obj, 0);
        fn_8009996C(obj->unk88, msg + 0x68);
        obj->unk16 = 0x14;
        obj->step++;
    case 7:
        if (obj->unk16 == 0) {
            fn_8001C340(obj);
        } else {
            obj->unk16--;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
