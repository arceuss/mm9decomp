#include "types.h"

typedef struct Unk80096A20Gfx {
    /* 0x0000 */ u8 pad0[0x1000];
    /* 0x1000 */ u8 weapon;
    /* 0x1001 */ u8 pad1001;
    /* 0x1002 */ u8 unk1002;
    /* 0x1003 */ u8 pad1003[0x101C - 0x1003];
    /* 0x101C */ u16 owned;
} Unk80096A20Gfx;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;

#define GFX ((Unk80096A20Gfx*)(lbl_80316D78.unk3004 + 0xD40000))

void fn_80096A20(void) {
    s8 w = (s8)GFX->weapon;
    u8 i;

    if (GFX->unk1002 != 0) {
        if ((u8)w <= 2) {
            GFX->unk1002 = 0;
            for (w = 5; w >= 0; w--) {
                if (GFX->owned & (1 << w)) {
                    GFX->weapon = w;
                    return;
                }
            }
        } else {
            GFX->weapon = w - 3;
        }
        return;
    }
    for (i = 0; i < 6; i++) {
        w--;
        if (w < 0 || w == 5) {
            GFX->unk1002 = 1;
            GFX->weapon = 3;
            return;
        }
        if (GFX->owned & (1 << w)) {
            GFX->weapon = w;
            return;
        }
    }
}
