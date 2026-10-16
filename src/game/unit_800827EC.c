#include "types.h"
typedef struct Unk800827EC {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ s8 unk08;
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
} Unk800827EC;
typedef struct Unk800827ECWork {
    /* 0x00 */ u8 pad00[0x28];
    /* 0x28 */ u8* unk28;
    /* 0x2C */ u8 pad2C[0x194 - 0x2C];
    /* 0x194 */ Unk800827EC* unk194;
} Unk800827ECWork;
extern void** lbl_80265138[];
extern void** lbl_804EC838[];
extern Unk800827EC* fn_80041EE0(void);
s32 fn_800827EC(Unk800827ECWork* p) {
    Unk800827EC* q;
    if (p->unk28[1] == 0) {
        if (p->unk194) { p->unk28 -= 8; return 1; }
        return 0;
    }
    q = p->unk194;
    if (q) {
        if (q->unk08 == 8) {
            q->unk0A &= ~1; q->unk0A &= 0xFD;
            q->unk18 = lbl_80265138[q->unk09][3];
            q->unk10 = 3; q->unk11 = 0; q->unk12 = 0; q->unk13 = 0;
        } else if (q->unk08 == 4) {
            q->unk0A &= ~1; q->unk0A &= 0xFD;
            q->unk18 = lbl_804EC838[q->unk09][3];
            q->unk10 = 3; q->unk11 = 0; q->unk12 = 0; q->unk13 = 0;
        }
    }
    if ((s32)p->unk28[1] == 1) {
        p->unk194 = fn_80041EE0();
        if (!p->unk194) { p->unk28 -= 8; return 1; }
    }
    if (!p->unk194) { p->unk28 -= 8; return 1; }
    return 0;
}
