#include "types.h"

typedef struct Unk800A59F4 {
    /* 0x00 */ struct Unk800A59F4* next;
    /* 0x04 */ u8 bpp;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[0x8 - 0x6];
    /* 0x08 */ u8* buf;
    /* 0x0C */ void* unkC;
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 w;
    /* 0x13 */ u8 h;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 unk24;
    /* 0x25 */ u8 unk25;
    /* 0x26 */ u8 unk26;
    /* 0x27 */ u8 unk27;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
} Unk800A59F4;

typedef struct Unk8036CF50 {
    /* 0x0000 */ u8 pad0[0xEFDC];
    /* 0xEFDC */ Unk800A59F4* head;
} Unk8036CF50;

extern Unk8036CF50 lbl_8036CF50;
extern u8 lbl_8027E190[];

void fn_800E8520(s32 value, void* dst, u32 size);
void fn_800BAFDC(void* src, void* dst, s32 size);

u8* fn_800A59F4(Unk800A59F4* p, s32 arg1, u8* buf, void* arg3, u32 w, u32 h, u8 bpp, s32 arg7, s32 arg8,
                s32 arg9, s32 arg10, s32 arg11, s32 arg12) {
    u32 n;

    if (w > 0x20) {
        w = 0x20;
    }
    n = (bpp << 3) * ((u8)w * (u8)h + 1);
    p->next = NULL;
    p->bpp = bpp;
    p->unk5 = 0;
    p->buf = buf;
    p->unkC = arg3;
    p->unk10 = arg11;
    p->unk11 = arg12;
    p->w = w;
    p->h = h;
    p->unk14 = arg7;
    p->unk18 = arg8;
    p->unk1C = arg9;
    p->unk20 = arg10;
    p->unk24 = arg11;
    p->unk25 = arg12;
    p->unk26 = w;
    p->unk27 = h;
    p->unk28 = 0;
    p->unk2A = 0;
    fn_800E8520(0, buf + n, n);
    fn_800E8520(0, p->buf, bpp << 3);
    fn_800BAFDC(lbl_8027E190, p->unkC, 0xC);
    p->unk5 = 0;
    p->unk28 = 0;
    p->unk2A = 0;
    if (p->next == NULL) {
        p->next = lbl_8036CF50.head;
        lbl_8036CF50.head = p;
    }
    return buf + (p->bpp << 4) * (p->w * p->h + 1);
}
