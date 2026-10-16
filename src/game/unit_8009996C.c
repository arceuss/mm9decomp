#include "types.h"

typedef struct Unk8009996C {
    /* 0x00 */ void* unk0;
    /* 0x04 */ u8 pad4[0x36 - 0x4];
    /* 0x36 */ u8 unk36;
    /* 0x37 */ u8 pad37[0x3B - 0x37];
    /* 0x3B */ u8 unk3B;
} Unk8009996C;

extern u8 lbl_80274528[];

void fn_8009996C(Unk8009996C* work, void* arg) {
    if (arg == NULL) {
        work->unk0 = lbl_80274528;
    } else {
        work->unk0 = arg;
    }
    work->unk3B = 0;
    work->unk36 = 0;
}
