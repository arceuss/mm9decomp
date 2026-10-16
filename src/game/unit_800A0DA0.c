#include "types.h"
#include "game/work_8031BF70.h"

typedef struct Unk800A0DA0 {
    /* 0x0 */ u8 pad0[0xE];
    /* 0xE */ u8 step;
} Unk800A0DA0;

extern u8 lbl_804ECDEC[4];
extern void* lbl_804EE984;

void fn_800B60CC(void* player, s32 speed);

static inline u32 Zone(u32 d) {
    u32 n;

    if ((s32)d <= 0) {
        return 1;
    }
    if ((s32)d >= 0xC000) {
        return 0;
    }
    n = 2 - d / 0x6000;
    return n - 1;
}

void fn_800A0DA0(Unk800A0DA0* task) {
    u32 d;
    u32 index;

    if (task->step == 0) {
        task->step++;
    }
    d = lbl_8031BF70.unk284 + 0x6000;
    d -= 0x30000;
    d += 0x6000;
    index = Zone(d);
    lbl_8031BF70.unk4CEE0 = lbl_804ECDEC[index];
    if (index < 1) {
        lbl_8031BF70.unk4CEE4 = 2;
    } else {
        lbl_8031BF70.unk4CEE4 = 1;
    }
    if (lbl_8031BF70.unk284 < 0x2A000) {
        lbl_8031BF70.unk4CEEC = -0x80;
    } else {
        lbl_8031BF70.unk4CEEC = 0x80;
    }
    fn_800B60CC(lbl_804EE984, lbl_8031BF70.unk4CEEC);
}
