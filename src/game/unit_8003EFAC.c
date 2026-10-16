#include "types.h"

typedef struct Unk3EFAC {
    /* 0x000 */ u8 pad000[0x2AE];
    /* 0x2AE */ u16 unk2AE;
} Unk3EFAC;

void fn_8003EFAC(s32 a, s32 b, Unk3EFAC* o) {
    switch (a) {
    case 0:
        o->unk2AE |= 0x20;
        break;
    case 1:
        o->unk2AE |= 0x200;
        break;
    case 3:
        o->unk2AE |= 0x20;
        break;
    }
}
