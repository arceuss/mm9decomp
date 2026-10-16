#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk800B3B3C {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 flagsA;
    /* 0x00B */ u8 padB[0x11 - 0xB];
    /* 0x011 */ u8 state;
    /* 0x012 */ u8 pad12[0x60 - 0x12];
    /* 0x060 */ Vec2i pos;
    /* 0x068 */ u8 pad68[0xC8 - 0x68];
    /* 0x0C8 */ Vec2i prevPos;
    /* 0x0D0 */ Vec2i curPos;
    /* 0x0D8 */ u8 padD8[0x104 - 0xD8];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x124 - 0x108];
    /* 0x124 */ s32 unk124;
    /* 0x128 */ u8 pad128[0x19C - 0x128];
    /* 0x19C */ s32 unk19C;
    /* 0x1A0 */ s32 unk1A0;
    /* 0x1A4 */ s32 unk1A4;
    /* 0x1A8 */ u8 pad1A8[0x1F4 - 0x1A8];
    /* 0x1F4 */ u8 unk1F4;
    /* 0x1F5 */ u8 unk1F5;
} Unk800B3B3C;

void fn_800B73B8(Unk800B3B3C* p);
void fn_800B7684(Unk800B3B3C* p);
void fn_800B96E0(Vec2i* pos, s32* bounds, u32 facing);

void fn_800B3B3C(Unk800B3B3C* p) {
    s32* bounds;

    p->unk124 = 0;
    fn_800B73B8(p);
    p->unk1A0 = p->unk1A4;
    bounds = &p->unk19C;
    p->unk1A4 = *bounds;
    p->prevPos = p->curPos;
    p->curPos = p->pos;
    p->unk1F5 = p->unk1F4;
    fn_800B7684(p);
    p->unk104 &= ~0x2A0;
    p->unk104 &= ~0x540;
    if (((1 << p->state) & 0x7013) && !(p->unk104 & 2)) {
        fn_800B96E0(&p->pos, bounds, (p->flagsA >> 4) & 1);
    }
}
