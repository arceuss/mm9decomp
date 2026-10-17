#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern u16 lbl_802740F0[];
extern u8 lbl_802740C8[];
extern Unk80316D78 lbl_80316D78;

void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 fn_800BB6C8(u32 id);
void fn_800BB7B8(u32 id);
u32 fn_8000ECB8(u32 a, u32 b, u32 c, u32 d, u32 e);

static inline void Play(u32 id, u32 v, u32 size) {
    u32 R;
    u32 a;
    u32 b;

    R = (u32)lbl_80316D78.unk3004 + 0xCD5000;
    a = *(u32*)(R + 0x14) >> 1;
    b = (*(u32*)(R + 0x18) >> 1) + R;
    fn_800BB4E8(id, v, a + R + *(u32*)(a + R), b + *(u32*)b, size, 0, b, a + R);
}

void fn_800939EC(u8* obj) {
    u16 cnt;
    u32 lim;
    u16 n;
    u8 v;

    n = *(u16*)(obj + 0x1008);
    lim = (*(u32*)(obj + 0xFF4) * 0x2E) >> 12;
    while (lim >= *(u32*)(obj + 0xFFC)) {
        *(u32*)(obj + 0xFFC) += lbl_802740F0[*(u16*)(obj + 0x1008)];
        n++;
    }
    v = lbl_802740C8[n / 2];
    if (v != *(u8*)(obj + 0x100C)) {
        u32 R = (u32)lbl_80316D78.unk3004 + 0xCD5000;
        u32 a = *(u32*)(R + 4) >> 1;

        fn_8000ECB8(0x38, a + R, v, 0, 0xE);
        *(u8*)(obj + 0x100C) = v;
    }
    cnt = *(u16*)(obj + 0x1004);
    if ((cnt & 3) == 0) {
        if ((u16)n - 1 > cnt / 2) {
            Play(0x8000, 0, 0x80);
            cnt++;
        }
    } else if ((cnt & 3) == 2) {
        if ((u16)n - 1 > cnt / 2) {
            Play(0x8001, 1, 0x80);
            cnt++;
        }
    }
    if ((cnt & 3) == 1) {
        if ((fn_800BB6C8(0x8000) & 0xFF) == 3) {
            fn_800BB7B8(0x8000);
            cnt++;
        }
    } else if ((cnt & 3) == 3) {
        if ((fn_800BB6C8(0x8001) & 0xFF) == 3) {
            fn_800BB7B8(0x8001);
            cnt++;
        }
    }
    *(u16*)(obj + 0x1008) = n;
    *(u16*)(obj + 0x1004) = cnt;
}
