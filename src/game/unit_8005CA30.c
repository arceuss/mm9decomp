#include "types.h"
#include "game/obj.h"

typedef struct Unk8005CA30 {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[6];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x54 - 0x17];
    /* 0x54 */ u32 unk54hi : 21;
    /* 0x54 */ u32 unk54bit : 1;
    /* 0x54 */ u32 unk54lo : 10;
    /* 0x58 */ u8 pad58[8];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[4];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[4];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0xC8 - 0x78];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ s32 unkCC;
} Unk8005CA30;

extern void (*lbl_80266DC8[])(Unk8005CA30*);

void fn_800C7C24(s32, s32, s32);
void fn_800E9244(Obj*);
void fn_800E9758(Obj*);
void fn_80042CF8(Obj*, s32);
extern u8 lbl_80304B90[];
s32 fn_80080484(void*, void*, s32);

void fn_8005CA30(Unk8005CA30* obj) {
    switch (obj->unk12) {
    case 0:
        fn_800E9244((Obj*)obj);
        obj->unk74 = -32;
        obj->unk6C = 0;
        obj->unk16 = 16;
        obj->unk12++;
    case 1:
        obj->unk64 += obj->unk6C;
        if (fn_80080484(lbl_80304B90 + 0x21C, &obj->unk60, 1) != 0) {
            fn_80042CF8((Obj*)obj, 2);
            obj->unk11 = 1;
            if (obj->unk14 != 3) {
                fn_800C7C24(obj->unk08, obj->unk09, 0);
            }
            lbl_80266DC8[obj->unk11](obj);
        } else {
            obj->unk6C += obj->unk74;
            if (obj->unk6C < -0x700) {
                obj->unk6C = -0x700;
            }
            if (--obj->unk16 == 0) {
                u8 flip = !((obj->unk0A >> 4) & 1);
                if (flip) {
                    obj->unk0A |= 0x10;
                } else {
                    obj->unk0A &= 0xEF;
                }
                obj->unk54bit = flip;
                obj->unk16 = 16;
            }
            fn_800E9758((Obj*)obj);
        }
        break;
    }
}
