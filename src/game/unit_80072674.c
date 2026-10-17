#include "types.h"

typedef struct Unk80072674Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk80072674Pos;

typedef struct Unk80072674Rec {
    /* 0x0 */ Unk80072674Pos pos;
    /* 0x8 */ u32 kind;
} Unk80072674Rec;

typedef struct Unk80304B68 {
    /* 0x00 */ u8 pad0[0x15];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x18 - 0x16];
    /* 0x18 */ u8 cntB;
    /* 0x19 */ u8 cntA;
    /* 0x1A */ u8 lastA;
    /* 0x1B */ u8 lastB;
    /* 0x1C */ u8 pad1C[0x28 - 0x1C];
} Unk80304B68;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x2144];
    /* 0x2144 */ u32 seed;
} Unk803140C0;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0;
    /* 0x01 */ struct {
        u8 hi : 1;
        u8 lo : 7;
    } unk1;
} Unk803051D8;

extern Unk80304B68 lbl_80304B68;
extern Unk803140C0 lbl_803140C0;
extern Unk803051D8 lbl_803051D8;
extern u8 lbl_804EE808[8];
extern u8 lbl_804EE800[8];
extern Unk80072674Rec lbl_80268C20[];
extern Unk80072674Rec lbl_80268BC0[];

void fn_8009BF14(s32 val, void* dst, s32 size);
void fn_800A2F38(void);

u8 fn_80072674(Unk80072674Pos* out) {
    u32 seed;
    u8 v;
    u8 last;
    u8 byte;
    u32 bit;

    if (lbl_80304B68.cntA < 5) {
        if (lbl_80304B68.cntA == 0 && lbl_80304B68.cntB >= 8) {
            if (++lbl_80304B68.unk15 >= 0x1C) {
                lbl_80304B68.unk15 = 0x1C;
            }
        }
        seed = lbl_803140C0.seed;
        last = lbl_80304B68.lastA;
        for (;;) {
            seed = seed * 0x41C64E6D + 0x3039;
            v = (seed >> 16) % 0x22;
            if (v != last) {
                byte = lbl_804EE808[v >> 3];
                bit = 1 << (v & 7);
                if (!(byte & bit)) {
                    break;
                }
            }
        }
        lbl_80304B68.lastA = v;
        lbl_803140C0.seed = seed;
        lbl_804EE808[v >> 3] = byte | bit;
        lbl_80304B68.cntA++;
        *out = lbl_80268C20[v].pos;
        return lbl_80268C20[v].kind;
    }
    fn_8009BF14(0, lbl_804EE808, 8);
    lbl_80304B68.cntA = 0;
    if (lbl_80304B68.cntB >= 8) {
        lbl_803051D8.unk1.lo = 0;
        lbl_803051D8.unk1.hi = 0;
        fn_8009BF14(0, lbl_804EE800, 4);
        lbl_80304B68.cntB = 0;
    }
    seed = lbl_803140C0.seed;
    last = lbl_80304B68.lastB;
    for (;;) {
        seed = seed * 0x41C64E6D + 0x3039;
        v = (seed >> 16) & 7;
        if (v != last) {
            byte = lbl_804EE800[v >> 3];
            bit = 1 << v;
            if (!(byte & bit)) {
                break;
            }
        }
    }
    lbl_803140C0.seed = seed;
    lbl_80304B68.lastB = v;
    lbl_804EE800[v >> 3] = byte | bit;
    lbl_80304B68.cntB++;
    fn_800A2F38();
    *out = lbl_80268BC0[v].pos;
    return lbl_80268BC0[v].kind;
}
