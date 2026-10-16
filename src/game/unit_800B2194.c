#include "types.h"

typedef struct Unk800B2194 {
    /* 0x000 */ u8 pad0[0x9];
    /* 0x009 */ u8 unk9;
    /* 0x00A */ u8 padA[0x11 - 0xA];
    /* 0x011 */ u8 state;
    /* 0x012 */ u8 pad12[0x14 - 0x12];
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad15[0x10F - 0x15];
    /* 0x10F */ u8 unk10F;
    /* 0x110 */ u8 unk110;
    /* 0x111 */ u8 unk111;
    /* 0x112 */ u8 pad112[0x128 - 0x112];
    /* 0x128 */ u32 unk128;
    /* 0x12C */ u8 pad12C[0x1F8 - 0x12C];
    /* 0x1F8 */ u8 shots;
} Unk800B2194;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2A0];
    /* 0x2A0 */ u16 unk2A0[4];
    /* 0x2A8 */ u8 pad2A8[0x300 - 0x2A8];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern u8 lbl_8027E80C[];
extern u8 lbl_8027E800[];

void fn_800B2194(Unk800B2194* p) {
    u8 v;
    s32 n;

    if (p->shots != 0) {
        p->unk10F = 0;
        p->unk110 = 0;
        p->unk111 = 0;
        return;
    }
    if (!((1 << p->state) & 0x6720) && !(lbl_80304B90.unk2A0[p->unk14] & 0x8000)) {
        v = p->unk10F;
        if (v - (p->unk9 == 2 ? lbl_8027E80C[1] : lbl_8027E800[1]) >= 0) {
            p->unk128 |= 0x10;
        } else if (v > 1) {
            p->unk128 |= 8;
        }
    }
    if (!((1 << p->state) & 0x100)) {
        n = p->unk110;
        n++;
        if (n >= 8) {
            n = 0;
        }
        p->unk110 = n;
    }
}
