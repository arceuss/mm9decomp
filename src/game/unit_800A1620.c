#include "types.h"

typedef struct Unk800A03BCArc {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u32 seqOff;
    /* 0x18 */ u32 bankOff;
} Unk800A03BCArc;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern u8 lbl_8031BF70[];
extern Unk80316D78 lbl_80316D78;

void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 fn_800BB6C8(u32 id);
void fn_800BB7B8(u32 id);

#define FLAGS (*(u32*)(lbl_8031BF70 + 0x4CEDC))
#define CUR (*(u32*)(lbl_8031BF70 + 0x4CEE0))

static inline s32 Mode(void) {
    u16 v = *(u16*)(lbl_8031BF70 + 0x890);
    s32 n = 0xF;

    if ((v >> 8) == (*(u16*)(lbl_8031BF70 + 0x28C) & 0x7F)) {
        n = v & 0xF;
    }
    return n;
}

static inline void Play(u32 id, s32 x, s32 idx, s32 size) {
    u32 R;
    u32 a;
    u32 b;

    R = (u32)lbl_80316D78.unk3004 + 0xCD5000;
    a = *(u32*)(R + 0x14) >> 1;
    b = (*(u32*)(R + 0x18) >> 1) + R;
    fn_800BB4E8(id, x, a + R + ((u32*)(a + R))[idx], b + ((u32*)b)[idx], size, 0, b, a + R);
}

void fn_800A1620(s32* pos) {
    s32 sw = 0;
    u32 st;
    u32 r;

    if (Mode() == 0) {
        if (!(FLAGS & 1)) {
            Play(0x8000, 0, 0, 0x60);
            FLAGS |= 1;
        }
        fn_800BB6C8(0x8000);
    } else if (FLAGS & 1) {
        fn_800BB7B8(0x8000);
        FLAGS &= ~1;
    }
    if (Mode() == 0) {
        if (!(FLAGS & 2)) {
            Play(0x8100, 0, 1, 0x80);
            FLAGS |= 2;
        }
        fn_800BB6C8(0x8100);
    } else if (FLAGS & 2) {
        fn_800BB7B8(0x8100);
        FLAGS &= ~2;
    }
    r = fn_800BB6C8(CUR | 0x8200);
    fn_800BB6C8(CUR | 0x8300);
    fn_800BB6C8(CUR | 0x8400);
    switch (CUR) {
    case 0:
        if (pos[0] >= 0x88000 && pos[0] <= 0x127FFF && pos[1] >= 0x23000 && pos[1] <= 0x37FFF) {
            st = 2;
            sw = 1;
        }
        break;
    case 2:
        if ((u8)r == 3) {
            st = 1;
            sw = 1;
        }
        break;
    case 1:
        if (!(pos[0] >= 0x88000 && pos[0] <= 0x127FFF && pos[1] >= 0x23000 && pos[1] <= 0x37FFF)) {
            st = 3;
            sw = 1;
        }
        break;
    case 3:
        if ((u8)r == 3) {
            st = 0;
            sw = 1;
        }
        break;
    }
    if (sw) {
        fn_800BB7B8(CUR | 0x8200);
        fn_800BB7B8(CUR | 0x8300);
        fn_800BB7B8(CUR | 0x8400);
        Play(st | 0x8200, st, 2, 0);
        Play(st | 0x8300, st, 3, 0x20);
        Play(st | 0x8400, st, 4, 0x40);
        CUR = st;
    }
}
