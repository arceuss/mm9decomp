#include "types.h"

typedef struct Unk800D1E60 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ struct Unk800D1E60* unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0x68 - 0x64];
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x74 - 0x6C];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0xC8 - 0x78];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 padCC[0xEC - 0xCC];
    /* 0xEC */ u8 unkEC;
    /* 0xED */ u8 unkED;
    /* 0xEE */ u8 unkEE;
    /* 0xEF */ u8 unkEF;
    /* 0xF0 */ u8 padF0[0xF4 - 0xF0];
    /* 0xF4 */ u8 unkF4;
    /* 0xF5 */ u8 unkF5;
    /* 0xF6 */ u8 unkF6;
    /* 0xF7 */ u8 unkF7;
} Unk800D1E60;

void fn_800D1E60(Unk800D1E60* obj) {
    Unk800D1E60* parent = obj->unk34;

    switch (obj->unk12) {
    case 0:
        obj->unk12++;
        obj->unk16 = 0x50;
        obj->unk68 = (obj->unk74 - obj->unk60) / 80;
    case 1:
        obj->unk60 += obj->unk68;
        if (obj->unk16 == 0) {
            obj->unk12++;
        } else {
            obj->unk16--;
        }
        break;
    case 2:
        obj->unk16 = 0x1E;
        obj->unk12++;
    case 3:
        if (obj->unk16 != 0) {
            obj->unk16--;
            break;
        }
        switch (obj->unkC8) {
        case 0:
            parent->unkEC = 0;
            parent->unkF4 = 0;
            break;
        case 1:
            parent->unkED = 0;
            parent->unkF5 = 0;
            break;
        case 2:
            parent->unkEE = 0;
            parent->unkF6 = 0;
            break;
        case 3:
            parent->unkEF = 0;
            parent->unkF7 = 0;
            break;
        }
        obj->unk11 = 0;
        obj->unk12 = 0;
        break;
    }
}
