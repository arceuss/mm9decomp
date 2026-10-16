#include "types.h"

typedef struct Unk800A7D8C {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ u16* unk4;
    /* 0x08 */ u8 pad8[0xA - 0x8];
    /* 0x0A */ u16 unkA;
} Unk800A7D8C;

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ void* unk4[0x400];
} Unk80383E70;

typedef struct Unk8037CC40 {
    /* 0x0000 */ u8 pad0[0x1008];
    /* 0x1008 */ u8 unk1008[0x7230 - 0x1008];
} Unk8037CC40;

extern Unk8037CC40 lbl_8037CC40;
extern Unk80383E70 lbl_80383E70;

void fn_800A9090(void* p, void* src, u16 index, u16 arg3, s32 arg4, s32 arg5, s32 arg6);

void fn_800A7D8C(Unk800A7D8C* s) {
    u8 i;
    u16 index;
    u16 e;

    if (s->unk4 == NULL) {
        return;
    }
    for (i = 0; i < (u8)s->unkA; i++) {
        e = s->unk4[i];
        index = e & 0x3FF;
        if (e & 0x2000) {
            index = 0x1FF - ((e >> 10) & 7);
        }
        if (e & 0x4000) {
            fn_800A9090(lbl_8037CC40.unk1008, lbl_80383E70.unk4[index], index, index, 0, 1, 0);
        } else {
            fn_800A9090(lbl_8037CC40.unk1008, lbl_80383E70.unk4[index], index, index, 0, 1, 1);
        }
    }
}
