#include "types.h"

typedef struct Unk8038E028 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u16 unk4[4];
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u8 padE[0x10 - 0xE];
} Unk8038E028;

typedef struct SeEntry {
    /* 0x0 */ u16 id;
    /* 0x2 */ u8 channels;
    /* 0x3 */ u8 priority;
} SeEntry;

extern Unk8038E028 lbl_8038E028;
extern u16 lbl_802805C0[][4];
extern SeEntry lbl_80280440[];

void fn_800D443C(u16 id);
void fn_800D4CA8(u16 id, s32 arg1);
void fn_800D43B4(u16 id);

static inline BOOL Blocked(u8 channels, u8 priority) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (((1 << i) & channels) && (lbl_8038E028.unk1 & (1 << i)) &&
            priority > lbl_80280440[lbl_8038E028.unk4[i]].priority) {
            return TRUE;
        }
    }
    return FALSE;
}

void fn_800D5234(s32 se) {
    SeEntry* e;
    s32 i;

    if (lbl_8038E028.unk2 == 0 && se < 0x5F) {
        e = &lbl_80280440[se];
        if ((lbl_8038E028.unk1 & e->channels) && Blocked(e->channels, e->priority)) {
            return;
        }
        for (i = 0; i < 4; i++) {
            if ((1 << i) & e->channels) {
                if (lbl_8038E028.unk1 & (1 << i)) {
                    fn_800D443C(lbl_80280440[lbl_8038E028.unk4[i]].id);
                    lbl_8038E028.unk1 &= ~(1 << i);
                } else {
                    fn_800D4CA8(lbl_802805C0[lbl_8038E028.unkC][i], 0);
                }
                lbl_8038E028.unk4[i] = se;
            }
        }
        lbl_8038E028.unk0 &= ~lbl_80280440[se].channels;
        lbl_8038E028.unk1 |= lbl_80280440[se].channels;
        fn_800D43B4(lbl_80280440[se].id);
    }
}
