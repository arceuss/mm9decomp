#include "types.h"

typedef struct Unk800B2D84 {
    /* 0x000 */ u8 pad0[0xF5];
    /* 0x0F5 */ u8 unkF5;
    /* 0x0F6 */ u8 padF6[0x152 - 0xF6];
    /* 0x152 */ u16 energy[8];
    /* 0x162 */ u8 pad162[0x1F8 - 0x162];
    /* 0x1F8 */ u8 shots;
} Unk800B2D84;

typedef struct Unk804EE8C0 {
    /* 0x0 */ u8 pad0[0xA];
    /* 0xA */ s16 unkA;
} Unk804EE8C0;

extern Unk804EE8C0* lbl_804EE8C0;
extern void* lbl_8027E718[4];

BOOL fn_800C0120(Unk800B2D84* p, void* data, s32 arg2, s32 arg3, s32 arg4);

s32 fn_800B2D84(Unk800B2D84* p) {
    s32 energy;
    void* data;

    if ((u32)(3 - p->shots) >= 1 && (u32)lbl_804EE8C0->unkA >= 5) {
        energy = p->energy[4];
        data = lbl_8027E718[p->unkF5];
        if (energy - 0x80 >= 0 && fn_800C0120(p, data, 0, 1, 6)) {
            p->energy[4] = energy - 0x80;
            return 9;
        }
    }
    return -1;
}
