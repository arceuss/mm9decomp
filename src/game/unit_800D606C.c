#include "types.h"

typedef struct Unk800D606CObj {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ u8 index;
    /* 0x21 */ u8 pad21[0x98 - 0x21];
} Unk800D606CObj;

extern void* lbl_804EE948;

void fn_800E8ABC(void* pool, s8 id, void* buf, s16 stride, s16 count);

void fn_800D606C(void* pool, Unk800D606CObj* objs, s16 count) {
    s16 i;

    fn_800E8ABC(pool, 0xB, objs, 0x98, count);
    for (i = 0; i < count; i++) {
        objs[i].index = i;
    }
    lbl_804EE948 = pool;
}
