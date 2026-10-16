#include "types.h"
#include "game/work_8031BF70.h"

typedef struct Unk800A5148Rect {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} Unk800A5148Rect;

void fn_800A5148(s32 id, u16 arg1, Unk8031BF70Vec* base, Unk800A5148Rect* rect) {
    u8 n = lbl_8031BF70.unk28E;
    Unk8031BF70_290* rec;
    s32 i;

    if (n + 1 >= 32) {
        return;
    }
    lbl_8031BF70.unk28E = n + 1;
    rec = &lbl_8031BF70.unk290[n];
    rec->id = id;
    rec->unk2 = arg1;
    rec->unk8 = base->x + rect->x;
    rec->unkC = base->y + rect->y;
    for (i = 0; i < lbl_8031BF70.unk28F; i++) {
        if (lbl_8031BF70.unk290[32 + i].id == (u16)id) {
            break;
        }
    }
    if (i < lbl_8031BF70.unk28F) {
        lbl_8031BF70.unk290[n].unk10 = lbl_8031BF70.unk290[32 + i].unk8;
        lbl_8031BF70.unk290[n].unk14 = lbl_8031BF70.unk290[32 + i].unkC;
    } else {
        lbl_8031BF70.unk290[n].unk10 = rec->unk8;
        lbl_8031BF70.unk290[n].unk14 = rec->unkC;
    }
    lbl_8031BF70.unk290[n].unk4 = rect->w >> 1;
    lbl_8031BF70.unk290[n].unk6 = rect->h >> 1;
}
