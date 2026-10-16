#include "types.h"

typedef struct Unk4044C {
    /* 0x000 */ u8 pad000[0xC74];
    /* 0xC74 */ s16 unkC74;
    /* 0xC76 */ u8 padC76[0xCCC - 0xC76];
    /* 0xCCC */ u16 unkCCC;
    /* 0xCCE */ u8 padCCE[2];
    /* 0xCD0 */ u16 unkCD0;
    /* 0xCD2 */ u8 padCD2[2];
    /* 0xCD4 */ u8 unkCD4;
    /* 0xCD5 */ u8 unkCD5;
    /* 0xCD6 */ u8 unkCD6;
    /* 0xCD7 */ u8 unkCD7;
    /* 0xCD8 */ u8 unkCD8;
    /* 0xCD9 */ u8 unkCD9;
    /* 0xCDA */ u8 unkCDA;
    /* 0xCDB */ u8 padCDB[0xCEC - 0xCDB];
    /* 0xCEC */ s32 unkCEC;
} Unk4044C;
extern Unk4044C lbl_80303E58;
extern s16 lbl_802537E8[];

void fn_8003FDE0(void);
void fn_8004044C(void) {
    switch (lbl_80303E58.unkCD5) {
    case 0:
        lbl_80303E58.unkCCC &= ~2;
        lbl_80303E58.unkCD8 = 0;
        lbl_80303E58.unkCD5++;
        break;
    case 1:
        lbl_80303E58.unkCD8++;
        lbl_80303E58.unkCEC = ((lbl_802537E8[(u8)(lbl_80303E58.unkCD8 * 2 + 0x80)] * -0x28000) / 256) >> 8;
        lbl_80303E58.unkC74 = lbl_80303E58.unkCEC;
        if (lbl_80303E58.unkCD8 >= 0x20) {
            fn_8003FDE0();
        }
        break;
    }
}
