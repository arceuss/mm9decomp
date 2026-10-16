#include "types.h"

typedef struct Unk800B37C8 {
    /* 0x000 */ u8 pad0[0xF5];
    /* 0x0F5 */ u8 unkF5;
    /* 0x0F6 */ u8 padF6[0x152 - 0xF6];
    /* 0x152 */ u16 energy[9];
    /* 0x164 */ u8 pad164[0x1F8 - 0x164];
    /* 0x1F8 */ u8 shots;
    /* 0x1F9 */ u8 unk1F9;
} Unk800B37C8;

typedef struct Unk804EE8C0 {
    /* 0x0 */ u8 pad0[0xA];
    /* 0xA */ s16 unkA;
} Unk804EE8C0;

extern Unk804EE8C0* lbl_804EE8C0;
extern void* lbl_8027E758[4];
extern Unk804EE8C0* lbl_804EE8F8;
extern void* lbl_804EE8B8[2];

BOOL fn_800C5108(Unk800B37C8* p, s32 arg1);
BOOL fn_800BBC28(Unk800B37C8* p, void* data, void* arg2, s32 arg3, s32 arg4);

s32 fn_800B37C8(Unk800B37C8* p) {
    if (p->unk1F9 == 0 && p->energy[8] - 8 >= 0 && (u32)lbl_804EE8C0->unkA >= 1 && fn_800C5108(p, 10)) {
        return 14;
    }
    if ((u32)(3 - p->shots) >= 1 && (u32)lbl_804EE8C0->unkA >= 1 && fn_800BBC28(p, lbl_8027E758[p->unkF5], lbl_804EE8B8[1], 1, 10)) {
        return 15;
    }
    return -1;
}
