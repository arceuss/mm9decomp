#include "types.h"

typedef struct Unk800B2390 {
    /* 0x000 */ u8 pad0[0xF5];
    /* 0x0F5 */ u8 unkF5;
    /* 0x0F6 */ u8 padF6[0x152 - 0xF6];
    /* 0x152 */ u16 energy[4];
    /* 0x15A */ u8 pad15A[0x1F8 - 0x15A];
    /* 0x1F8 */ u8 shots;
    /* 0x1F9 */ u8 pad1F9;
    /* 0x1FA */ u8 slots;
} Unk800B2390;

typedef struct Unk804EE8C0 {
    /* 0x0 */ u8 pad0[0xA];
    /* 0xA */ s16 unkA;
} Unk804EE8C0;

extern Unk804EE8C0* lbl_804EE8C0;
extern void* lbl_8027E6D8[4];

BOOL fn_800BCEB0(Unk800B2390* p, void* data, s32 arg2, s32 arg3, s32 arg4);

s32 fn_800B2390(Unk800B2390* p) {
    s32 energy;
    void* data;
    s32 i;

    if ((u32)(3 - p->shots) >= 1 && (u32)lbl_804EE8C0->unkA >= 1) {
        data = lbl_8027E6D8[p->unkF5];
        for (i = 0; i < 3; i++) {
            if (!(p->slots & (1 << i))) {
                break;
            }
        }
        if (i < 3) {
            energy = p->energy[0];
            if (energy - 0x100 >= 0 && fn_800BCEB0(p, data, i, 1, 2)) {
                p->energy[0] = energy - 0x100;
                return 5;
            }
        }
    }
    return -1;
}
