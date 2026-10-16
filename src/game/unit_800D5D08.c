#include "types.h"

typedef struct Unk8038E038Item {
    /* 0x00 */ u8 pad0[0x38];
    /* 0x38 */ u8 unk38;
} Unk8038E038Item;

typedef struct Unk8038E038Rec {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u16 unkE;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
} Unk8038E038Rec;

typedef struct Unk8038E038 {
    /* 0x000 */ Unk8038E038Item* lists[3][4];
    /* 0x030 */ u32 counts[3];
    /* 0x03C */ u8 mutex[0x54 - 0x3C];
    /* 0x054 */ Unk8038E038Rec recs[4];
    /* 0x0D4 */ u32 recCount;
    /* 0x0D8 */ u8 padD8[0x108 - 0xD8];
} Unk8038E038;

extern Unk8038E038 lbl_8038E038;

void fn_800F615C(void* mutex);
void fn_800F6238(void* mutex);

extern u8 lbl_804ED308[4];
extern s32 lbl_802806C8[4];

void fn_800D5D08(s32 a, s32 b, s32 c, u16 d, u16 e, s32 f, s32 g) {
    u32 n = lbl_8038E038.recCount;
    Unk8038E038Rec* rec;

    if (n + 1 <= 4) {
        rec = &lbl_8038E038.recs[n];
        rec->unk0 = a;
        rec->unk4 = b;
        rec->unk8 = lbl_804ED308[c * 2];
        rec->unkC = d;
        rec->unkE = e;
        rec->unk10 = lbl_802806C8[f];
        rec->unk14 = lbl_802806C8[g];
        rec->unk18 = 0;
        rec->unk1C = 0;
        lbl_8038E038.recCount = n + 1;
    }
}
