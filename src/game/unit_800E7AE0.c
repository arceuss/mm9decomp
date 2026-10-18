#include "types.h"

typedef struct Unk800E7AE0Ent {
    /* 0x0 */ struct {
        u32 pad : 24;
        u32 sx : 3;
        u32 pad2 : 3;
        u32 layer : 2;
    } fmt;
    /* 0x4 */ struct {
        u32 a : 10;
        u32 b : 10;
        u32 c : 1;
        u32 d : 1;
        u32 once : 1;
        u32 kind : 3;
        u32 pad2 : 6;
    } pos;
} Unk800E7AE0Ent;

typedef struct Unk8037C428 {
    /* 0x000 */ u8 pad0[0x808];
    /* 0x808 */ Unk800E7AE0Ent* end;
    /* 0x80C */ Unk800E7AE0Ent* begin;
} Unk8037C428;

typedef struct Unk803B9308 {
    /* 0x0 */ u32 count;
    /* 0x4 */ u32 max;
    /* 0x8 */ u8 slots[1][0x20];
} Unk803B9308;

extern Unk8037C428 lbl_8037C428;
extern Unk803B9308 lbl_803B9308;
extern void (*lbl_804ED400[2])(Unk800E7AE0Ent* e, void* slot);

void fn_800E7AE0(u32 x, u32 layer) {
    u8* slot = lbl_803B9308.slots[0];
    Unk800E7AE0Ent* e;
    u32 max = lbl_803B9308.max;
    s32 one = 1;

    for (e = lbl_8037C428.begin; e < lbl_8037C428.end; slot += 0x20, e++) {
        if (layer == e->fmt.layer && x - (e->pos.a - ((e->pos.a & 0x200) << 1)) < (one << (e->fmt.sx + 3))) {
            if (max != 0 && e->pos.once) {
                if (lbl_803B9308.count >= max) {
                    continue;
                }
                lbl_803B9308.count++;
            }
            lbl_804ED400[e->pos.kind](e, slot);
        }
    }
}
