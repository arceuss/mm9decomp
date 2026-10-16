#include "types.h"

typedef struct Unk800999E8 {
    /* 0x00 */ void* unk0;
    /* 0x04 */ u8 pad4[0x36 - 0x4];
    /* 0x36 */ u8 unk36;
    /* 0x37 */ u8 pad37[0x3B - 0x37];
    /* 0x3B */ u8 unk3B;
} Unk800999E8;

void fn_800999E8(Unk800999E8* anim, void* data, u8 arg2) {
    anim->unk0 = data;
    anim->unk3B = arg2;
    anim->unk36 = 0;
}
