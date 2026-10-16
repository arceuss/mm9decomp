#include "types.h"
#include "game/sound.h"

typedef struct Unk800852B4 {
    /* 0x0000 */ u8 pad0[0xFF5];
    /* 0x0FF5 */ u8 unkFF5;
    /* 0x0FF6 */ u8 padFF6[0x100C - 0xFF6];
    /* 0x100C */ u8 unk100C;
    /* 0x100D */ u8 pad100D[0x100F - 0x100D];
    /* 0x100F */ u8 unk100F;
    /* 0x1010 */ u8 unk1010;
    /* 0x1011 */ u8 unk1011;
} Unk800852B4;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x864];
    /* 0x864 */ u16 unk864;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

void fn_800D5234(s32 id);

void fn_800852B4(Unk800852B4* o) {
    if ((s8)o->unk1010 == 0) {
        if (lbl_80319DA0.unk864 & 1) {
            o->unk100C--;
            o->unk1011--;
            if ((s8)o->unk100C < 0) {
                if ((s8)o->unk1011 < 0) {
                    o->unk100C = 8;
                } else {
                    o->unk100C = 0;
                }
                o->unk100F--;
                if ((s8)o->unk100F < 0) {
                    o->unk100F = 0x29;
                }
            }
            if ((s8)o->unk1011 < 0) {
                o->unk1011 = 0x31;
                fn_800D5234(SE_CURSOR);
            } else {
                fn_800D5234(SE_CURSOR);
            }
            o->unkFF5 = 0;
        } else if (lbl_80319DA0.unk864 & 2) {
            o->unk100C++;
            o->unk1011++;
            if ((s8)o->unk100C > 8) {
                if ((s8)o->unk1011 > 0x31) {
                    o->unk100C = 0;
                } else {
                    o->unk100C = 8;
                }
                o->unk100F++;
                if ((s8)o->unk100F > 0x29) {
                    o->unk100F = 0;
                }
            }
            if ((s8)o->unk1011 > 0x31) {
                o->unk1011 = 0;
                fn_800D5234(SE_CURSOR);
            } else {
                fn_800D5234(SE_CURSOR);
            }
            o->unkFF5 = 0;
        }
    }
    if (lbl_80319DA0.unk864 & 8) {
        fn_800D5234(SE_CURSOR);
        o->unk1010++;
        if ((s8)o->unk1010 > 1) {
            o->unk1010 = 0;
        }
    } else if (lbl_80319DA0.unk864 & 4) {
        fn_800D5234(SE_CURSOR);
        o->unk1010--;
        if ((s8)o->unk1010 < 0) {
            o->unk1010 = 1;
        }
    }
}
