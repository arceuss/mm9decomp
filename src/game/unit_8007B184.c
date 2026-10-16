#include "types.h"
typedef struct Unk8007B184 {
    /* 0x00 */ u8 pad00[0x9];
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[0x5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x3];
    /* 0x18 */ void* unk18;
} Unk8007B184;
extern void** lbl_80270168[];
extern void fn_800E9244(Unk8007B184*);
void fn_8007B184(Unk8007B184* p) {
    fn_800E9244(p);
    p->unk0A &= ~1;
    p->unk18 = lbl_80270168[p->unk09][4];
    p->unk10 = 4; p->unk11 = 0; p->unk12 = 0; p->unk13 = 0;
}
