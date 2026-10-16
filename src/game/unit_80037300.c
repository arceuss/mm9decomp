#include "types.h"
#include "game/sound.h"

typedef struct Unk2500 {
    /* 0x0000 */ u8 pad0000[0x2500];
    /* 0x2500 */ u8 unk2500;
} Unk2500;

typedef struct Unk8038B2F8 {
    /* 0x000 */ u8 pad000[0x184];
    /* 0x184 */ Unk2500* unk184;
} Unk8038B2F8;

typedef struct Unk37300 {
    /* 0x000 */ u8 pad000[5];
    /* 0x005 */ u8 unk5;
    /* 0x006 */ u8 pad006[0x008 - 0x006];
    /* 0x008 */ s16 unk8;
    /* 0x00A */ u8 pad00A[0x26C - 0x00A];
    /* 0x26C */ u8 unk26C;
    /* 0x26D */ u8 pad26D[0x281 - 0x26D];
    /* 0x281 */ u8 unk281;
    /* 0x282 */ u8 pad282[0x287 - 0x282];
    /* 0x287 */ u8 unk287;
} Unk37300;

extern Unk8038B2F8 lbl_8038B2F8;

extern s32 fn_800D57BC(s32 a);
extern void fn_800D56A4(s32 a);

void fn_80037300(Unk37300* o) {
    lbl_8038B2F8.unk184->unk2500 = o->unk8;
    if (o->unk8 > 0) {
        o->unk8 = o->unk8 - 1;
    } else {
        o->unk26C = 2;
        if (o->unk281 == 0) {
            o->unk5 = 3;
            o->unk287 = 1;
        } else {
            o->unk5 = 3;
            o->unk287 = 1;
            if (fn_800D57BC(BGM_PASSWORD) != 0) {
                fn_800D56A4(BGM_PASSWORD);
            }
        }
    }
}
