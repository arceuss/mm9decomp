#include "types.h"

typedef struct Unk800B28AC {
    /* 0x000 */ u8 pad0[0xF5];
    /* 0x0F5 */ u8 unkF5;
    /* 0x0F6 */ u8 padF6[0x152 - 0xF6];
    /* 0x152 */ u16 energy[4];
    /* 0x15A */ u8 pad15A[0x1F8 - 0x15A];
    /* 0x1F8 */ u8 shots;
} Unk800B28AC;

typedef struct Unk804EE8C0 {
    /* 0x0 */ u8 pad0[0xA];
    /* 0xA */ s16 unkA;
} Unk804EE8C0;

extern Unk804EE8C0* lbl_804EE8C0;
extern void* lbl_8027E6F8[4];

BOOL fn_800BEA7C(Unk800B28AC* p, void* data, s32 arg2, s32 arg3, s32 arg4);

s32 fn_800B28AC(Unk800B28AC* p) {
    s32 energy;
    void* data;

    if ((u32)(1 - p->shots) >= 1 && (u32)lbl_804EE8C0->unkA >= 5) {
        energy = p->energy[2];
        data = lbl_8027E6F8[p->unkF5];
        if (energy - 0x400 >= 0 && fn_800BEA7C(p, data, 0, 1, 4)) {
            p->energy[2] = energy - 0x400;
            return 7;
        }
    }
    return -1;
}
