#include "types.h"

typedef struct Unk8038DD8C {
    /* 0x000 */ u8 pad0[0x154];
    /* 0x154 */ u8 player[0x18C - 0x154];
    /* 0x18C */ u32 count;
    /* 0x190 */ u8 pad190[0x23C - 0x190];
    /* 0x23C */ u8 unk23C[0x240 - 0x23C];
    /* 0x240 */ u8 mutex240[0x258 - 0x240];
    /* 0x258 */ u8 unk258[0x270 - 0x258];
    /* 0x270 */ u8 mutex[0x290 - 0x270];
    /* 0x290 */ u16 flags;
} Unk8038DD8C;

extern Unk8038DD8C lbl_8038DD8C;

void fn_800F615C(void* mutex);
void fn_800F6238(void* mutex);

BOOL fn_80196DCC(void* player);
void* fn_80197F90(void* player, u32 index);
void fn_8019A680(void* sound, s32 arg1);

void fn_800D49F8(void) {
    fn_800F615C(lbl_8038DD8C.mutex);
    if (fn_80196DCC(lbl_8038DD8C.player)) {
        fn_8019A680(fn_80197F90(lbl_8038DD8C.player, 1), 0);
    }
    fn_800F6238(lbl_8038DD8C.mutex);
}
