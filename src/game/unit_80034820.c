#include "types.h"

typedef struct Unk80034820Entry {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
} Unk80034820Entry;

typedef struct Unk80034820 {
    /* 0x000 */ u8 pad0[0x28A];
    /* 0x28A */ u8 stage;
} Unk80034820;

extern Unk80034820Entry lbl_802643B0[];
extern Unk80034820Entry lbl_802643D4[];
extern u8 lbl_80316D78[];

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x7480];
    /* 0x7480 */ u32 heard;
    /* 0x7484 */ u8 pad7484[0x7488 - 0x7484];
} Unk80383E70;

extern Unk80383E70 lbl_80383E70;
extern u8 lbl_804EE6FA;
extern u8 lbl_804EE6FB;
extern u8 lbl_804EE6FC[4];
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

void fn_80034820(Unk80034820* obj, s32 mode) {
    switch (obj->stage) {
    case 0:
        lbl_804EE6FC[0] = 0x13;
        lbl_804EE6FC[1] = 0x16;
        lbl_804EE6FC[2] = 0x11;
        lbl_804EE6FC[3] = 4;
        lbl_804EE6FA = lbl_802643B0[0].unk2;
        lbl_804EE6FB = lbl_802643D4[0].unk2;
        break;
    case 1:
        lbl_804EE6FC[0] = 0x13;
        lbl_804EE6FC[1] = 0x16;
        lbl_804EE6FC[2] = 0x11;
        lbl_804EE6FC[3] = 4;
        lbl_804EE6FA = lbl_802643B0[1].unk2;
        lbl_804EE6FB = lbl_802643D4[1].unk2;
        break;
    case 2:
        lbl_804EE6FC[0] = 0x17;
        lbl_804EE6FC[1] = 0x16;
        lbl_804EE6FC[2] = 0x17;
        lbl_804EE6FC[3] = 4;
        lbl_804EE6FA = lbl_802643B0[2].unk2;
        lbl_804EE6FB = lbl_802643D4[2].unk2;
        break;
    case 3:
        lbl_804EE6FC[0] = 0x15;
        lbl_804EE6FC[1] = 0x17;
        lbl_804EE6FC[2] = 0x19;
        lbl_804EE6FC[3] = 6;
        lbl_804EE6FA = lbl_802643B0[3].unk2;
        lbl_804EE6FB = lbl_802643D4[3].unk2;
        break;
    case 4:
        lbl_804EE6FC[0] = 0x18;
        lbl_804EE6FC[1] = 0x17;
        lbl_804EE6FC[2] = 0x13;
        lbl_804EE6FC[3] = 4;
        lbl_804EE6FA = lbl_802643B0[4].unk2;
        lbl_804EE6FB = lbl_802643D4[4].unk2;
        break;
    case 5:
        lbl_804EE6FC[0] = 0x15;
        lbl_804EE6FC[1] = 0x17;
        lbl_804EE6FC[2] = 0x17;
        lbl_804EE6FC[3] = 5;
        lbl_804EE6FA = lbl_802643B0[5].unk2;
        lbl_804EE6FB = lbl_802643D4[5].unk2;
        break;
    }
    if (mode == 0) {
        fn_8000ECB8(0x38, Font(), 7, 0, 1);
        fn_8000ECB8(0x38, Font(), 0x14, lbl_804EE6FA, lbl_804EE6FB);
        if (lbl_80383E70.heard & 8) {
            fn_8000ECB8(0x38, Font(), 0x15, lbl_804EE6FA, (u8)(lbl_804EE6FB + 2));
        } else {
            fn_8000ECB8(0x38, Font(), 2, lbl_804EE6FA, (u8)(lbl_804EE6FB + 2));
        }
        fn_8000ECB8(0x38, Font(), 0x16, lbl_804EE6FA, (u8)(lbl_804EE6FB + 4));
        fn_8000ECB8(0x38, Font(), 3, lbl_804EE6FA, (u8)(lbl_804EE6FB + 6));
    } else {
        Row(lbl_804EE6FA, lbl_804EE6FB, lbl_804EE6FC[0]);
        Row(lbl_804EE6FA, lbl_804EE6FB + 2, lbl_804EE6FC[1]);
        Row(lbl_804EE6FA, lbl_804EE6FB + 4, lbl_804EE6FC[2]);
        Row(lbl_804EE6FA, lbl_804EE6FB + 6, lbl_804EE6FC[3]);
    }
}
