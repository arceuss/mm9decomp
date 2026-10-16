#include "types.h"

typedef struct Unk8038E028 {
    /* 0x0 */ u8 loaded;
    /* 0x1 */ u8 pending;
    /* 0x2 */ u8 pad2[0x4 - 0x2];
    /* 0x4 */ u16 unk4[4];
    /* 0xC */ u16 group;
    /* 0xE */ u8 padE[0x10 - 0xE];
} Unk8038E028;

extern Unk8038E028 lbl_8038E028;
extern u16 lbl_802805C0[][4];

void fn_800D4B88(u16 id, s32 arg1);

void fn_800D5838(s32 group, s32 arg1) {
    s32 i;

    if (group < 0x21) {
        for (i = 0; i < 4; i++) {
            if (i != 2) {
                fn_800D4B88(lbl_802805C0[group][i], arg1);
            }
        }
    }
}
