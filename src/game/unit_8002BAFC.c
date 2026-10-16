#include "types.h"

typedef struct Unk316C8 {
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u32 unk8;
} Unk316C8;

void fn_800316C8(Unk316C8* obj, u32 arg);

void fn_8002BAFC(Unk316C8* obj) {
    fn_800316C8(obj, 0x6000005);
}
