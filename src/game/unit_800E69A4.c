#include "types.h"

// 0x200 bytes of list heads (bucket[4][32]), then bookkeeping.
typedef struct Unk800E695C {
    /* 0x000 */ void* buckets[4][32];
    /* 0x200 */ void* (*cur)[32];
    /* 0x204 */ void* unk204;
    /* 0x208 */ s32 unk208;
} Unk800E695C;

void fn_800E69A4(Unk800E695C* work, void* arg) {
    work->unk204 = arg;
}
