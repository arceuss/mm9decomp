#include "types.h"

typedef struct Unk800AC92C {
    /* 0x00 */ u8 pad0[0xB];
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x20 - 0xC];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
} Unk800AC92C;

u32 fn_800B417C(Unk800AC92C* obj);

u32 fn_800AC92C(Unk800AC92C* obj) {
    u32 result = fn_800B417C(obj);

    if (result != 6) {
        obj->flagsB |= 0x20;
        obj->unk21 = obj->unk20;
        return result;
    }
    return 6;
}
