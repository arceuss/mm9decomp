#include "types.h"

typedef struct Unk800352A8Entry {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
} Unk800352A8Entry;

typedef struct Unk800352A8 {
    /* 0x000 */ u8 pad0[0x28A];
    /* 0x28A */ u8 stage;
} Unk800352A8;

extern Unk800352A8Entry lbl_802643B0[];
extern Unk800352A8Entry lbl_802643D4[];
extern u8 lbl_80316D78[];
extern u8 lbl_804EE708;
extern u8 lbl_804EE709;
extern u8 lbl_804EE70C[4];
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

void fn_800352A8(Unk800352A8* obj, s32 mode) {
    switch (obj->stage) {
    case 0:
        lbl_804EE70C[0] = 5;
        lbl_804EE70C[1] = 8;
        lbl_804EE70C[2] = 5;
        lbl_804EE70C[3] = 4;
        lbl_804EE708 = lbl_802643B0[0].unk4;
        lbl_804EE709 = lbl_802643D4[0].unk4;
        break;
    case 1:
        lbl_804EE70C[0] = 5;
        lbl_804EE70C[1] = 8;
        lbl_804EE70C[2] = 5;
        lbl_804EE70C[3] = 4;
        lbl_804EE708 = lbl_802643B0[1].unk4;
        lbl_804EE709 = lbl_802643D4[1].unk4;
        break;
    case 2:
        lbl_804EE70C[0] = 5;
        lbl_804EE70C[1] = 0xb;
        lbl_804EE70C[2] = 6;
        lbl_804EE70C[3] = 4;
        lbl_804EE708 = lbl_802643B0[2].unk4;
        lbl_804EE709 = lbl_802643D4[2].unk4;
        break;
    case 3:
        lbl_804EE70C[0] = 5;
        lbl_804EE70C[1] = 0xa;
        lbl_804EE70C[2] = 6;
        lbl_804EE70C[3] = 6;
        lbl_804EE708 = lbl_802643B0[3].unk4;
        lbl_804EE709 = lbl_802643D4[3].unk4;
        break;
    case 4:
        lbl_804EE70C[0] = 5;
        lbl_804EE70C[1] = 0xb;
        lbl_804EE70C[2] = 6;
        lbl_804EE70C[3] = 4;
        lbl_804EE708 = lbl_802643B0[4].unk4;
        lbl_804EE709 = lbl_802643D4[4].unk4;
        break;
    case 5:
        lbl_804EE70C[0] = 6;
        lbl_804EE70C[1] = 0xd;
        lbl_804EE70C[2] = 6;
        lbl_804EE70C[3] = 5;
        lbl_804EE708 = lbl_802643B0[5].unk4;
        lbl_804EE709 = lbl_802643D4[5].unk4;
        break;
    }
    if (mode == 0) {
        fn_8000ECB8(0x38, Font(), 8, 0, 1);
        fn_8000ECB8(0x38, Font(), 0x17, lbl_804EE708, lbl_804EE709);
        fn_8000ECB8(0x38, Font(), 0xC, lbl_804EE708, (u8)(lbl_804EE709 + 2));
        fn_8000ECB8(0x38, Font(), 0x1F, lbl_804EE708, (u8)(lbl_804EE709 + 4));
        fn_8000ECB8(0x38, Font(), 3, lbl_804EE708, (u8)(lbl_804EE709 + 6));
    } else {
        Row(lbl_804EE708, lbl_804EE709, lbl_804EE70C[0]);
        Row(lbl_804EE708, lbl_804EE709 + 2, lbl_804EE70C[1]);
        Row(lbl_804EE708, lbl_804EE709 + 4, lbl_804EE70C[2]);
        Row(lbl_804EE708, lbl_804EE709 + 6, lbl_804EE70C[3]);
    }
}
