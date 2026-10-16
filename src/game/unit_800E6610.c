#include "types.h"

// One game thread: OSThread (0x318), its 0x4000-byte stack, then bookkeeping.
typedef struct Unk8038E7C0Thread {
    /* 0x0000 */ u8 thread[0x318];
    /* 0x0318 */ u8 stack[0x4000];
    /* 0x4318 */ void* (*func)(void*);
    /* 0x431C */ u8 pad431C[0x4320 - 0x431C];
    /* 0x4320 */ u8 unk4320;
    /* 0x4321 */ u8 unk4321;
    /* 0x4322 */ u8 pad4322[0x4324 - 0x4322];
    /* 0x4324 */ u8 unk4324[4];
    /* 0x4328 */ s16 unk4328[4];
} Unk8038E7C0Thread;

typedef struct Unk8038E7C0 {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ u8 unk4[0x10 - 0x4];
    /* 0x0010 */ Unk8038E7C0Thread threads[3];
} Unk8038E7C0;

extern Unk8038E7C0 lbl_8038E7C0;

Unk8038E7C0Thread* fn_800F8DD4(void* arg);
void OSSleepThread(void* queue);

void fn_800E6610(s32 arg) {
    Unk8038E7C0Thread* t = fn_800F8DD4(NULL);

    if (t != NULL) {
        t->unk4321 = 8;
    }
    OSSleepThread(lbl_8038E7C0.unk4);
}
