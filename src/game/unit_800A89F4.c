#include "types.h"

typedef struct UnkA89F4 {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u8 unk8[2];
    /* 0x0A */ u16 unkA;
} UnkA89F4;

s32 fn_800A89F4(UnkA89F4* rec) {
    s32 i;
    u16 max = 0;
    u32 n = rec->unk0 / 12;
    if ((rec->unkA >> 3) & 1) {
        for (i = 0; i < n; i++) {
            if ((rec->unk4 >> 19) > (u32)max) {
                max = rec->unk4 >> 19;
            }
            rec++;
        }
    } else {
        for (i = 0; i < n; i++) {
            if ((rec->unk4 >> 18) > (u32)max) {
                max = rec->unk4 >> 18;
            }
            rec++;
        }
    }
    return max;
}
