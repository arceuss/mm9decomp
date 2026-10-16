#include "types.h"

typedef struct Unk8038B2F8_184 {
    /* 0x0000 */ u8 pad0[0x2500];
    /* 0x2500 */ u8 unk2500;
} Unk8038B2F8_184;

typedef struct Unk8038B2F8 {
    /* 0x000 */ u8 pad0[0x184];
    /* 0x184 */ Unk8038B2F8_184* unk184;
} Unk8038B2F8;

typedef struct Unk8003BE3C {
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ s16 timer;
    /* 0x00A */ u8 padA[0x26C - 0xA];
    /* 0x26C */ u8 state;
} Unk8003BE3C;

extern Unk8038B2F8 lbl_8038B2F8;

void fn_8003BE3C(Unk8003BE3C* work) {
    lbl_8038B2F8.unk184->unk2500 = work->timer;
    if (work->timer > 0) {
        work->timer--;
    } else {
        work->state = 2;
    }
}
