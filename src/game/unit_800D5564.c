#include "types.h"
#include "game/sound.h"

typedef struct Unk8038E028 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u16 unk4[4];
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u8 padE[0x10 - 0xE];
} Unk8038E028;

extern Unk8038E028 lbl_8038E028;
extern u16 lbl_802805C0[][4];
extern u16 lbl_80280440[][2];

void fn_800D443C(u16 id);
void fn_800D48DC(u16 id);
void fn_800D486C(u16 id);
void fn_800D4CA8(u16 id, s32 arg1);

void fn_800D5564(s32 set) {
    s32 i;

    if (set == BGM_SE_OUT) {
        for (i = 0; i < 4; i++) {
            if (lbl_8038E028.unk4[i] != 0xFFFF) {
                fn_800D443C(lbl_80280440[lbl_8038E028.unk4[i]][0]);
                lbl_8038E028.unk4[i] = 0xFFFF;
            }
        }
        lbl_8038E028.unk1 = 0;
        lbl_8038E028.unk2 = 1;
    } else {
        lbl_8038E028.unk2 = 0;
    }
    if (set < 0x21) {
        for (i = 0; i < 4; i++) {
            if (lbl_8038E028.unkC != 0xFFFF) {
                fn_800D48DC(lbl_802805C0[lbl_8038E028.unkC][i]);
            }
            fn_800D486C(lbl_802805C0[set][i]);
            if (lbl_8038E028.unk1 & (1 << i)) {
                fn_800D4CA8(lbl_802805C0[set][i], 0);
            } else {
                lbl_8038E028.unk0 |= (1 << i);
            }
        }
        lbl_8038E028.unkC = set;
    }
}
