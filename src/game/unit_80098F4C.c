#include "types.h"

typedef struct Unk98F4C {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[0x10F8 - 0xC];
    /* 0x10F8 */ u16 unk10F8[0x20];
} Unk98F4C;

extern u8 lbl_8043CA80[];

s32 fn_8000EECC(s32);

void fn_80098F4C(Unk98F4C* rec) {
    s32 v = rec->unkA;
    if (v < 0x1E && (0x80 - rec->unk8) / 4 >= v) {
        s32 off = fn_8000EECC(0x38);
        u16* tbl = rec->unk10F8;
        *(u16*)(*(u32*)(lbl_8043CA80 + 0x258) + off + 0x244 + rec->unkA * 2) = tbl[rec->unkA];
        rec->unkA = rec->unkA + 1;
    }
}
