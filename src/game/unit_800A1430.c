#include "game/work_8031BF70.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
    /* 0x3008 */ u8 pad3008[0x3028 - 0x3008];
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;

void fn_800BB938(u8 arg0, void* data, s32 size);

void fn_800A1430(void) {
    u8* base;

    if (lbl_8031BF70.unk4AEAE != 0) {
        base = lbl_80316D78.unk3004 + 0xCD5000;
        base = (u8*)(*(u32*)(base + 0x14) / 2 + (u32)base);
        fn_800BB938(lbl_8031BF70.unk4CEE0, base + *(u32*)(base + 4), 0x40);
    }
}
