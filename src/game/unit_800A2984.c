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

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x26BC];
    /* 0x26BC */ u16 unk26BC;
} Unk8038B2F8;

extern Unk8038B2F8 lbl_8038B2F8;

#define FLAGS (*(u32*)(lbl_8031BF70 + 0x4CEDC))

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

extern u8 lbl_803051D8[];
extern u8 lbl_8027B104[];
u16 fn_8009E850(s32, s32);
void fn_8009EF24(s32, s32, void*);

void fn_800A2984(void) {
    if (Mode() == 0) {
        if (!(FLAGS & 1)) {
            Play(0x8000, 0, 0, 0x0);
            FLAGS |= 1;
        }
        fn_800BB6C8(0x8000);
    } else if (FLAGS & 1) {
        fn_800BB7B8(0x8000);
        FLAGS &= ~1;
    }
    if (Mode() == 0) {
        if (!(FLAGS & 2)) {
            Play(0x8100, 0, 1, 0xA0);
            FLAGS |= 2;
        }
        fn_800BB6C8(0x8100);
    } else if (FLAGS & 2) {
        fn_800BB7B8(0x8100);
        FLAGS &= ~2;
    }
    if (Mode() == 0) {
        if (!(FLAGS & 4)) {
            Play(0x8200, 0, 2, 0x20);
            FLAGS |= 4;
        }
        fn_800BB6C8(0x8200);
    } else if (FLAGS & 4) {
        fn_800BB7B8(0x8200);
        FLAGS &= ~4;
    }
    if (Mode() == 0) {
        if (!(FLAGS & 8)) {
            Play(0x8300, 0, 3, 0x60);
            FLAGS |= 8;
        }
        fn_800BB6C8(0x8300);
    } else if (FLAGS & 8) {
        fn_800BB7B8(0x8300);
        FLAGS &= ~8;
    }
    if (Mode() == 0) {
        if (!(FLAGS & 16)) {
            Play(0x8400, 0, 4, 0xE0);
            FLAGS |= 16;
        }
        fn_800BB6C8(0x8400);
    } else if (FLAGS & 16) {
        fn_800BB7B8(0x8400);
        FLAGS &= ~16;
    }
    if ((lbl_803051D8[1] & 1) && (lbl_803051D8[1] & 2) && (lbl_803051D8[1] & 4) && (lbl_803051D8[1] & 8) && (lbl_803051D8[1] & 0x10) && (lbl_803051D8[1] & 0x20) && (lbl_803051D8[1] & 0x40) && (lbl_803051D8[1] & 0x80)) {
        if (fn_8009E850(0x27000, 0x80000) == 0x32) fn_8009EF24(0x27, 0x80, lbl_8027B104);
    }
    lbl_8038B2F8.unk26BC = 0;
}
