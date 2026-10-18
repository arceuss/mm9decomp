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

void OSLockMutex(void* mutex);
void OSUnlockMutex(void* mutex);

BOOL fn_80196DCC(void* player);
void* fn_80197F90(void* player, u32 index);
void fn_8019A714(void* sound, s32 arg1, s32 arg2);

void fn_800D4E0C(void) {
    u32 i;

    OSLockMutex(lbl_8038DD8C.mutex);
    if (fn_80196DCC(lbl_8038DD8C.player)) {
        for (i = 0; i < lbl_8038DD8C.count; i++) {
            fn_8019A714(fn_80197F90(lbl_8038DD8C.player, i), 1, 0);
        }
    }
    OSUnlockMutex(lbl_8038DD8C.mutex);
}
