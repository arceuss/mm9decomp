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

Unk8031BF70_288* fn_8009F5B8(Unk8031BF70Vec* view);
void fn_8009FC6C(Unk8031BF70_20* rec, Unk8031BF70_288* layer, Unk8031BF70Vec* view);

void fn_8009E06C(Unk8031BF70Vec* pos) {
    Unk8031BF70Vec view;
    Unk8031BF70_288* layer;
    Unk8031BF70_20* rec;
    s32 i;

    lbl_8031BF70.unk280 = pos->x;
    lbl_8031BF70.unk284 = pos->y;
    view.x = ((lbl_8031BF70.unk280 >> 8) - 0x80) << 8;
    view.y = ((lbl_8031BF70.unk284 >> 8) - 0x70) << 8;
    layer = fn_8009F5B8(&view);
    if (lbl_8031BF70.unk28C != layer->unk0) {
        lbl_8031BF70.unk28C = layer->unk0;
        lbl_80301280.unk40->unk0 = (lbl_80301280.unk40->unk0 & ~7) | layer->unk24;
        layer->unk4->unk0(&view);
    }
    layer->unk4->unk4(&view);
    rec = lbl_8031BF70.unk20;
    for (i = 0; i < 4; i++) {
        fn_8009FC6C(rec, layer, &view);
        if (rec->unk0 != NULL) {
            rec->unk0(rec, layer);
        }
        rec++;
    }
    lbl_8031BF70.unk4CED8++;
}
