#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern u8 lbl_8031BF70[];
extern Unk80316D78 lbl_80316D78;

void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void fn_800BB6C8(u32 id);
void fn_800BB7B8(u32 id);

#define FLAGS (*(u32*)(lbl_8031BF70 + 0x4CEDC))

void fn_800A31D8(void) {
    s32 n = 0xF;
    u16 v = *(u16*)(lbl_8031BF70 + 0x890);
    u32 R;
    u32 a;
    u32 b;

    if ((v >> 8) == (*(u16*)(lbl_8031BF70 + 0x28C) & 0x7F)) {
        n = v & 0xF;
    }
    if (n == 0) {
        if (!(FLAGS & 1)) {
            R = (u32)lbl_80316D78.unk3004 + 0xCD5000;
            a = *(u32*)(R + 0x14) >> 1;
            b = (*(u32*)(R + 0x18) >> 1) + R;
            fn_800BB4E8(0x8000, 0, a + R + *(u32*)(a + R), b + *(u32*)b, 0x80, 0, b, a + R);
            FLAGS |= 1;
        }
        fn_800BB6C8(0x8000);
    } else if (FLAGS & 1) {
        fn_800BB7B8(0x8000);
        FLAGS &= ~1;
    }
}
