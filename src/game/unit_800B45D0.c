#include "types.h"

typedef struct UnkB45D0 {
    /* 0x000 */ u8 pad000[9];
    /* 0x009 */ u8 unk09;
    /* 0x00A */ u8 pad00A[0x14 - 0x0A];
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad015[0x188 - 0x15];
    /* 0x188 */ u16 unk188;
    /* 0x18A */ u8 pad18A[0x18C - 0x18A];
    /* 0x18C */ u16 unk18C;
} UnkB45D0;

extern u16 lbl_80304B90[];

s32 fn_800B45D0(UnkB45D0* obj) {
    if (((1 << obj->unk09) & 4)
        && !(((u16*)((u8*)lbl_80304B90 + 0x2A0))[obj->unk14] & 0x8000)
        && (obj->unk188 & 2)
        && (obj->unk18C & 0x20)) {
        return 1;
    }
    return 0;
}
