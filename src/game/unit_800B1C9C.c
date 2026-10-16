#include "types.h"

typedef struct Unk800B1C9C {
    /* 0x000 */ u8 pad0[0x9];
    /* 0x009 */ u8 kind;
    /* 0x00A */ u8 padA[0x11 - 0xA];
    /* 0x011 */ u8 state;
    /* 0x012 */ u8 pad12[0x14 - 0x12];
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad15[0x10F - 0x15];
    /* 0x10F */ u8 charge;
    /* 0x110 */ u8 unk110;
    /* 0x111 */ u8 chargeSE;
    /* 0x112 */ u8 pad112[0x128 - 0x112];
    /* 0x128 */ u32 unk128;
} Unk800B1C9C;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2A0];
    /* 0x2A0 */ u16 unk2A0[2];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern u8 lbl_8027E80C[];
extern u8 lbl_8027E800[];

void fn_800D5234(s32 id);

void fn_800B1C9C(Unk800B1C9C* p) {
    u8 thr;
    u8 kind;
    s32 charge;
    s32 v;

    if (!((1 << p->state) & 0x6720) && !(lbl_80304B90.unk2A0[p->unk14] & 0x8000)) {
        if (p->chargeSE == 0) {
            charge = p->charge;
            kind = p->kind;
            if (charge - 0x20 >= 0) {
                if (kind == 2) {
                    fn_800D5234(0x32);
                } else {
                    fn_800D5234(0x22);
                }
                p->chargeSE = 1;
            }
        }
        kind = p->kind;
        charge = p->charge;
        if (kind == 2) {
            thr = lbl_8027E80C[0];
        } else {
            thr = lbl_8027E800[0];
        }
        charge -= thr;
        if (charge >= 0 && kind != 2) {
            p->unk128 |= 1;
        }
    }
    if (!((1 << p->state) & 0x100)) {
        v = p->unk110;
        v++;
        if (v >= 8) {
            v = 0;
        }
        p->unk110 = v;
    }
}
