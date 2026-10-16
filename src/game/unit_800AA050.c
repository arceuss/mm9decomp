#include "types.h"

typedef struct Unk800AA050Entry {
    /* 0x0 */ u8 pad0[0x10];
} Unk800AA050Entry;

typedef struct Unk800AA050 {
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ Unk800AA050Entry bankA[0x60];
    /* 0x610 */ Unk800AA050Entry bankB[0x60];
    /* 0xC10 */ u8 mapA[0x280];
    /* 0xE90 */ u8 mapB[0x280];
} Unk800AA050;

void fn_800A9120(Unk800AA050* p, s32 arg1, s32 arg2, s32 arg3, u16 index, s32 arg5);

void fn_800AA050(Unk800AA050* p, s32 arg1, s32 arg2, s32 arg3, u16 index, s32 arg5) {
    Unk800AA050Entry* a;
    Unk800AA050Entry* b;

    a = p->mapA[index] != 0xFF ? &p->bankA[p->mapA[index]] : NULL;
    b = p->mapB[index] != 0xFF ? &p->bankB[p->mapB[index]] : NULL;
    if (a != NULL && b != NULL) {
        return;
    }
    if (a == NULL && b != NULL) {
        fn_800A9120(p, arg1, 0, 4, index, arg5);
        return;
    }
    if (a != NULL && b == NULL) {
        fn_800A9120(p, 0, arg2, arg3, index, arg5);
        return;
    }
    fn_800A9120(p, arg1, arg2, arg3, index, arg5);
}
