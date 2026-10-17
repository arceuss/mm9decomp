#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3008];
    /* 0x3008 */ u8* unk3008;
} Unk80316D78;

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x2018];
    /* 0x2018 */ u8 unk2018[0x7480 - 0x2018];
    /* 0x7480 */ u32 heard;
    /* 0x7484 */ u8 pad7484[0x7488 - 0x7484];
} Unk80383E70;

extern Unk80316D78 lbl_80316D78;
extern Unk80383E70 lbl_80383E70;
extern u8 lbl_804ECE1C;
extern u8 lbl_804ECE1D;
extern u8 lbl_804ECE1E;
extern u8 lbl_804ECE1F;
extern u32 lbl_8036CF50[];
extern u8 lbl_8026F9B8[];

void OSFatal(void*, void*, void*);
s32 fn_80026DD8(u8* buf, u32 size, s32 arg2);
void fn_8002701C(u32 code, u32 game);
s32 fn_80027090(u8 slot, s32 kind);
s32 fn_801E201C(u32 code, u32 game, s32 slot, void* info, void* out);
s32 fn_801E2648(void* info);
void fn_800AAFB0(void* info, s32 arg1);
s32 fn_800AB27C(s32 err);
void fn_80026EDC(void);

static inline void Fatal(void) {
    u8 fg[4];
    u32 bg = 0;

    fg[0] = lbl_804ECE1C;
    fg[1] = lbl_804ECE1D;
    fg[2] = lbl_804ECE1E;
    fg[3] = lbl_804ECE1F;
    OSFatal(fg, &bg, *(void**)(lbl_8026F9B8 + lbl_8036CF50[0] * 0x24 + 0x10));
}

static inline void Check(s32 r) {
    switch (r) {
    case -0x1395:
        Fatal();
        break;
    case -0x1394:
        Fatal();
        break;
    default:
        fn_800AB27C(r);
        break;
    }
}

void fn_800AAD68(void) {
    u8 info[0x30];
    u32 bit;
    s32 i;

    if (fn_80026DD8(lbl_80316D78.unk3008 + 0x2819000, 0x400000, 0) == 0) {
        return;
    }
    fn_8002701C(0x10005, 0x77523945);
    for (i = 0; i < 5; i++) {
        bit = 1 << i;
        if (!(lbl_80383E70.heard & bit) && fn_80027090(i + 1, 1) && fn_80027090(i + 1, 2)) {
            Check(fn_801E201C(0x10005, 0x77523945, i + 1, info, lbl_80383E70.unk2018));
            fn_800AAFB0(info, 1);
            Check(fn_801E2648(info));
            lbl_80383E70.heard |= bit;
        }
    }
    fn_80026EDC();
}
