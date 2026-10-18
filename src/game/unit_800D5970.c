#include "types.h"

typedef struct Unk8038E038Mutex {
    /* 0x00 */ u8 pad0[0x18];
} Unk8038E038Mutex;

typedef struct Unk8038E038 {
    /* 0x00 */ u8 pad0[0x30];
    /* 0x30 */ u32 unk30[3];
    /* 0x3C */ Unk8038E038Mutex unk3C;
} Unk8038E038;

extern Unk8038E038 lbl_8038E038;

void OSInitMutex(Unk8038E038Mutex* mutex);
void OSLockMutex(Unk8038E038Mutex* mutex);
void OSUnlockMutex(Unk8038E038Mutex* mutex);

void fn_800D5970(void) {
    lbl_8038E038.unk30[0] = 0;
    lbl_8038E038.unk30[1] = 0;
    lbl_8038E038.unk30[2] = 0;
    OSInitMutex(&lbl_8038E038.unk3C);
}
