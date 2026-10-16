#include "types.h"

typedef struct UnkB5064 {
    /* 0x000 */ u8 pad000[0xE4];
    /* 0x0E4 */ s16 unkE4;
    /* 0x0E6 */ u8 pad0E6[0x104 - 0x0E6];
    /* 0x104 */ u32 unk104;
} UnkB5064;

s32 fn_800B9658(void*);

s32 fn_800B5064(UnkB5064* obj) {
    s32 r = fn_800B9658((u8*)obj + 0x19C);
    if (obj->unk104 & 0x10000) {
        r += obj->unkE4;
    }
    return r;
}
