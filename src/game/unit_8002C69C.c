#include "types.h"
#include "game/sound.h"

typedef struct Unk8002C69C {
    /* 0x000 */ u8 pad0[0x26D];
    /* 0x26D */ u8 unk26D;
    /* 0x26E */ u8 unk26E;
    /* 0x26F */ u8 pad26F[0x271 - 0x26F];
    /* 0x271 */ u8 unk271;
    /* 0x272 */ u8 pad272;
    /* 0x273 */ u8 unk273;
    /* 0x274 */ u8 pad274[0x284 - 0x274];
    /* 0x284 */ u8 unk284;
} Unk8002C69C;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x864];
    /* 0x864 */ u16 unk864;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

void fn_800D5234(s32 id);

void fn_8002C69C(Unk8002C69C* o) {
    if ((s8)o->unk273 == 0) {
        if (lbl_80319DA0.unk864 & 1) {
            o->unk26E--;
            o->unk284--;
            if ((s8)o->unk26E < 0) {
                if ((s8)o->unk284 < 0) {
                    o->unk26E = 8;
                } else {
                    o->unk26E = 0;
                }
                o->unk271--;
                if ((s8)o->unk271 < 0) {
                    o->unk271 = 0x29;
                }
            }
            if ((s8)o->unk284 < 0) {
                o->unk284 = 0x31;
                fn_800D5234(SE_CURSOR);
            } else {
                fn_800D5234(SE_CURSOR);
            }
            o->unk26D = 0;
        } else if (lbl_80319DA0.unk864 & 2) {
            o->unk26E++;
            o->unk284++;
            if ((s8)o->unk26E > 8) {
                if ((s8)o->unk284 > 0x31) {
                    o->unk26E = 0;
                } else {
                    o->unk26E = 8;
                }
                o->unk271++;
                if ((s8)o->unk271 > 0x29) {
                    o->unk271 = 0;
                }
            }
            if ((s8)o->unk284 > 0x31) {
                o->unk284 = 0;
                fn_800D5234(SE_CURSOR);
            } else {
                fn_800D5234(SE_CURSOR);
            }
            o->unk26D = 0;
        }
    }
    if (lbl_80319DA0.unk864 & 8) {
        fn_800D5234(SE_CURSOR);
        o->unk273++;
        if ((s8)o->unk273 > 1) {
            o->unk273 = 0;
        }
    } else if (lbl_80319DA0.unk864 & 4) {
        fn_800D5234(SE_CURSOR);
        o->unk273--;
        if ((s8)o->unk273 < 0) {
            o->unk273 = 1;
        }
    }
}
