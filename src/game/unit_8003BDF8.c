#include "types.h"

typedef struct Unk2500 {
    /* 0x0000 */ u8 pad0000[0x2500];
    /* 0x2500 */ u8 unk2500;
} Unk2500;

typedef struct Unk8038B2F8 {
    /* 0x000 */ u8 pad000[0x184];
    /* 0x184 */ Unk2500* unk184;
} Unk8038B2F8;

typedef struct Unk3BDF8 {
    /* 0x000 */ u8 pad000[8];
    /* 0x008 */ s16 unk8;
    /* 0x00A */ u8 pad00A[0x26C - 0x00A];
    /* 0x26C */ u8 unk26C;
} Unk3BDF8;

extern Unk8038B2F8 lbl_8038B2F8;

void fn_8003BDF8(Unk3BDF8* o) {
    lbl_8038B2F8.unk184->unk2500 = o->unk8;
    if (o->unk8 < 0x20) {
        o->unk8 = o->unk8 + 1;
        return;
    }
    lbl_8038B2F8.unk184->unk2500 = 0x20;
    o->unk26C = 3;
}
