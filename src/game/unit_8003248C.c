#include "types.h"

typedef struct Unk316C8 {
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u32 unk8;
} Unk316C8;

void fn_800316C8(Unk316C8* obj, u32 arg);

void fn_8003248C(Unk316C8* obj) {
    u8 t = *(u8*)((u8*)obj + 0x26E);
    if (t == 2) {
        fn_800316C8(obj, 8);
        return;
    }
    if (t == 3) {
        *(u8*)((u8*)obj + 0x26E) = 1;
    }
}
