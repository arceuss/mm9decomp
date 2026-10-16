#include "types.h"

typedef struct UnkB7684 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 pad12[0x14 - 0x12];
    /* 0x14 */ u8 unk14;
} UnkB7684;

extern u8 lbl_80304B90[];

s32 fn_800B7684(UnkB7684* rec) {
    s32 idx = rec->unk14;
    s32 v = rec->unk11;
    s32 t = *(u16*)(lbl_80304B90 + idx * 2 + 0x2A0);
    if ((t & 0x8000) == 0) {
        t = (1 << v) & 0x101F;
    }
    return t;
}
