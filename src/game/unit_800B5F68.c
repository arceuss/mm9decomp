#include "types.h"

typedef struct Unk57 {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0xC8 - 0xA];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 unkCD;
    /* 0xCE */ u8 padCE[0xD0 - 0xCE];
    /* 0xD0 */ u8 unkD0;
    /* 0xD1 */ u8 unkD1;
    /* 0xD2 */ u8 padD2[0xD4 - 0xD2];
    /* 0xD4 */ s32 unkD4;
} Unk57;

s32 fn_800B5F68(Unk57* rec) {
    if ((s32)rec->unk8 == 1 && (u32)rec->unk9 == 2) {
        rec->unkD1 = 1;
    }
    return 0;
}
