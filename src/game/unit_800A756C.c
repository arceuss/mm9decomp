#include "types.h"

typedef struct Unk8037C3D8 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 choice;
    /* 0x0B */ u8 padB[0x20 - 0xB];
    /* 0x20 */ u8 unk20[0x4C - 0x20];
    /* 0x4C */ void* unk4C;
} Unk8037C3D8;

typedef struct Unk80301280Sub {
    /* 0x0 */ u32 flags;
} Unk80301280Sub;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ Unk80301280Sub* unk40;
} Unk80301280;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 unk860;
    /* 0x864 */ u16 unk864;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;
extern Unk8037C3D8 lbl_8037C3D8;
extern Unk80301280 lbl_80301280;

void fn_800A5B2C(void* arg0);
void fn_800D5234(s32 id);
s32 fn_800A5ED4(void* arg0);
s32 fn_800A5DE0(s32 arg0, s32 arg1);
void fn_800A5BE0(void* arg0, s32 arg1, s32 arg2, s32 arg3);

BOOL fn_800A756C(void) {
    BOOL ret = FALSE;
    u8 choice;
    u8 row;

    if (lbl_80319DA0.unk860 & 0x50) {
        fn_800A5B2C(lbl_8037C3D8.unk20);
        lbl_80301280.unk40->flags &= ~0x200;
        fn_800D5234(1);
        ret = TRUE;
    } else {
        choice = lbl_8037C3D8.choice;
        if (lbl_80319DA0.unk864 & 1) {
            choice = (choice + 1) & 1;
        } else if (lbl_80319DA0.unk864 & 0x82) {
            choice = (choice + 1) & 1;
        }
        row = fn_800A5ED4(lbl_8037C3D8.unk4C);
        row -= 3;
        fn_800A5BE0(lbl_8037C3D8.unk20, fn_800A5DE0(0, 0x2A), 0, (row + choice * 2) * 8);
        fn_800A5BE0(lbl_8037C3D8.unk20, fn_800A5DE0(0, 0x24), 0, (row + (1 - choice) * 2) * 8);
        if (lbl_8037C3D8.choice != choice) {
            fn_800D5234(0);
        }
        lbl_8037C3D8.choice = choice;
    }
    return ret;
}
