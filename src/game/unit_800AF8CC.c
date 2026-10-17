#include "types.h"

typedef struct UnkAF8CC {
    /* 0x000 */ u8 pad000[0x9];
    /* 0x009 */ u8 unk009;
    /* 0x00A */ u8 unk00A;
    /* 0x00B */ u8 pad00B[0x12 - 0xB];
    /* 0x012 */ u8 unk012;
    /* 0x013 */ u8 unk013;
    /* 0x014 */ u8 pad014[0x60 - 0x14];
    /* 0x060 */ s32 x;
    /* 0x064 */ s32 y;
    /* 0x068 */ s32 unk068;
    /* 0x06C */ s32 unk06C;
    /* 0x070 */ u8 pad070[0xA9 - 0x70];
    /* 0x0A9 */ u8 unk0A9;
    /* 0x0AA */ u8 pad0AA[0xC8 - 0xAA];
    /* 0x0C8 */ u8 unk0C8[0xDC - 0xC8];
    /* 0x0DC */ s16 unk0DC;
    /* 0x0DE */ s16 unk0DE;
    /* 0x0E0 */ u8 pad0E0[0xE4 - 0xE0];
    /* 0x0E4 */ s16 unk0E4;
    /* 0x0E6 */ u8 pad0E6[0xED - 0xE6];
    /* 0x0ED */ u8 unk0ED;
    /* 0x0EE */ u8 unk0EE;
    /* 0x0EF */ u8 pad0EF[0xFC - 0xEF];
    /* 0x0FC */ u8 unk0FC;
    /* 0x0FD */ u8 unk0FD;
    /* 0x0FE */ u8 pad0FE[0x101 - 0xFE];
    /* 0x101 */ u8 unk101;
    /* 0x102 */ u8 pad102[0x104 - 0x102];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 unk108;
    /* 0x109 */ u8 pad109[0x115 - 0x109];
    /* 0x115 */ u8 unk115;
    /* 0x116 */ u8 pad116;
    /* 0x117 */ u8 unk117;
    /* 0x118 */ u8 unk118;
    /* 0x119 */ u8 pad119[0x11C - 0x119];
    /* 0x11C */ u8 unk11C;
    /* 0x11D */ u8 pad11D[0x19C - 0x11D];
    /* 0x19C */ u32 unk19C;
    /* 0x1A0 */ u32 unk1A0;
} UnkAF8CC;

extern u32* lbl_8027EB60[];

void fn_800B9F74(UnkAF8CC* obj, u32 anim);
void fn_800AF680(UnkAF8CC* obj);
u32 fn_800B7A28(s32* pos, void* vel, u32* box, u32 cur, u32 arg4, u32 flags);
void fn_800B4C40(UnkAF8CC* obj);
void fn_800BA334(UnkAF8CC* obj, u8 arg1, s32 arg2);
void fn_800BA1A8(UnkAF8CC* obj, u8 arg1);

void fn_800AF8CC(UnkAF8CC* obj) {
    u8 f;
    u8 fd;
    s32 v;
    u32 r;
    union {
        u32 w;
        struct {
            u32 pad : 10;
            u32 b21 : 1;
            u32 b20 : 1;
            u32 b19 : 1;
            u32 face : 1;
            u32 dir : 2;
            u32 pad2 : 15;
            u32 b0 : 1;
        } f;
    } fl;

    switch (obj->unk012) {
    case 0:
        obj->unk068 = 0;
        obj->unk06C = 0;
        obj->unk0DC = 0;
        obj->unk0DE = 0;
        obj->unk104 &= ~1;
        obj->unk118 = 0;
        obj->unk101 = 0xF;
        if ((obj->unk117 & 4) && obj->unk0FD == 8) {
            obj->unk117 |= 2;
            obj->unk0FC = obj->unk0FD;
            fn_800B9F74(obj, lbl_8027EB60[obj->unk009][obj->unk0FC]);
        } else if (obj->unk0FC != 8) {
            obj->unk0FC = 0x18;
            fn_800B9F74(obj, lbl_8027EB60[obj->unk009][0x18]);
        }
        if (obj->unk117 & 2) {
            obj->unk108 = 0xFF;
        } else {
            obj->unk108 = 4;
        }
        if (obj->unk117 & 1) {
            obj->unk0ED = obj->unk012;
            obj->unk012 = 1;
            obj->unk0EE = obj->unk013;
            obj->unk013 = 0;
        } else {
            obj->unk0ED = obj->unk012;
            obj->unk012 = 2;
            obj->unk0EE = obj->unk013;
            obj->unk013 = 0;
        }
    case 1:
        if (obj->unk012 == 1) {
            obj->unk104 |= 2;
            break;
        }
    case 2:
        if (obj->unk013 == 0) {
            fn_800AF680(obj);
            break;
        }
        v = obj->unk0E4;
        obj->unk104 |= 2;
        if (v != 0) {
            obj->x += v;
            fl.w = 0;
            fl.f.dir = ((((obj->unk00A >> 3) & 2) - 1) * (v != 0 ? ((v >> 31) * 2 + 1) : 0) < 0) ? 3 : 2;
            fl.f.b0 = 1;
            fl.f.face = (obj->unk00A & 0x10) != 0;
            fl.f.b21 = 1;
            fl.f.b19 = 1;
            fn_800B7A28(&obj->x, obj->unk0C8, &obj->unk19C, obj->unk19C, obj->unk1A0, fl.w);
        }
        obj->y += obj->unk06C;
        fn_800B4C40(obj);
        r = fn_800B7A28(&obj->x, obj->unk0C8, &obj->unk19C, obj->unk19C, obj->unk1A0, ((obj->unk00A & 0x10) << 14) | 0x280001);
        if ((r & 0xF) != 0 || (r & 0x40) == 0x40) {
            obj->unk0EE = obj->unk013;
            obj->unk013 = 0;
            obj->unk104 &= ~2;
        }
        break;
    }
    fn_800BA334(obj, obj->unk115, 0);
    if (obj->unk0A9 < obj->unk11C) {
        obj->unk0A9 = 0;
    } else {
        obj->unk0A9 -= obj->unk11C;
    }
    fn_800BA1A8(obj, obj->unk0A9);
}
