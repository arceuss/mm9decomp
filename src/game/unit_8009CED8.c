#include "types.h"

typedef struct Unk8009CED8 {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x14 - 0xA];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x60 - 0x15];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x70 - 0x68];
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0xD0 - 0x78];
    /* 0xD0 */ u8 unkD0;
} Unk8009CED8;

extern s16 lbl_80274BA8[];

BOOL fn_8009CED8(Unk8009CED8* obj, s32* pos) {
    if (obj != NULL && (s32)obj->unk8 == 10 && obj->unk9 == 0 && ((1 << obj->unk14) & 0x19F) && obj->unkD0 == 0) {
        s32 x;
        s32 y;

        obj->unkD0 = 1;
        x = pos[0];
        obj->unk60 = x;
        y = pos[1];
        obj->unk64 = y;
        obj->unk70 = x;
        obj->unk74 = y + lbl_80274BA8[obj->unk14];
        return TRUE;
    }
    return FALSE;
}
