#include "types.h"

typedef struct Unk800B2B18 {
    /* 0x000 */ u8 pad0[0xF5];
    /* 0x0F5 */ u8 unkF5;
    /* 0x0F6 */ u8 padF6[0x152 - 0xF6];
    /* 0x152 */ u16 energy[4];
    /* 0x15A */ u8 pad15A[0x1F8 - 0x15A];
    /* 0x1F8 */ u8 shots;
} Unk800B2B18;

typedef struct Unk804EE8C0 {
    /* 0x0 */ u8 pad0[0xA];
    /* 0xA */ s16 unkA;
} Unk804EE8C0;

extern Unk804EE8C0* lbl_804EE8C0;
extern void* lbl_8027E708[4];

BOOL fn_800BF8E4(Unk800B2B18* p, void* data, s32 arg2, s32 arg3, s32 arg4);

s32 fn_800B2B18(Unk800B2B18* p) {
    s32 energy;
    void* data;

    if ((u32)(1 - p->shots) >= 1 && (u32)lbl_804EE8C0->unkA >= 5) {
        energy = p->energy[3];
        data = lbl_8027E708[p->unkF5];
        if (energy - 0x700 >= 0 && fn_800BF8E4(p, data, 0, 1, 5)) {
            p->energy[3] = energy - 0x700;
            return 8;
        }
    }
    return -1;
}
