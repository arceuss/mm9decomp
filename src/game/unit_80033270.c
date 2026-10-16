#include "types.h"

typedef struct Unk2500 {
    /* 0x0000 */ u8 pad0000[0x2500];
    /* 0x2500 */ u8 unk2500;
} Unk2500;

typedef struct Unk8038B2F8 {
    /* 0x000 */ u8 pad000[0x184];
    /* 0x184 */ Unk2500* unk184;
} Unk8038B2F8;

typedef struct Unk33270 {
    /* 0x000 */ u8 pad000[8];
    /* 0x008 */ s16 unk8;
    /* 0x00A */ u8 pad00A[0x26E - 0x00A];
    /* 0x26E */ u8 unk26E;
    /* 0x26F */ u8 pad26F[0x28D - 0x26F];
    /* 0x28D */ u8 unk28D;
} Unk33270;

extern Unk8038B2F8 lbl_8038B2F8;

void fn_80033270(Unk33270* o) {
    lbl_8038B2F8.unk184->unk2500 = o->unk8;
    if (o->unk8 < 0x20) {
        o->unk8 = o->unk8 + 2;
        return;
    }
    o->unk28D = 1;
    lbl_8038B2F8.unk184->unk2500 = 0x20;
    o->unk26E = 3;
}
