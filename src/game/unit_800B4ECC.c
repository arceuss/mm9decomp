#include "types.h"

typedef struct Unk800B4ECC {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 flagsA;
    /* 0x00B */ u8 padB[0x11 - 0xB];
    /* 0x011 */ u8 state;
    /* 0x012 */ u8 pad12[0x14 - 0x12];
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad15[0x60 - 0x15];
    /* 0x060 */ s32 x;
    /* 0x064 */ u8 pad64[0xC8 - 0x64];
    /* 0x0C8 */ s32 unkC8;
    /* 0x0CC */ u8 padCC[0x121 - 0xCC];
    /* 0x121 */ u8 unk121;
    /* 0x122 */ u8 pad122[0x19C - 0x122];
    /* 0x19C */ s32 unk19C;
    /* 0x1A0 */ s32 unk1A0;
    /* 0x1A4 */ u8 pad1A4[0x1E0 - 0x1A4];
    /* 0x1E0 */ u16 unk1E0;
} Unk800B4ECC;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2A0];
    /* 0x2A0 */ u16 unk2A0[2];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_800B7A28(s32* pos, s32* arg1, s32* arg2, s32 arg3, s32 arg4, u32 flags);

static inline BOOL Slippery(Unk800B4ECC* p) {
    if (p->unk121 != 0) {
        return TRUE;
    }
    if (((1 << p->state) & 3) && (u32)(p->unk1E0 & 0x1000) == 0x1000) {
        return TRUE;
    }
    return FALSE;
}

s32 fn_800B4ECC(Unk800B4ECC* p, s32 cur, s32 target, s32 accel, s32 skip) {
    s32 d;
    s32* v;

    if (lbl_80304B90.unk2A0[p->unk14] & 0x8000) {
        return target;
    }
    if (skip == 0) {
        v = &p->unk19C;
        fn_800B7A28(&p->x, &p->unkC8, v, v[0], v[1], ((p->flagsA << 14) & 0x40000) | 1);
    }
    if (!Slippery(p)) {
        return target;
    }
    d = target - cur;
    if (target == 0 && d < 0) {
        accel = -accel;
    }
    if (d != 0) {
        if (accel * d < 0) {
            accel = -accel;
        }
        if (accel * accel > d * d) {
            accel = d;
        }
        cur += accel;
        if ((u32)(0x700 - cur) > 0xE00) {
            cur = (((cur >> 31) << 1) + 1) * 0x700;
        }
    }
    return cur;
}
