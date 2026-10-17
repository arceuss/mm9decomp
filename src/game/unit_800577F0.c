#include "types.h"

typedef struct Unk800577F0 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x54 - 0x17];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 unk54_b10 : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x7C - 0x78];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 pad7E[0x88 - 0x7E];
    /* 0x88 */ u8 unk88[1];
} Unk800577F0;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern u8 lbl_802669A0[];
extern Unk800577F0* lbl_804EE984;

void fn_800E946C(Unk800577F0* obj, s32 arg1);
void fn_800E9750(Unk800577F0* obj, u16 arg1);
void fn_8009996C(void* handle, void* table);
void fn_800D5234(u32 id);
void fn_800778A4(Vec2i* pos, s32 arg1);
s32 fn_800A39F0(s32 x, s32 y);
s32 fn_800A36F8(s32 x, s32 y);

void fn_800577F0(Unk800577F0* obj) {
    u8* const table = lbl_802669A0;
    u32 f;
    s32 d;

    switch (obj->unk12) {
    case 0:
        fn_800E946C(obj, 0);
        fn_8009996C(obj->unk88, table + 0x40);
        obj->unk16 = 0x28;
        obj->unk12 = obj->unk12 + 1;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk16 == 0) {
            if (__abs(obj->unk60 - lbl_804EE984->unk60) <= 0x3800) {
                obj->unk12 = obj->unk12 + 1;
            }
        } else {
            obj->unk16 = obj->unk16 - 1;
        }
        break;
    case 2:
        fn_800E946C(obj, 1);
        f = lbl_804EE984->unk60 - obj->unk60 > 0;
        if (f) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->unk54_b10 = f;
        fn_8009996C(obj->unk88, table + 0x70);
        obj->unk6C = -0x480;
        obj->unk74 = 0x40;
        obj->unk12 = obj->unk12 + 1;
    case 3:
        if (obj->unk7C != 1 || obj->unk7D != 0) {
            obj->unk64 += obj->unk6C;
            obj->unk6C += obj->unk74;
        }
        if (obj->unk7C == 1 && obj->unk7D == 1) {
            fn_8009996C(obj->unk88, table + 0xA0);
        }
        if (obj->unk7C == 2 && obj->unk7D == 1) {
            fn_8009996C(obj->unk88, table + 0x40);
        }
        if (obj->unk6C >= 0 && obj->unk7C != 2) {
            Vec2i v;

            fn_800E946C(obj, 2);
            fn_8009996C(obj->unk88, table + 0xD0);
            v.x = obj->unk60;
            v.y = obj->unk64 - 0x1C00;
            fn_800D5234(0x3F);
            fn_800778A4(&v, 0);
            fn_800778A4(&v, 1);
        }
        d = fn_800A39F0(obj->unk60, obj->unk64 - 0x1E00);
        if (d > 0) {
            obj->unk64 += d;
            obj->unk6C = 0;
        }
        d = fn_800A36F8(obj->unk60, obj->unk64);
        if (d < 0) {
            obj->unk64 += d;
            obj->unk12 = obj->unk12 + 1;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 4:
        fn_800E946C(obj, 3);
        fn_8009996C(obj->unk88, table + 0x70);
        obj->unk16 = 8;
        fn_800D5234(0x41);
        obj->unk12 = obj->unk12 + 1;
    case 5:
        fn_800E9750(obj, 0xFFFF);
        if (--obj->unk16 == 0) {
            obj->unk12 = 0;
        }
        break;
    }
}
