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

BOOL fn_800D4624(u16 id);
void fn_800D4CA8(u16 id, s32 arg1);
BOOL fn_800D4A60(u16 id);

static inline BOOL Playing(s32 set) {
    s32 i;

    if (set < 0x21) {
        for (i = 0; i < 4; i++) {
            if (!fn_800D4A60(lbl_802805C0[set][i])) {
                return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

void fn_800D50C0(void) {
    s32 i;

    if (lbl_8038E028.unk1 != 0) {
        for (i = 0; i < 4; i++) {
            if ((lbl_8038E028.unk1 & (1 << i)) && !fn_800D4624(lbl_80280440[lbl_8038E028.unk4[i]][0])) {
                fn_800D4CA8(lbl_802805C0[lbl_8038E028.unkC][i], 0x1000);
                lbl_8038E028.unk4[i] = 0xFFFF;
                lbl_8038E028.unk1 &= ~(1 << i);
                lbl_8038E028.unk0 |= (1 << i);
            }
        }
    }
    if (lbl_8038E028.unkC != 0xFFFF && !Playing(lbl_8038E028.unkC)) {
        if (lbl_8038E028.unkC == BGM_SE_OUT) {
            lbl_8038E028.unk2 = 0;
        }
        lbl_8038E028.unkC = 0xFFFF;
        lbl_8038E028.unk0 = 0;
    }
}
