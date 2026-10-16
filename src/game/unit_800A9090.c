#include "types.h"

typedef struct Unk800A9090Entry {
    /* 0x0 */ u8 pad0[0x10];
} Unk800A9090Entry;

typedef struct Unk800A9090 {
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ Unk800A9090Entry bankA[0x60];
    /* 0x610 */ Unk800A9090Entry bankB[0x60];
    /* 0xC10 */ u8 mapA[0x280];
    /* 0xE90 */ u8 mapB[0x280];
} Unk800A9090;

void fn_800A8B28(Unk800A9090* p, void* src, u16 index, u16 arg3, s32 arg4, s32 arg5, s32 arg6);

void fn_800A9090(Unk800A9090* p, void* src, u16 index, u16 arg3, s32 arg4, s32 arg5, s32 arg6) {
    Unk800A9090Entry* a;
    Unk800A9090Entry* b;

    a = p->mapA[index] != 0xFF ? &p->bankA[p->mapA[index]] : NULL;
    b = p->mapB[index] != 0xFF ? &p->bankB[p->mapB[index]] : NULL;
    if (a != NULL && b != NULL) {
        return;
    }
    if (a == NULL && b != NULL) {
        fn_800A8B28(p, src, index, arg3, arg4, arg5, 0);
        return;
    }
    if (a != NULL && b == NULL) {
        fn_800A8B28(p, src, index, arg3, arg4, 0, arg6);
        return;
    }
    fn_800A8B28(p, src, index, arg3, arg4, arg5, arg6);
}
