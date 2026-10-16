#include "types.h"

typedef struct UnkB4814 {
    /* 0x000 */ u8 pad000[0x104];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x188 - 0x108];
    /* 0x188 */ u16 unk188;
} UnkB4814;

extern u8 lbl_80304B90[];

s32 fn_80080484(void*, void*, s32);

s32 fn_800B4814(UnkB4814* obj) {
    s32 result;
    if (obj->unk104 & 0x4000) {
        result = 0;
    } else {
        if (fn_80080484(lbl_80304B90 + 0x21C, (u8*)obj + 0x60, 1) == 0
            && (obj->unk188 & 1)
            && !(obj->unk188 & 2)) {
            result = 1;
        } else {
            result = 0;
        }
    }
    return result;
}
