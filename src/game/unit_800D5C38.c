#include "types.h"

typedef struct Unk8038E038Item {
    /* 0x00 */ u8 pad0[0x38];
    /* 0x38 */ u8 unk38;
} Unk8038E038Item;

typedef struct Unk8038E038 {
    /* 0x000 */ Unk8038E038Item* lists[3][4];
    /* 0x030 */ u32 counts[3];
    /* 0x03C */ u8 mutex[0x108 - 0x3C];
} Unk8038E038;

extern Unk8038E038 lbl_8038E038;

void OSLockMutex(void* mutex);
void OSUnlockMutex(void* mutex);

void fn_800D5C38(s32 list, Unk8038E038Item* item, u8 value) {
    u32 n;

    OSLockMutex(lbl_8038E038.mutex);
    n = lbl_8038E038.counts[list];
    if (n + 1 <= 4) {
        item->unk38 = value;
        lbl_8038E038.lists[list][n] = item;
        lbl_8038E038.counts[list] = n + 1;
    }
    OSUnlockMutex(lbl_8038E038.mutex);
}
