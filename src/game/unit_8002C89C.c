#include "types.h"
#include "game/sound.h"

typedef struct Unk2C89C {
    /* 0x000 */ u8 pad000[0x26C];
    /* 0x26C */ u8 unk26C;
    /* 0x26D */ u8 pad26D[0x272 - 0x26D];
    /* 0x272 */ u8 unk272;
    /* 0x273 */ s8 unk273;
} Unk2C89C;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad000[0x860];
    /* 0x860 */ u32 unk860;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

extern void fn_800D5234(s32 a);

void fn_8002C89C(Unk2C89C* o) {
    u32 v = lbl_80319DA0.unk860;

    if (v & 0x50) {
        fn_800D5234(SE_SELECT);
        if (o->unk272 == 1) {
            o->unk272 = 0;
        } else {
            o->unk272 = 1;
        }
        if (o->unk273 == 1) {
            o->unk26C = 1;
        }
    } else if (v & 0x20) {
        if (o->unk272 == 0) {
            if ((s8)o->unk273 == 0) {
                fn_800D5234(SE_CURSOR);
            }
            o->unk273 = 1;
        } else {
            o->unk272 = 0;
        }
    }
}
