#include "types.h"

typedef struct UnkB6228Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} UnkB6228Pos;

typedef struct UnkB6228Box {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u8 pad8[0xC - 0x8];
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x5C - 0x1C];
} UnkB6228Box;

typedef struct UnkB6228 {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 unkA;
    /* 0x00B */ u8 padB[0x60 - 0xB];
    /* 0x060 */ UnkB6228Pos pos;
    /* 0x068 */ u8 pad68[0x104 - 0x68];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x19C - 0x108];
    /* 0x19C */ UnkB6228Box box;
} UnkB6228;

u32 fn_800B7A28(UnkB6228Pos* pos, UnkB6228Pos* vel, UnkB6228Box* box, u32 a, u32 b, u32 flags);

s32 fn_800B6228(UnkB6228* obj, UnkB6228Pos* d, s32 v) {
    UnkB6228Pos p;
    UnkB6228Box box;
    u32 flags;

    box = obj->box;
    box.unkC = 0;
    box.unk10 = 0;
    box.unk14 = 0;
    box.unk18 = 0;
    p.x = obj->pos.x;
    p.x += d->x;
    p.y = obj->pos.y;
    p.y += d->y;
    if (obj->unk104 & 2) {
        flags = ((((((obj->unkA & 0x10) != 0) << 1) - 1) * (v != 0 ? ((v >> 31) * 2 + 1) : 0) < 0 ? 3 : 2) << 16) | 1 |
                ((obj->unkA & 0x10) << 14) | 0x280000;
    } else {
        flags = ((((((obj->unkA & 0x10) != 0) << 1) - 1) * (v != 0 ? ((v >> 31) * 2 + 1) : 0) < 0 ? 3 : 2) << 16) | 1 |
                ((obj->unkA & 0x10) << 14) | 0x80000;
    }
    fn_800B7A28(&p, &obj->pos, &box, box.unk0, box.unk4, flags);
    return p.x - (obj->pos.x + d->x);
}
