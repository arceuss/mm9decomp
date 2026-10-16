#include "types.h"

typedef struct Unk8000EF50 {
    /* 0x000 */ u8 pad0[0x20];
    /* 0x020 */ u8 unk20;
    /* 0x021 */ u8 pad21[0x108 - 0x21];
} Unk8000EF50;

extern u8 lbl_804EE982;
extern void* lbl_804EE664;
extern u8 lbl_804EE661;
extern u8 lbl_804EE660;

void fn_800E8ABC(void* pool, s8 id, void* buf, s16 stride, s16 count);

void fn_8000EF50(void* pool, Unk8000EF50* objs, s16 count) {
    s16 i;

    fn_800E8ABC(pool, 5, objs, sizeof(Unk8000EF50), count);
    for (i = 0; i < count; i++) {
        objs[i].unk20 = lbl_804EE982 + i;
    }
    lbl_804EE664 = pool;
    lbl_804EE982 += count;
    lbl_804EE661 = 0;
    lbl_804EE660 = 0;
}
