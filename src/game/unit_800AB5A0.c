#include "types.h"

typedef struct Unk800AB5A0 {
    /* 0x000 */ u8 pad0[0x20];
    /* 0x020 */ u8 unk20;
    /* 0x021 */ u8 pad21[0x98 - 0x21];
} Unk800AB5A0;

extern u8 lbl_804EE982;
extern void* lbl_804EE8A0;

void fn_800E8ABC(void* pool, s8 id, void* buf, s16 stride, s16 count);

void fn_800AB5A0(void* pool, Unk800AB5A0* objs, s16 count) {
    s16 i;

    fn_800E8ABC(pool, 2, objs, sizeof(Unk800AB5A0), count);
    for (i = 0; i < count; i++) {
        objs[i].unk20 = lbl_804EE982 + i;
    }
    lbl_804EE8A0 = pool;
    lbl_804EE982 += count;
}
