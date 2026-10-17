#include "types.h"

typedef struct Unk80033890Entry {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
} Unk80033890Entry;

typedef struct Unk80033890 {
    /* 0x000 */ u8 pad0[0x28A];
    /* 0x28A */ u8 stage;
} Unk80033890;

extern Unk80033890Entry lbl_802643B0[];
extern Unk80033890Entry lbl_802643D4[];
extern u8 lbl_80316D78[];
extern u8 lbl_804EE6E8;
extern u8 lbl_804EE6E9;
extern u8 lbl_804EE6EC[6];
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

void fn_80033890(Unk80033890* obj, s32 mode) {
    switch (obj->stage) {
    case 0:
        lbl_804EE6EC[0] = 0xa;
        lbl_804EE6EC[1] = 0xf;
        lbl_804EE6EC[2] = 8;
        lbl_804EE6EC[3] = 7;
        lbl_804EE6EC[4] = 0x14;
        lbl_804EE6EC[5] = 4;
        lbl_804EE6E8 = lbl_802643B0[0].unk0;
        lbl_804EE6E9 = lbl_802643D4[0].unk0;
        break;
    case 1:
        lbl_804EE6EC[0] = 0xa;
        lbl_804EE6EC[1] = 0xf;
        lbl_804EE6EC[2] = 8;
        lbl_804EE6EC[3] = 7;
        lbl_804EE6EC[4] = 0x14;
        lbl_804EE6EC[5] = 4;
        lbl_804EE6E8 = lbl_802643B0[1].unk0;
        lbl_804EE6E9 = lbl_802643D4[1].unk0;
        break;
    case 2:
        lbl_804EE6EC[0] = 0xf;
        lbl_804EE6EC[1] = 0xf;
        lbl_804EE6EC[2] = 0xb;
        lbl_804EE6EC[3] = 7;
        lbl_804EE6EC[4] = 0x16;
        lbl_804EE6EC[5] = 4;
        lbl_804EE6E8 = lbl_802643B0[2].unk0;
        lbl_804EE6E9 = lbl_802643D4[2].unk0;
        break;
    case 3:
        lbl_804EE6EC[0] = 0xe;
        lbl_804EE6EC[1] = 0xf;
        lbl_804EE6EC[2] = 0xa;
        lbl_804EE6EC[3] = 8;
        lbl_804EE6EC[4] = 0x17;
        lbl_804EE6EC[5] = 9;
        lbl_804EE6E8 = lbl_802643B0[3].unk0;
        lbl_804EE6E9 = lbl_802643D4[3].unk0;
        break;
    case 4:
        lbl_804EE6EC[0] = 0xb;
        lbl_804EE6EC[1] = 0xf;
        lbl_804EE6EC[2] = 0xb;
        lbl_804EE6EC[3] = 7;
        lbl_804EE6EC[4] = 0x15;
        lbl_804EE6EC[5] = 4;
        lbl_804EE6E8 = lbl_802643B0[4].unk0;
        lbl_804EE6E9 = lbl_802643D4[4].unk0;
        break;
    case 5:
        lbl_804EE6EC[0] = 0xf;
        lbl_804EE6EC[1] = 0xe;
        lbl_804EE6EC[2] = 0xd;
        lbl_804EE6EC[3] = 8;
        lbl_804EE6EC[4] = 0x17;
        lbl_804EE6EC[5] = 5;
        lbl_804EE6E8 = lbl_802643B0[5].unk0;
        lbl_804EE6E9 = lbl_802643D4[5].unk0;
        break;
    }
    if (mode == 0) {
        fn_8000ECB8(0x38, Font(), 4, 0, 1);
        fn_8000ECB8(0x38, Font(), 0xA, lbl_804EE6E8, lbl_804EE6E9);
        fn_8000ECB8(0x38, Font(), 0xB, lbl_804EE6E8, (u8)(lbl_804EE6E9 + 2));
        fn_8000ECB8(0x38, Font(), 0xC, lbl_804EE6E8, (u8)(lbl_804EE6E9 + 4));
        fn_8000ECB8(0x38, Font(), 0xD, lbl_804EE6E8, (u8)(lbl_804EE6E9 + 6));
        fn_8000ECB8(0x38, Font(), 0x1C, lbl_804EE6E8, (u8)(lbl_804EE6E9 + 8));
        fn_8000ECB8(0x38, Font(), 3, lbl_804EE6E8, (u8)(lbl_804EE6E9 + 10));
    } else {
        Row(lbl_804EE6E8, lbl_804EE6E9, lbl_804EE6EC[0]);
        Row(lbl_804EE6E8, lbl_804EE6E9 + 2, lbl_804EE6EC[1]);
        Row(lbl_804EE6E8, lbl_804EE6E9 + 4, lbl_804EE6EC[2]);
        Row(lbl_804EE6E8, lbl_804EE6E9 + 6, lbl_804EE6EC[3]);
        Row(lbl_804EE6E8, lbl_804EE6E9 + 8, lbl_804EE6EC[4]);
        Row(lbl_804EE6E8, lbl_804EE6E9 + 10, lbl_804EE6EC[5]);
    }
}
