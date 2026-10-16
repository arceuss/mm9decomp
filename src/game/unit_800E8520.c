#include "types.h"

typedef struct Unk8043CA80Entry {
    /* 0x0 */ u32 kind : 2;
    /* 0x0 */ u32 size : 30;
    /* 0x4 */ void* dst;
    /* 0x8 */ void* src;
} Unk8043CA80Entry;

typedef struct Unk8043CA80 {
    /* 0x000 */ s32 count;
    /* 0x004 */ Unk8043CA80Entry entries[0x30];
    /* 0x244 */ u8 pad244[0x258 - 0x244];
    /* 0x258 */ u8* unk258[2];
    /* 0x260 */ u32 unk260[2];
} Unk8043CA80;

extern Unk8043CA80 lbl_8043CA80;

void fn_8009C04C(s32 value, void* dst, s32 size);

void fn_800E8520(s32 value, u32 addr, s32 size) {
    u8* base;

    if (addr < 0x400000) {
        base = lbl_8043CA80.unk258[0];
    } else {
        base = lbl_8043CA80.unk258[1];
    }
    fn_8009C04C(value, base + (addr & 0xFFFFF), size);
}
