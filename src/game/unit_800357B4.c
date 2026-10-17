#include "types.h"

typedef struct Unk800357B4Entry {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
} Unk800357B4Entry;

typedef struct Unk800357B4 {
    /* 0x000 */ u8 pad0[0x28A];
    /* 0x28A */ u8 stage;
} Unk800357B4;

extern Unk800357B4Entry lbl_802643B0[];
extern Unk800357B4Entry lbl_802643D4[];
extern u8 lbl_80316D78[];

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x7480];
    /* 0x7480 */ u32 heard;
    /* 0x7484 */ u8 pad7484[0x7488 - 0x7484];
} Unk80383E70;

extern Unk80383E70 lbl_80383E70;
extern u8 lbl_804EE710;
extern u8 lbl_804EE711;
extern u8 lbl_804EE714[4];
extern u8 lbl_804EE718;

void fn_8000ECB8(s32 arg0, u32 font, s32 tile, s8 x, s8 y);

static inline u32 Font(void) {
    u32 R = *(u32*)(lbl_80316D78 + 0x3004) + 0xC29000;
    u32 a = *(u32*)(R + 8) >> 1;

    return a + R;
}

static inline void Row(u8 x, u8 y, u8 n) {
    for (lbl_804EE718 = 0; lbl_804EE718 < n; lbl_804EE718++) {
        fn_8000ECB8(0x38, Font(), 1, (u8)(x + lbl_804EE718), y);
    }
}

void fn_800357B4(Unk800357B4* obj, s32 mode) {
    switch (obj->stage) {
    case 0:
        lbl_804EE714[0] = 9;
        lbl_804EE714[1] = 0xe;
        lbl_804EE714[2] = 0xb;
        lbl_804EE714[3] = 4;
        lbl_804EE710 = lbl_802643B0[0].unk5;
        lbl_804EE711 = lbl_802643D4[0].unk5;
        break;
    case 1:
        lbl_804EE714[0] = 9;
        lbl_804EE714[1] = 0xe;
        lbl_804EE714[2] = 0xe;
        lbl_804EE714[3] = 4;
        lbl_804EE710 = lbl_802643B0[1].unk5;
        lbl_804EE711 = lbl_802643D4[1].unk5;
        break;
    case 2:
        lbl_804EE714[0] = 0xa;
        lbl_804EE714[1] = 0x10;
        lbl_804EE714[2] = 0xe;
        lbl_804EE714[3] = 4;
        lbl_804EE710 = lbl_802643B0[2].unk5;
        lbl_804EE711 = lbl_802643D4[2].unk5;
        break;
    case 3:
        lbl_804EE714[0] = 0xc;
        lbl_804EE714[1] = 0x11;
        lbl_804EE714[2] = 0xf;
        lbl_804EE714[3] = 6;
        lbl_804EE710 = lbl_802643B0[3].unk5;
        lbl_804EE711 = lbl_802643D4[3].unk5;
        break;
    case 4:
        lbl_804EE714[0] = 8;
        lbl_804EE714[1] = 0xd;
        lbl_804EE714[2] = 0x12;
        lbl_804EE714[3] = 4;
        lbl_804EE710 = lbl_802643B0[4].unk5;
        lbl_804EE711 = lbl_802643D4[4].unk5;
        break;
    case 5:
        lbl_804EE714[0] = 0xa;
        lbl_804EE714[1] = 0xf;
        lbl_804EE714[2] = 0xe;
        lbl_804EE714[3] = 5;
        lbl_804EE710 = lbl_802643B0[5].unk5;
        lbl_804EE711 = lbl_802643D4[5].unk5;
        break;
    }
    if (mode == 0) {
        fn_8000ECB8(0x38, Font(), 9, 0, 1);
        if (lbl_80383E70.heard & 2) {
            fn_8000ECB8(0x38, Font(), 0x19, lbl_804EE710, lbl_804EE711);
        } else {
            fn_8000ECB8(0x38, Font(), 2, lbl_804EE710, lbl_804EE711);
        }
        if (lbl_80383E70.heard & 4) {
            fn_8000ECB8(0x38, Font(), 0x1A, lbl_804EE710, (u8)(lbl_804EE711 + 2));
        } else {
            fn_8000ECB8(0x38, Font(), 2, lbl_804EE710, (u8)(lbl_804EE711 + 2));
        }
        if (lbl_80383E70.heard & 1) {
            fn_8000ECB8(0x38, Font(), 0x1B, lbl_804EE710, (u8)(lbl_804EE711 + 4));
        } else {
            fn_8000ECB8(0x38, Font(), 2, lbl_804EE710, (u8)(lbl_804EE711 + 4));
        }
        fn_8000ECB8(0x38, Font(), 3, lbl_804EE710, (u8)(lbl_804EE711 + 6));
    } else {
        if (lbl_80383E70.heard & 2) {
            Row(lbl_804EE710, lbl_804EE711, lbl_804EE714[0]);
        } else {
            Row(lbl_804EE710, lbl_804EE711, lbl_804EE714[0]);
        }
        if (lbl_80383E70.heard & 4) {
            Row(lbl_804EE710, lbl_804EE711 + 2, lbl_804EE714[1]);
        } else {
            Row(lbl_804EE710, lbl_804EE711 + 2, lbl_804EE714[1]);
        }
        if (lbl_80383E70.heard & 1) {
            Row(lbl_804EE710, lbl_804EE711 + 4, lbl_804EE714[2]);
        } else {
            Row(lbl_804EE710, lbl_804EE711 + 4, lbl_804EE714[2]);
        }
        Row(lbl_804EE710, lbl_804EE711 + 6, lbl_804EE714[3]);
    }
}
