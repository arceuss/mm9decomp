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

void fn_800F615C(void* mutex);
void fn_800F6238(void* mutex);

extern const u8 lbl_804ED30C[4];

s32 fn_800E66A8(Unk8038E038Item* item);

void fn_800D5B90(Unk8038E038Item* item, u8 value) {
    s32 kind = fn_800E66A8(item);
    s32 list;
    u32 n;

    if (kind == 3) {
        return;
    }
    list = lbl_804ED30C[kind];
    fn_800F615C(lbl_8038E038.mutex);
    n = lbl_8038E038.counts[list];
    if (n + 1 <= 4) {
        item->unk38 = value;
        lbl_8038E038.lists[list][n] = item;
        lbl_8038E038.counts[list] = n + 1;
    }
    fn_800F6238(lbl_8038E038.mutex);
}
