#include "types.h"

typedef struct Unk800B34FC {
    /* 0x000 */ u8 pad0[0xF5];
    /* 0x0F5 */ u8 unkF5;
    /* 0x0F6 */ u8 padF6[0x152 - 0xF6];
    /* 0x152 */ u16 energy[8];
    /* 0x162 */ u8 pad162[0x1F8 - 0x162];
    /* 0x1F8 */ u8 shots;
    /* 0x1F9 */ u8 unk1F9;
} Unk800B34FC;

typedef struct Unk804EE8C0 {
    /* 0x0 */ u8 pad0[0xA];
    /* 0xA */ s16 unkA;
} Unk804EE8C0;

extern Unk804EE8C0* lbl_804EE8C0;
extern void* lbl_8027E748[4];
extern Unk804EE8C0* lbl_804EE8F8;
extern void* lbl_804EE8B0[2];

BOOL fn_800C3F60(Unk800B34FC* p, s32 arg1);
BOOL fn_800BBC28(Unk800B34FC* p, void* data, void* arg2, s32 arg3, s32 arg4);

s32 fn_800B34FC(Unk800B34FC* p) {
    if (p->unk1F9 == 0 && p->energy[7] - 0x200 >= 0 && (u32)lbl_804EE8F8->unkA >= 1 && fn_800C3F60(p, 9)) {
        return 12;
    }
    if ((u32)(3 - p->shots) >= 1 && (u32)lbl_804EE8C0->unkA >= 1 && fn_800BBC28(p, lbl_8027E748[p->unkF5], lbl_804EE8B0[1], 1, 9)) {
        return 13;
    }
    return -1;
}
