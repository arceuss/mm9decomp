#include "types.h"

// 0x200 bytes of list heads (bucket[4][32]), then bookkeeping.
typedef struct Unk800E695C {
    /* 0x000 */ void* buckets[4][32];
    /* 0x200 */ void* (*cur)[32];
    /* 0x204 */ void* unk204;
    /* 0x208 */ s32 unk208;
} Unk800E695C;

void* fn_8009BECC(s32 size);
void fn_8009C04C(s32 value, void* dst, s32 size);

void fn_800E6A78(Unk800E695C* work) {
    work->cur = fn_8009BECC(sizeof(work->buckets));
    if (work->cur == NULL) {
        work->cur = work->buckets;
    }
    fn_8009C04C(0, work->cur, sizeof(work->buckets));
}
