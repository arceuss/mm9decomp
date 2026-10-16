#include "types.h"

typedef struct Unk7388 {
    /* 0x00 */ u8 pad0[0x11C];
    /* 0x11C */ u8 unk11C;
    /* 0x11D */ u8 pad11D[0x188 - 0x11D];
    /* 0x188 */ u16 unk188;
    /* 0x18A */ u16 unk18A;
    /* 0x18C */ u16 unk18C;
    /* 0x18E */ u16 unk18E;
    /* 0x190 */ u16 unk190;
    /* 0x192 */ u16 unk192;
    /* 0x194 */ u16 unk194;
    /* 0x196 */ u16 unk196;
    /* 0x198 */ u16 unk198;
} Unk7388;

void fn_800B7388(Unk7388* rec) {
    rec->unk188 = 0;
    rec->unk18A = 0;
    rec->unk18C = 0;
    rec->unk18E = 0;
    rec->unk190 = 0;
    rec->unk192 = 0;
    rec->unk194 = 0;
    rec->unk196 = 0;
    rec->unk198 = 0;
    rec->unk11C = 0;
}
