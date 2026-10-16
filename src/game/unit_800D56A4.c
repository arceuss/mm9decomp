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

BOOL fn_800D4A60(u16 id);
void fn_800D48DC(u16 id);

static inline BOOL GroupReady(s32 group) {
    s32 i;

    if (group >= 0x21) {
        return FALSE;
    }
    for (i = 0; i < 4; i++) {
        if (!fn_800D4A60(lbl_802805C0[group][i])) {
            return FALSE;
        }
    }
    return TRUE;
}

void fn_800D56A4(s32 group) {
    s32 i;

    if (group < 0x21 && GroupReady(group)) {
        for (i = 0; i < 4; i++) {
            fn_800D48DC(lbl_802805C0[group][i]);
            lbl_8038E028.loaded &= ~(1 << i);
        }
        lbl_8038E028.group = 0xFFFF;
    }
}
