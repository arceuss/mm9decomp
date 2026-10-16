#include "types.h"

typedef struct Unk316C8 {
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u32 unk8;
} Unk316C8;

void fn_80042CF8(Unk316C8* obj, u32 arg);

void fn_800717F0(Unk316C8* obj) {
    fn_80042CF8(obj, 4);
}
