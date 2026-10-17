#include "types.h"

typedef struct Unk80033F64Entry {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
} Unk80033F64Entry;

typedef struct Unk80033F64 {
    /* 0x000 */ u8 pad0[0x28A];
    /* 0x28A */ u8 stage;
} Unk80033F64;

extern Unk80033F64Entry lbl_802643B0[];
extern Unk80033F64Entry lbl_802643D4[];
extern u8 lbl_80316D78[];

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x7480];
    /* 0x7480 */ u32 heard;
    /* 0x7484 */ u8 pad7484[0x7488 - 0x7484];
} Unk80383E70;

extern Unk80383E70 lbl_80383E70;
extern u8 lbl_804EE6F2;
extern u8 lbl_804EE6F3;
extern u8 lbl_804EE6F4[6];
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

void fn_80033F64(Unk80033F64* obj, s32 mode) {
    switch (obj->stage) {
    case 0:
        lbl_804EE6F4[0] = 8;
        lbl_804EE6F4[1] = 8;
        lbl_804EE6F4[2] = 0xb;
        lbl_804EE6F4[3] = 0xe;
        lbl_804EE6F4[4] = 0xd;
        lbl_804EE6F4[5] = 4;
        lbl_804EE6F2 = lbl_802643B0[0].unk1;
        lbl_804EE6F3 = lbl_802643D4[0].unk1;
        break;
    case 1:
        lbl_804EE6F4[0] = 8;
        lbl_804EE6F4[1] = 8;
        lbl_804EE6F4[2] = 0xb;
        lbl_804EE6F4[3] = 0xe;
        lbl_804EE6F4[4] = 0xd;
        lbl_804EE6F4[5] = 4;
        lbl_804EE6F2 = lbl_802643B0[1].unk1;
        lbl_804EE6F3 = lbl_802643D4[1].unk1;
        break;
    case 2:
        lbl_804EE6F4[0] = 0xf;
        lbl_804EE6F4[1] = 7;
        lbl_804EE6F4[2] = 0x10;
        lbl_804EE6F4[3] = 0xf;
        lbl_804EE6F4[4] = 0xd;
        lbl_804EE6F4[5] = 4;
        lbl_804EE6F2 = lbl_802643B0[2].unk1;
        lbl_804EE6F3 = lbl_802643D4[2].unk1;
        break;
    case 3:
        lbl_804EE6F4[0] = 0xb;
        lbl_804EE6F4[1] = 8;
        lbl_804EE6F4[2] = 0xb;
        lbl_804EE6F4[3] = 0xe;
        lbl_804EE6F4[4] = 0xd;
        lbl_804EE6F4[5] = 6;
        lbl_804EE6F2 = lbl_802643B0[3].unk1;
        lbl_804EE6F3 = lbl_802643D4[3].unk1;
        break;
    case 4:
        lbl_804EE6F4[0] = 0xd;
        lbl_804EE6F4[1] = 0xe;
        lbl_804EE6F4[2] = 0xf;
        lbl_804EE6F4[3] = 0x10;
        lbl_804EE6F4[4] = 0xf;
        lbl_804EE6F4[5] = 4;
        lbl_804EE6F2 = lbl_802643B0[4].unk1;
        lbl_804EE6F3 = lbl_802643D4[4].unk1;
        break;
    case 5:
        lbl_804EE6F4[0] = 0xd;
        lbl_804EE6F4[1] = 6;
        lbl_804EE6F4[2] = 0xd;
        lbl_804EE6F4[3] = 0xe;
        lbl_804EE6F4[4] = 0x11;
        lbl_804EE6F4[5] = 5;
        lbl_804EE6F2 = lbl_802643B0[5].unk1;
        lbl_804EE6F3 = lbl_802643D4[5].unk1;
        break;
    }
    if (mode == 0) {
        fn_8000ECB8(0x38, Font(), 5, 0, 1);
        fn_8000ECB8(0x38, Font(), 0xE, lbl_804EE6F2, lbl_804EE6F3);
        fn_8000ECB8(0x38, Font(), 0xF, lbl_804EE6F2, (u8)(lbl_804EE6F3 + 2));
        fn_8000ECB8(0x38, Font(), 0x10, lbl_804EE6F2, (u8)(lbl_804EE6F3 + 4));
        if (lbl_80383E70.heard & 8) {
            fn_8000ECB8(0x38, Font(), 0x11, lbl_804EE6F2, (u8)(lbl_804EE6F3 + 6));
        } else {
            fn_8000ECB8(0x38, Font(), 2, lbl_804EE6F2, (u8)(lbl_804EE6F3 + 6));
        }
        if ((lbl_80383E70.heard & 1) || (lbl_80383E70.heard & 2) || (lbl_80383E70.heard & 4)) {
            fn_8000ECB8(0x38, Font(), 0x12, lbl_804EE6F2, (u8)(lbl_804EE6F3 + 8));
        } else {
            fn_8000ECB8(0x38, Font(), 2, lbl_804EE6F2, (u8)(lbl_804EE6F3 + 8));
        }
        fn_8000ECB8(0x38, Font(), 3, lbl_804EE6F2, (u8)(lbl_804EE6F3 + 10));
    } else {
        Row(lbl_804EE6F2, lbl_804EE6F3, lbl_804EE6F4[0]);
        Row(lbl_804EE6F2, lbl_804EE6F3 + 2, lbl_804EE6F4[1]);
        Row(lbl_804EE6F2, lbl_804EE6F3 + 4, lbl_804EE6F4[2]);
        if (lbl_80383E70.heard & 8) {
            Row(lbl_804EE6F2, lbl_804EE6F3 + 6, lbl_804EE6F4[3]);
        } else {
            Row(lbl_804EE6F2, lbl_804EE6F3 + 6, 8);
        }
        if ((lbl_80383E70.heard & 1) || (lbl_80383E70.heard & 2) || (lbl_80383E70.heard & 4)) {
            Row(lbl_804EE6F2, lbl_804EE6F3 + 8, lbl_804EE6F4[4]);
        } else {
            Row(lbl_804EE6F2, lbl_804EE6F3 + 8, 8);
        }
        Row(lbl_804EE6F2, lbl_804EE6F3 + 10, lbl_804EE6F4[5]);
    }
}
