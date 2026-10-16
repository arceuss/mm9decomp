#include "types.h"

// One game thread: OSThread (0x318), its 0x4000-byte stack, then bookkeeping.
typedef struct Unk8038E7C0Thread {
    /* 0x0000 */ u8 thread[0x318];
    /* 0x0318 */ u8 stack[0x4000];
    /* 0x4318 */ void* (*func)(void*);
    /* 0x431C */ s32 unk431C;
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
    /* 0xC9A0 */ u8 padC9A0[0xC9A8 - 0xC9A0];
    /* 0xC9A8 */ u8 mutex[0x18];
} Unk8038E7C0;

extern Unk8038E7C0 lbl_8038E7C0;

void fn_800F6238(void* mutex);

void fn_800E65FC(void) {
    fn_800F6238(lbl_8038E7C0.mutex);
}
