#include "types.h"

typedef struct Unk80301388 {
    /* 0x00 */ u8 mutex[0x18];
    /* 0x18 */ void* heap;
    /* 0x1C */ void* unk1C;
    /* 0x20 */ void* unk20;
    /* 0x24 */ void* unk24;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u16 flags;
    /* 0x2C */ void* unk2C;
    /* 0x30 */ void* unk30;
} Unk80301388;

extern Unk80301388 lbl_80301388;

void OSLockMutex(void* mutex);
void fn_80116038(void* heap, void* block);
void OSUnlockMutex(void* mutex);
void fn_8002541C(void* block);
void fn_8024C6F0(void);
void fn_80115F58(void* heap);

static inline void Free(void* block) {
    if (block != NULL) {
        if (!(lbl_80301388.flags & 1)) {
            OSLockMutex(&lbl_80301388);
            fn_80116038(lbl_80301388.heap, block);
            OSUnlockMutex(&lbl_80301388);
        } else {
            fn_8002541C(block);
        }
    }
}

void fn_80026EDC(void) {
    Free(lbl_80301388.unk20);
    Free(lbl_80301388.unk24);
    Free(lbl_80301388.unk2C);
    lbl_80301388.unk20 = NULL;
    lbl_80301388.unk28 = 0;
    lbl_80301388.unk24 = NULL;
    lbl_80301388.unk29 = 0;
    lbl_80301388.unk2C = NULL;
    lbl_80301388.unk30 = NULL;
    if (!(lbl_80301388.flags & 1)) {
        fn_8024C6F0();
        fn_80115F58(lbl_80301388.heap);
    }
}
