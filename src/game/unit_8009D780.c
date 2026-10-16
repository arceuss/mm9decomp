#include "types.h"

typedef struct Unk80319DA0_8 {
    /* 0x000 */ u8 pad0[0x86C];
} Unk80319DA0_8;

typedef struct Unk80319DA0 {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ Unk80319DA0_8 unk8[4];
    /* 0x21B8 */ u8 pad21B8[0x21C0 - 0x21B8];
} Unk80319DA0;

typedef struct Unk80316D28 {
    /* 0x0 */ u8 pad0[0x3];
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 pad5[0x10 - 0x5];
} Unk80316D28;

extern Unk80319DA0 lbl_80319DA0;
extern Unk80316D28 lbl_80316D28;

void fn_8009D83C(Unk80319DA0_8* work, s32 index);
void fn_80153C50(s32 chan);
void fn_80158468(s32 chan);
void fn_80153C6C(s32 chan);

void fn_8009D780(void) {
    Unk80319DA0_8* work = lbl_80319DA0.unk8;
    s32 i;

    for (i = 0; i < 4; i++) {
        fn_8009D83C(work, i);
        work++;
    }
    if (lbl_80316D28.unk3 == 0 && lbl_80316D28.unk4 < 2) {
        for (i = 0; i < 4; i++) {
            fn_80153C50(i);
            if (i != 0) {
                fn_80158468(i);
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            fn_80153C6C(i);
        }
    }
}
