#include "types.h"

// 0x200 bytes of list heads (bucket[4][32]), then bookkeeping.
typedef struct Unk800E695C {
    /* 0x000 */ void* buckets[4][32];
    /* 0x200 */ void* (*cur)[32];
    /* 0x204 */ void* unk204;
    /* 0x208 */ s32 unk208;
} Unk800E695C;

void fn_800E69C4(Unk800E695C* work, void** node, s32 layer, s32 index) {
    *node = work->cur[layer][index];
    work->cur[layer][index] = node;
}
