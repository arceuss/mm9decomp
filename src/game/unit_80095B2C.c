#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;
extern u8 lbl_80274350[];
extern u8 lbl_80274318[];
extern u8 lbl_803051D8[];
extern void* lbl_804EE984;

s32 fn_800B5BE4(void* p);
s32 fn_800B5B6C(void* p);
void fn_8000ECB8(u32 a, u32 b, u32 c, s32 d, s32 e);

static inline void Glyph(u32 idx, s8 x, s8 y) {
    u32 R = (u32)lbl_80316D78.unk3004 + 0xCD5000;

    fn_8000ECB8(0x38, (*(u32*)(R + 4) >> 1) + R, idx, x, y);
}

void fn_80095B2C(void) {
    u16 n;
    u8* p;
    s32 i;
    u8 a;
    u8 b;
    u16 d;

    for (i = 0, p = lbl_80274350; i < 8; i++, p += 2) {
        a = p[0];
        b = p[1];
        if (i == 7) {
            u16 v = fn_800B5BE4(lbl_804EE984);

            d = v / 100;
            n = v - d * 100;
            if (d > 9) {
                d = 9;
            }
            Glyph(lbl_80274318[d], a, b);
            d = n / 10;
            n = n - d * 10;
            Glyph(lbl_80274318[d], a + 1, b);
            Glyph(lbl_80274318[n], a + 2, b);
        } else if (i == 6) {
            n = fn_800B5B6C(lbl_804EE984);
            Glyph(lbl_80274318[0], a, b);
            Glyph(lbl_80274318[n], a + 1, b);
        } else {
            s32 c = *(s8*)((u8*)lbl_80316D78.unk3004 + 0xD40000 + 0x101E + i);

            Glyph(lbl_80274318[0], a, b);
            Glyph(lbl_80274318[(u16)c], a + 1, b);
        }
    }
    {
        u32 k1 = (lbl_803051D8[3] >> 7) & 1;

        Glyph(lbl_80274318[0], 0x10, 0x15);
        Glyph(lbl_80274318[k1], 0x11, 0x15);
    }
    {
        u32 k2 = (lbl_803051D8[3] >> 5) & 1;

        Glyph(lbl_80274318[0], 0x10, 0x19);
        Glyph(lbl_80274318[k2], 0x11, 0x19);
    }
}
