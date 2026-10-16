#include "types.h"

typedef struct Unk800B1EF8 {
    /* 0x000 */ u8 pad0[0xEF];
    /* 0x0EF */ u8 unkEF;
    /* 0x0F0 */ u8 unkF0;
    /* 0x0F1 */ u8 unkF1;
    /* 0x0F2 */ u8 savedEF;
    /* 0x0F3 */ u8 savedF0;
    /* 0x0F4 */ u8 savedF1;
    /* 0x0F5 */ u8 padF5[0x14E - 0xF5];
    /* 0x14E */ u8 pad14E[0x150 - 0x14E];
    /* 0x150 */ u16 ammo[2];
    /* 0x154 */ u8 pad154[0x1F8 - 0x154];
    /* 0x1F8 */ u8 unk1F8;
} Unk800B1EF8;

typedef struct Unk804EE8C0 {
    /* 0x0 */ u8 pad0[0xA];
    /* 0xA */ s16 unkA;
} Unk804EE8C0;

extern Unk804EE8C0* lbl_804EE8C0;

u32 fn_800B789C(Unk800B1EF8* p, s32 arg1, s32 arg2);

static inline void SetSubState(Unk800B1EF8* p, u8 state) {
    p->savedEF = p->unkEF;
    p->unkEF = state;
    p->savedF0 = p->unkF0;
    p->unkF0 = 0;
    p->savedF1 = p->unkF1;
    p->unkF1 = 0;
}

extern u16 lbl_804ECE3C;

u32 fn_800B1EF8(Unk800B1EF8* p) {
    u32 r;

    if (p->unkF0 != 0 && (r = fn_800B789C(p, 1, 0x20)) != 0xFFFFFFFF) {
        if (r == 1) {
            if (p->unkF0 != 1 && p->ammo[r - 1] >= lbl_804ECE3C && p->unk1F8 < 3 && lbl_804EE8C0->unkA != 0) {
                SetSubState(p, 3);
            }
        } else {
            SetSubState(p, 3);
        }
        return r;
    }
    return 1;
}
