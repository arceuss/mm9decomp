#include "types.h"
typedef struct Unk800816F0 {
    /* 0x00 */ u8 pad00[0x1];
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 pad02[0x1];
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8* unk04[9];
    /* 0x28 */ u8* unk28;
    /* 0x2C */ u8 pad2C[0xC4];
    /* 0xF0 */ s32 unkF0;
} Unk800816F0;
extern s32 (*lbl_80272DA8[])(Unk800816F0*);
s32 fn_800816F0(Unk800816F0* p) {
    if (p->unkF0) { p->unkF0--; return 0; }
    for (;;) {
        while (p->unk28[0] == 0xFF) {
            if (p->unk03 == 0) { p->unk01 &= ~1; return 1; }
            p->unk03--;
            p->unk28 = p->unk04[p->unk03];
        }
        if (lbl_80272DA8[p->unk28[0]](p)) { p->unk28 += 8; return 0; }
        p->unk28 += 8;
    }
}
