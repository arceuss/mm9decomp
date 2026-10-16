#include "types.h"

typedef struct Unk800C2A14Parent {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 unkA;
    /* 0x00B */ u8 padB[0x11 - 0xB];
    /* 0x011 */ u8 unk11;
    /* 0x012 */ u8 pad12[0x50 - 0x12];
    /* 0x050 */ u32 unk50_hi : 30;
    /* 0x050 */ u32 unk50_lo : 2;
    /* 0x054 */ u8 pad54[0x60 - 0x54];
    /* 0x060 */ u32 unk60;
    /* 0x064 */ u32 unk64;
    /* 0x068 */ u8 pad68[0x108 - 0x68];
    /* 0x108 */ u8 unk108;
} Unk800C2A14Parent;

typedef struct Unk800C2A14 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800C2A14Parent* unk34;
    /* 0x38 */ u8 pad38[0x50 - 0x38];
    /* 0x50 */ u32 unk50_hi : 30;
    /* 0x50 */ u32 unk50_lo : 2;
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 unk54_b10 : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ u32 unk60;
    /* 0x64 */ u32 unk64;
    /* 0x68 */ u8 pad68[0x7D - 0x68];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ s8 unk7E;
    /* 0x7F */ u8 pad7F[0xC8 - 0x7F];
    /* 0xC8 */ u8 unkC8;
} Unk800C2A14;

void fn_800E9424(Unk800C2A14* obj, s32 v);
void fn_800E946C(Unk800C2A14* obj, s32 v);
void fn_800E9750(Unk800C2A14* obj, u16 v);
void fn_800E947C(Unk800C2A14* obj, s32 a, s8 b, s8 c);

void fn_800C2A14(Unk800C2A14* obj) {
    Unk800C2A14Parent* parent = obj->unk34;
    u8 c;
    s32 a;
    u32 b;

    switch (obj->unk12) {
    case 0:
        if (obj->unk16 != 0) {
            fn_800E9424(obj, 0x10B);
            obj->unk16 = 0;
            fn_800E946C(obj, 0);
        }
        obj->unkC8 = 1;
        obj->unk12++;
    case 1:
        if (parent->unk11 != 5) {
            obj->unkC8 = 0;
            obj->unk11 = 2;
            obj->unk12 = 0;
        } else {
            if (parent->unk108 < 0x3C && obj->unk16 != 1) {
                a = obj->unk7E;
                c = obj->unk7D;
                fn_800E9424(obj, 0x10B);
                obj->unk16 = 1;
                fn_800E947C(obj, 1, c, (s8)(u8)a);
            }
        }
        obj->unk50_lo = parent->unk50_lo;
        b = (parent->unkA >> 4) & 1;
        if (b != 0) {
            obj->unkA |= 0x10;
        } else {
            obj->unkA &= 0xEF;
        }
        obj->unk54_b10 = b;
        obj->unk60 = parent->unk60;
        obj->unk64 = parent->unk64 - 0x1800;
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
