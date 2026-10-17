#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

typedef struct Unk80095E40Gfx {
    /* 0x0000 */ u8 pad0[0x1006];
    /* 0x1006 */ u16 unk1006;
    /* 0x1008 */ u16 unk1008;
    /* 0x100A */ u16 unk100A;
    /* 0x100C */ u16 unk100C;
    /* 0x100E */ u16 unk100E;
    /* 0x1010 */ u16 unk1010;
    /* 0x1012 */ u16 unk1012;
    /* 0x1014 */ u16 unk1014;
    /* 0x1016 */ u16 unk1016;
    /* 0x1018 */ u16 unk1018;
    /* 0x101A */ u16 unk101A;
    /* 0x101C */ u16 owned;
} Unk80095E40Gfx;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x21F8];
    /* 0x21F8 */ u32 unk21F8;
} Unk803140C0;

extern Unk80316D78 lbl_80316D78;
extern Unk803140C0 lbl_803140C0;
extern void* lbl_804EE984;

u16 fn_800B59A4(void* p, s32 weapon);

#define GFX ((Unk80095E40Gfx*)(lbl_80316D78.unk3004 + 0xD40000))

void fn_80095E40(void) {
    GFX->owned = 0;
    if (lbl_803140C0.unk21F8 & 1) {
        GFX->owned |= 1;
        GFX->unk1006 = fn_800B59A4(lbl_804EE984, 0);
    }
    if (lbl_803140C0.unk21F8 & 2) {
        GFX->owned |= 2;
        GFX->unk1008 = fn_800B59A4(lbl_804EE984, 1);
    }
    if (lbl_803140C0.unk21F8 & 4) {
        GFX->owned |= 4;
        GFX->unk100A = fn_800B59A4(lbl_804EE984, 2);
    }
    if (lbl_803140C0.unk21F8 & 8) {
        GFX->owned |= 8;
        GFX->unk100C = fn_800B59A4(lbl_804EE984, 3);
    }
    if (lbl_803140C0.unk21F8 & 0x20) {
        GFX->owned |= 0x10;
        GFX->unk100E = fn_800B59A4(lbl_804EE984, 5);
    }
    if (lbl_803140C0.unk21F8 & 0x10) {
        GFX->owned |= 0x20;
        GFX->unk1010 = fn_800B59A4(lbl_804EE984, 4);
    }
    if (lbl_803140C0.unk21F8 & 0x40) {
        GFX->owned |= 0x40;
        GFX->unk1012 = fn_800B59A4(lbl_804EE984, 6);
    }
    if (lbl_803140C0.unk21F8 & 0x80) {
        GFX->owned |= 0x80;
        GFX->unk1014 = fn_800B59A4(lbl_804EE984, 7);
    }
    if (lbl_803140C0.unk21F8 & 0x100) {
        GFX->owned |= 0x100;
        GFX->unk1016 = fn_800B59A4(lbl_804EE984, 8);
    }
    if (lbl_803140C0.unk21F8 & 0x200) {
        GFX->owned |= 0x200;
        GFX->unk1018 = fn_800B59A4(lbl_804EE984, 9);
    }
    if (lbl_803140C0.unk21F8 & 0x400) {
        GFX->owned |= 0x400;
        GFX->unk101A = fn_800B59A4(lbl_804EE984, 10);
    }
}
