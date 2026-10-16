#include "types.h"

typedef struct Unk80303E58 {
    /* 0x000 */ u8 pad0[0x410];
    /* 0x410 */ u16 unk410;
    /* 0x412 */ u8 pad412[0x82C - 0x412];
    /* 0x82C */ u16 unk82C;
    /* 0x82E */ u8 pad82E[0xC48 - 0x82E];
    /* 0xC48 */ u16 unkC48;
    /* 0xC4A */ u8 padC4A[0xCD0 - 0xC4A];
    /* 0xCD0 */ u16 unkCD0;
    /* 0xCD2 */ u8 padCD2[0xCD4 - 0xCD2];
    /* 0xCD4 */ u8 unkCD4;
    /* 0xCD5 */ u8 padCD5[0xCEC - 0xCD5];
    /* 0xCEC */ s32 unkCEC;
    /* 0xCF0 */ u8 padCF0[0xD00 - 0xCF0];
} Unk80303E58;

extern Unk80303E58 lbl_80303E58;

extern void (*lbl_80264FB0[4])(void);

void fn_8004014C(void) {
    if (lbl_80303E58.unkCD4 < 3) {
        lbl_80264FB0[lbl_80303E58.unkCD4]();
        lbl_80303E58.unk410 = lbl_80303E58.unkCEC;
        lbl_80303E58.unk82C = lbl_80303E58.unkCEC;
        lbl_80303E58.unkC48 = lbl_80303E58.unkCEC;
    }
}
