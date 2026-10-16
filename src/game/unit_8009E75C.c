#include "game/work_8031BF70.h"

typedef struct Unk80301280_40 {
    /* 0x0 */ u32 unk0;
} Unk80301280_40;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ Unk80301280_40* unk40;
    /* 0x44 */ u8 pad44[0x48 - 0x44];
} Unk80301280;

extern Unk80301280 lbl_80301280;

void fn_800BAEE0(u32 addr);

void fn_8009E75C(void) {
    Unk8031BF70Vec view;
    u32 j;
    u32 base;
    Unk8031BF70_288* layer;
    Unk8031BF70_20* rec;
    s32 i;

    view.x = ((lbl_8031BF70.unk280 >> 8) - 0x80) << 8;
    layer = lbl_8031BF70.unk288;
    view.y = ((lbl_8031BF70.unk284 >> 8) - 0x70) << 8;
    layer->unk4->unkC(&view);
    rec = lbl_8031BF70.unk20;
    for (i = 0; i < 4; i++) {
        if (rec->unk8 != NULL) {
            rec->unk8(rec, layer);
        }
        rec++;
    }
    for (j = 0; j < 0x10; j++) {
        base = (u16)j << 9;
        fn_800BAEE0(base + 0x10004000);
        fn_800BAEE0(base + 0x10006000);
    }
    lbl_80301280.unk40->unk0 &= ~0xF00;
}
