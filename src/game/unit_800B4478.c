#include "types.h"

typedef struct UnkB4478 {
    /* 0x000 */ u8 pad000[0x14];
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad015[0x104 - 0x15];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x18C - 0x108];
    /* 0x18C */ u16 unk18C;
} UnkB4478;

extern u16 lbl_80304B90[];

s32 fn_800B4478(UnkB4478* obj) {
    u32 mask;
    u16* table;
    if (obj->unk104 & 0x8000) {
        return 0;
    }
    table = (u16*)((u8*)lbl_80304B90 + 0x2A0);
    mask = 0x20;
    if (table[obj->unk14] & 0x8000) {
        mask = 0x100;
    }
    if (obj->unk18C & mask) {
        return mask;
    }
    return 0;
}
