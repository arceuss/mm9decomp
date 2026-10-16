#include "game/work_8031BF70.h"

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x26BC];
    /* 0x26BC */ s16 unk26BC;
} Unk8038B2F8;

extern Unk8038B2F8 lbl_8038B2F8;

void fn_800A1DB4(void) {
    lbl_8038B2F8.unk26BC = 0;
    lbl_8031BF70.unk4CEDC = 0;
    lbl_8031BF70.unk4CEE0 = 0;
    lbl_8031BF70.unk4CEE4 = 0;
}
