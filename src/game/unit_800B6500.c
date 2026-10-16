#include "types.h"

typedef struct UnkB6500 {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[0x54 - 0xB];
    /* 0x54 */ u32 unk54a : 21;
    /* 0x54 */ u32 unk54b : 1;
    /* 0x54 */ u32 unk54c : 10;
} UnkB6500;

void fn_800B6500(UnkB6500* obj, u32 v) {
    obj->unk54b = v;

    if (obj->unk54b) {
        obj->unk0A |= 0x10;
    } else {
        obj->unk0A &= 0xEF;
    }
}
