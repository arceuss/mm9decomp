#include "types.h"

typedef struct Unk80011558 {
    /* 0x00 */ u8 pad00[0x0A];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[0x11 - 0x0B];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x88 - 0x17];
} Unk80011558;

extern u8 lbl_80262130[];
void fn_8009996C(void*, void*);

void fn_80011558(Unk80011558* o) {
    switch (o->unk12) {
    case 0:
        fn_8009996C((u8*)o + 0x88, lbl_80262130);
        o->unk0A &= ~1;
        o->unk16 = 0x8C;
        o->unk12++;
        /* fall through */
    case 1:
        if (--o->unk16 == 0) {
            o->unk11 = 1;
            o->unk12 = 0;
        }
        break;
    }
}
