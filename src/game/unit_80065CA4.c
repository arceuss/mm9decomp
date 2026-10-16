#include "types.h"
typedef struct Unk80065CA4 {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[7];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x60 - 0x13];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ s32 unkCC;
} Unk80065CA4;
extern void fn_800E9244(Unk80065CA4*);
extern s32 fn_800EB16C(s32, s32);
extern void fn_80042CF8(Unk80065CA4*, s32);
extern void fn_800E9758(Unk80065CA4*);
void fn_80065CA4(Unk80065CA4* p) {
    s32 x, y, d, f, a, b, speed;
    switch (p->unk12) {
    case 0:
        fn_800E9244(p);
        p->unk12++;
    case 1:
        x = p->unkC8 - p->unk60;
        y = p->unkCC - p->unk64;
        d = fn_800EB16C(x, y);
        if (d <= 0x800) {
            fn_80042CF8(p, 2);
            fn_800E9244(p);
            p->unk0A &= ~1;
            fn_80042CF8(p, 4);
            return;
        }
        f = 0x100 - (d << 8) / 0x2000;
        if (f < 0x40) f = 0x40;
        a = (x << 8) / d;
        b = (y << 8) / d;
        speed = (f << 10) / 0x100;
        p->unk60 += (a * speed) / 0x100;
        p->unk64 += (b * speed) / 0x100;
        fn_800E9758(p);
        break;
    }
}
