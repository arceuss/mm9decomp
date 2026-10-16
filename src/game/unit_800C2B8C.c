#include "types.h"

typedef struct Unk8027F228Entry {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u8 padC[4];
    /* 0x10 */ u32 unk10;
} Unk8027F228Entry;

typedef struct Unk800C2B8C {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 pad1C[0x50 - 0x1C];
    /* 0x50 */ u32 unk50_hi : 30;
    /* 0x50 */ u32 unk50_lo : 2;
    /* 0x54 */ u8 pad54[0x64 - 0x54];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x7D - 0x78];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ s8 unk7E;
    /* 0x7F */ u8 pad7F[0xC9 - 0x7F];
    /* 0xC9 */ u8 unkC9;
} Unk800C2B8C;

extern Unk8027F228Entry* lbl_8027F228[];
extern u8 lbl_80304B90[];

void fn_800E9424(Unk800C2B8C* obj, s32 v);
void fn_800E9244(Unk800C2B8C* obj);
void fn_800E9750(Unk800C2B8C* obj, u16 v);
void fn_800E947C(Unk800C2B8C* obj, s32 a, s8 p1, s8 p2);
void fn_800C2918(Unk800C2B8C* obj);

void fn_800C2B8C(Unk800C2B8C* obj) {
    u8 c;
    s32 a;

    switch (obj->unk12) {
    case 0:
        obj->unk50_lo = 2;
        if (obj->unk16 != 0) {
            a = obj->unk7E;
            c = obj->unk7D;
            fn_800E9424(obj, 0x10B);
            obj->unk16 = 0;
            fn_800E947C(obj, 0, c, (s8)(u8)a);
        }
        obj->unk6C = -0x200;
        obj->unk74 = 0;
        obj->unk12++;
    case 1:
        if (obj->unkC9 != 0) {
            obj->unkC9 = 0;
            obj->unk11 = 0;
            obj->unk12 = 0;
            fn_800C2918(obj);
        } else {
            obj->unk64 += obj->unk6C;
            if (obj->unk64 < *(s32*)(lbl_80304B90 + 0x260) - 0x7000) {
                obj->unk18 = lbl_8027F228[obj->unk9]->unk8;
                obj->unk10 = 2;
                obj->unk11 = 0;
                obj->unk12 = 0;
                obj->unk13 = 0;
                obj->unk18 = lbl_8027F228[obj->unk9]->unk10;
                obj->unk10 = 4;
                obj->unk11 = 0;
                obj->unk12 = 0;
                obj->unk13 = 0;
                fn_800E9244(obj);
                obj->unkA &= ~1;
            } else {
                obj->unk6C += obj->unk74;
                if (obj->unk6C < -0x200) {
                    obj->unk6C = -0x200;
                }
                fn_800E9750(obj, 0xFFFF);
            }
        }
        break;
    }
}
