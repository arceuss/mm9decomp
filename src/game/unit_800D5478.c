#include "types.h"

typedef struct Unk8038E028 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ u16 unk4[4];
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u8 padE[0x10 - 0xE];
} Unk8038E028;

extern Unk8038E028 lbl_8038E028;
extern u16 lbl_802805C0[][4];

void fn_800D4CA8(u16 id, s32 arg1);
void fn_800D45BC(void);

void fn_800D5478(void) {
    Unk8038E028* p = &lbl_8038E028;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (p->unk1 & (1 << i)) {
            fn_800D4CA8(lbl_802805C0[lbl_8038E028.unkC][i], 0x1000);
            p->unk1 &= ~(1 << i);
            lbl_8038E028.unk0 |= (1 << i);
        }
        lbl_8038E028.unk4[i] = 0xFFFF;
    }
    fn_800D45BC();
}
