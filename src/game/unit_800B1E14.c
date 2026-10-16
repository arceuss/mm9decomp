#include "types.h"

typedef struct Unk800B1E14 {
    /* 0x000 */ u8 pad0[0x11];
    /* 0x011 */ u8 state;
    /* 0x012 */ u8 pad12[0x14 - 0x12];
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad15[0x10F - 0x15];
    /* 0x10F */ u8 unk10F;
    /* 0x110 */ u8 pad110[0x188 - 0x110];
    /* 0x188 */ u16 unk188;
} Unk800B1E14;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2A0];
    /* 0x2A0 */ u16 unk2A0[4];
    /* 0x2A8 */ u8 pad2A8[0x300 - 0x2A8];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

u32 fn_800B7978(Unk800B1E14* p, u32 tile);
u32 fn_800B7950(Unk800B1E14* p);

s32 fn_800B1E14(Unk800B1E14* p) {
    u8 v;
    u32 a;
    u32 b;

    if ((lbl_80304B90.unk2A0[p->unk14] & 0x8000) || ((1 << p->state) & 0x1110)) {
        return -1;
    }
    v = p->unk10F;
    a = fn_800B7978(p, p->unk188);
    b = fn_800B7978(p, fn_800B7950(p));
    if (a & 0x10) {
        if (b & 0x10) {
            return v >= 0x20;
        }
        return 0;
    }
    return v >= 0x20;
}
