#include "types.h"

typedef struct Unk800AB87C {
    /* 0x00 */ u8 pad0[0xB];
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x20 - 0xC];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2A - 0x22];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D[0x2F - 0x2D];
    /* 0x2F */ u8 unk2F;
} Unk800AB87C;

extern void* lbl_804EE8AC;

Unk800AB87C* fn_800E8BEC(void* pool);

void fn_800AB87C(void) {
    Unk800AB87C* obj = fn_800E8BEC(lbl_804EE8AC);

    if (obj != NULL) {
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->flagsB |= 0x20;
        obj->unk21 = obj->unk20;
    }
}
