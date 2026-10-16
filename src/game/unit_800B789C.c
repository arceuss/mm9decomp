#include "types.h"

typedef struct Unk800B789C {
    /* 0x000 */ u8 pad0[0x10F];
    /* 0x10F */ u8 unk10F;
    /* 0x110 */ u8 pad110[0x188 - 0x110];
    /* 0x188 */ u16 held;
    /* 0x18A */ u8 pad18A[0x18C - 0x18A];
    /* 0x18C */ u16 trig;
    /* 0x18E */ u16 unk18E;
    /* 0x190 */ u8 pad190[0x198 - 0x190];
    /* 0x198 */ u16 unk198;
} Unk800B789C;

s32 fn_800B789C(Unk800B789C* p, s32 ret, u32 n) {
    u32 mask = 0;
    u32 rel;
    u32 trig;
    u32 rep;

    rel = ~p->held & 0x40;
    if (p->unk198 & 0x10) {
        mask |= 0x40;
    }
    trig = p->trig & ((mask | ~0x40) & 0x40);
    rep = p->unk18E & 0x40;
    if (((rel & 0x40) || (rep & 0x40)) && p->unk10F >= n) {
        return ret;
    }
    if (trig & 0x40) {
        return ret;
    }
    return -1;
}
