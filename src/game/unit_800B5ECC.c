#include "types.h"

typedef struct UnkB5ECC {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0xCC - 0xA];
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD0 - 0xCD];
    /* 0xD0 */ s32 unkD0;
    /* 0xD4 */ s32 unkD4;
} UnkB5ECC;

s32 fn_800B5ECC(UnkB5ECC* rec, s32* v) {
    if ((s32)rec->unk8 == 3 && rec->unk9 == 0 && rec->unkCC == 0) {
        rec->unkCC = 1;
        rec->unkD0 = v[0];
        rec->unkD4 = v[1];
    }
    return 0;
}
