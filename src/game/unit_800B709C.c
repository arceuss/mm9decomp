#include "types.h"

typedef struct UnkB709CWords {
    /* 0x00 */ u32 w[15];
} UnkB709CWords;

typedef struct UnkB709C {
    /* 0x000 */ u8 pad000[0x9];
    /* 0x009 */ u8 unk009;
    /* 0x00A */ u8 pad00A[0x11 - 0xA];
    /* 0x011 */ u8 unk011;
    /* 0x012 */ u8 unk012;
    /* 0x013 */ u8 unk013;
    /* 0x014 */ u8 pad014[0x18 - 0x14];
    /* 0x018 */ u32 unk018;
    /* 0x01C */ u8 pad01C[0x2E - 0x1C];
    /* 0x02E */ u8 unk02E;
    /* 0x02F */ u8 pad02F[0xEC - 0x2F];
    /* 0x0EC */ u8 unk0EC;
    /* 0x0ED */ u8 unk0ED;
    /* 0x0EE */ u8 unk0EE;
    /* 0x0EF */ u8 unk0EF;
    /* 0x0F0 */ u8 unk0F0;
    /* 0x0F1 */ u8 unk0F1;
    /* 0x0F2 */ u8 unk0F2;
    /* 0x0F3 */ u8 unk0F3;
    /* 0x0F4 */ u8 unk0F4;
    /* 0x0F5 */ u8 unk0F5;
    /* 0x0F6 */ u8 pad0F6[0x14C - 0xF6];
    /* 0x14C */ union {
        struct {
            /* 0x14C */ u8 unk14C;
            /* 0x14D */ u8 unk14D;
            /* 0x14E */ u16 unk14E[11];
            /* 0x164 */ u32 unk164;
        } f;
        /* 0x14C */ UnkB709CWords w;
    } u;
} UnkB709C;

extern UnkB709CWords* lbl_8027EB98[];

UnkB709C* fn_800AB87C(void);

void fn_800B709C(UnkB709C* a, UnkB709CWords* b, u8 c, u32 d, u32 e) {
    UnkB709CWords* p;
    s32 i;

    if (a == 0)
        a = fn_800AB87C();
    if (a == 0)
        return;
    if (b != 0) {
        a->u.w = *b;
    } else {
        a->u.f.unk14C = 2;
        a->u.f.unk14D = c;
        for (i = 0; i < 11; i++)
            a->u.f.unk14E[i] = 0x1C00;
        if (e == 1)
            a->u.f.unk164 = 0x7FF;
        else
            a->u.f.unk164 = 0x201;
    }
    a->unk02E = 0x10;
    a->unk009 = a->u.f.unk14D;
    p = lbl_8027EB98[a->unk009];
    a->unk018 = p->w[0];
    if (d == 1) {
        a->unk0EC = a->unk011;
        a->unk011 = 1;
        a->unk0ED = a->unk012;
        a->unk012 = 0;
        a->unk0EE = a->unk013;
        a->unk013 = 0;
        a->unk0F2 = a->unk0EF;
        a->unk0EF = 0;
        a->unk0F3 = a->unk0F0;
        a->unk0F0 = 0;
        a->unk0F4 = a->unk0F1;
        a->unk0F1 = 0;
        a->unk0F5 = 1;
    } else {
        a->unk0EC = a->unk011;
        a->unk011 = 0;
        a->unk0ED = a->unk012;
        a->unk012 = 0;
        a->unk0EE = a->unk013;
        a->unk013 = 0;
        a->unk0F2 = a->unk0EF;
        a->unk0EF = 0;
        a->unk0F3 = a->unk0F0;
        a->unk0F0 = 0;
        a->unk0F4 = a->unk0F1;
        a->unk0F1 = 0;
        a->unk0F5 = 0;
    }
}
