#include "types.h"

typedef struct Unk8008B05CPlayer {
    /* 0x000 */ u8 pad0[0xA0];
    /* 0x0A0 */ u32 flagsA0;
    /* 0x0A4 */ u8 padA4[0xB6 - 0xA4];
    /* 0x0B6 */ s16 unkB6;
    /* 0x0B8 */ u8 padB8[0x112 - 0xB8];
    /* 0x112 */ u8 unk112;
} Unk8008B05CPlayer;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x2290];
    /* 0x2290 */ Unk8008B05CPlayer* player;
} Unk803140C0;

extern Unk803140C0 lbl_803140C0;
extern s32 lbl_804EE97C;
extern s32 lbl_804EE978;

BOOL fn_800B593C(Unk8008B05CPlayer* player, s32 arg1);
BOOL fn_800B5A38(Unk8008B05CPlayer* player, s32 arg1, u8 arg2);

void fn_8008B05C(void) {
    Unk8008B05CPlayer* player = lbl_803140C0.player;

    if (!(player->flagsA0 & 0x200) && player->unkB6 != 0) {
        if (lbl_804EE97C != 0) {
            lbl_804EE97C--;
            if ((lbl_804EE97C & 3) == 3 && !fn_800B593C(player, 1)) {
                lbl_804EE97C = 0;
            }
        }
        if (lbl_804EE978 != 0) {
            lbl_804EE978--;
            if ((lbl_804EE978 & 3) == 3 && !fn_800B5A38(lbl_803140C0.player, 1, lbl_803140C0.player->unk112)) {
                lbl_804EE978 = 0;
            }
        }
    } else {
        lbl_804EE97C = 0;
        lbl_804EE978 = 0;
    }
}
