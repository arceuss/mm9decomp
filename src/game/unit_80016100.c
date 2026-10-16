#include "types.h"

typedef struct Unk80016100 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x64 - 0x13];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x7C - 0x78];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 pad7D[0x88 - 0x7D];
    /* 0x88 */ u8 unk88[0xDC - 0x88];
    /* 0xDC */ s32 unkDC;
    /* 0xE0 */ s32 unkE0;
} Unk80016100;

extern u32 lbl_80262608[];

void fn_800E946C(Unk80016100* obj, s32 arg);
void fn_8009996C(void* dst, void* src);
void fn_800E9750(Unk80016100* obj, u16 arg);

void fn_80016100(Unk80016100* obj) {
    switch (obj->unk12) {
    case 0:
        fn_800E946C(obj, 1);
        fn_8009996C(obj->unk88, (void*)lbl_80262608[obj->unk7C]);
        obj->unk6C = 0;
        obj->unk74 = -0x20;
        obj->unk12++;
    case 1:
        obj->unk64 += obj->unk6C;
        obj->unk6C += obj->unk74;
        if (obj->unk6C < -0x280) {
            obj->unk6C = -0x280;
        }
        if (obj->unk64 < obj->unkDC) {
            obj->unk64 = obj->unkDC;
            obj->unkE0 = 0;
            obj->unk11 = 1;
            obj->unk12 = 0;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
