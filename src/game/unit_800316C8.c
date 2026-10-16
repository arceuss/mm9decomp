#include "types.h"

typedef struct Unk316C8 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u32 unk8;
} Unk316C8;

void fn_800316C8(Unk316C8* obj, u32 arg) {
    obj->unk4 = (u8)arg;
    obj->unk5 = (u8)(arg >> 8);
    obj->unk6 = (u8)(arg >> 16);
    obj->unk7 = (u8)(arg >> 24);
    obj->unk8 = 0;
}
