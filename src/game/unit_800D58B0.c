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

void fn_800F6124(Unk8038E038Mutex* mutex);
void fn_800F615C(Unk8038E038Mutex* mutex);
void fn_800F6238(Unk8038E038Mutex* mutex);

extern u8 lbl_804ED30C[4];

s32 fn_800E66A8(void);

void fn_800D58B0(void) {
    s32 chan = fn_800E66A8();
    s32 index;

    if (chan != 3) {
        index = lbl_804ED30C[chan];
        fn_800F615C(&lbl_8038E038.unk3C);
        lbl_8038E038.unk30[index] = 0;
        fn_800F6238(&lbl_8038E038.unk3C);
    }
}
