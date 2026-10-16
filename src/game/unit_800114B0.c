#include "types.h"

typedef struct Unk800114B0 {
    /* 0x00 */ u8 pad00[0x0A];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[0x11 - 0x0B];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x7F - 0x17];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0x88 - 0x80];
} Unk800114B0;

extern u8 lbl_80262130[];
void fn_8009996C(void*, void*);
void fn_800E946C(Unk800114B0*, s32);
void fn_800E9750(Unk800114B0*, u16);

void fn_800114B0(Unk800114B0* o) {
    switch (o->unk12) {
    case 0:
        fn_800E946C(o, 3);
        fn_8009996C((u8*)o + 0x88, lbl_80262130);
        o->unk0A |= 1;
        o->unk16 = 0x10;
        o->unk12++;
        /* fall through */
    case 1:
        fn_800E9750(o, 0xFFFF);
        if (o->unk7F == 3) {
            o->unk11 = 6;
            o->unk12 = 0;
        }
        break;
    }
}
