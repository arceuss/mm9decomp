#include "types.h"

typedef struct Unk804EE878Obj {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x14 - 0xC];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x18 - 0x16];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2A - 0x22];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x60 - 0x30];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0xD0 - 0x70];
    /* 0xD0 */ u8 unkD0;
    /* 0xD1 */ u8 unkD1;
} Unk804EE878Obj;

extern void* lbl_804EE878;
extern s32* lbl_804ECDE0[3];

Unk804EE878Obj* fn_800E8C44(void* pool);

Unk804EE878Obj* fn_8009CF58(u8 arg0, s32* pos) {
    Unk804EE878Obj* obj = fn_800E8C44(lbl_804EE878);

    if (obj != NULL) {
        obj->unk2E = 0x10;
        obj->unk9 = 1;
        obj->unk18 = *lbl_804ECDE0[1];
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->flagsB |= 0x20;
        obj->unk21 = obj->unk20;
        obj->unk14 = arg0;
        obj->unk60 = pos[0];
        obj->unk64 = pos[1];
    }
    return obj;
}
