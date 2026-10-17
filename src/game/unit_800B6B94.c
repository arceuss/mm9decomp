#include "types.h"

typedef struct UnkB6B94Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} UnkB6B94Pos;

typedef struct UnkB6B94Box {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u8 pad8[0x5C - 0x8];
} UnkB6B94Box;

typedef struct UnkB6B94 {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 unkA;
    /* 0x00B */ u8 padB[0x11 - 0xB];
    /* 0x011 */ u8 unk11;
    /* 0x012 */ u8 pad12[0x60 - 0x12];
    /* 0x060 */ UnkB6B94Pos pos;
    /* 0x068 */ u8 pad68[0xC8 - 0x68];
    /* 0x0C8 */ UnkB6B94Pos unkC8;
    /* 0x0D0 */ UnkB6B94Pos unkD0;
    /* 0x0D8 */ u8 padD8[0x104 - 0xD8];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x19C - 0x108];
    /* 0x19C */ UnkB6B94Box box;
} UnkB6B94;

u32 fn_800B7A28(UnkB6B94Pos* pos, UnkB6B94Pos* vel, UnkB6B94Box* box, u32 a, u32 b, u32 flags);

#define HIT(r) (((r) & 0xF) || ((r) & 0x40) == 0x40)

s32 fn_800B6B94(UnkB6B94* obj) {
    UnkB6B94Pos saved;
    UnkB6B94Box box;
    s32 nf;
    u32 face;
    UnkB6B94Pos* vel;
    u32 r;

    if (!((1 << obj->unk11) & ~0x1700)) {
        return 0;
    }
    box = obj->box;
    nf = !(obj->unk104 & 2);
    face = ((obj->unkA >> 4) & 1) << 13;
    vel = &obj->unkD0;
    r = fn_800B7A28(&obj->pos, vel, &box, box.unk0, box.unk4, nf ? (face | 0x80000) : (face | 0x280000));
    if (HIT(r)) {
        fn_800B7A28(&obj->pos, vel, &box, box.unk0, box.unk4, nf ? (face | 0x90000) : (face | 0x290000));
    } else {
        r = fn_800B7A28(&obj->pos, vel, &box, box.unk0, box.unk4, nf ? (face | 0x90000) : (face | 0x290000));
        saved = obj->pos;
        if (HIT(r)) {
            r = fn_800B7A28(&obj->pos, vel, &box, box.unk0, box.unk4, nf ? (face | 0x80000) : (face | 0x280000));
            if (HIT(r) && (r & 0x80) == 0x80) {
                obj->pos = saved;
                obj->unkC8 = saved;
                *vel = saved;
            }
        }
    }
    r = fn_800B7A28(&obj->pos, vel, &box, box.unk0, box.unk4, nf ? (face | 0xA0000) : (face | 0x2A0000));
    if (HIT(r)) {
        fn_800B7A28(&obj->pos, vel, &box, box.unk0, box.unk4, nf ? (face | 0xB0000) : (face | 0x2B0000));
    } else {
        r = fn_800B7A28(&obj->pos, vel, &box, box.unk0, box.unk4, nf ? (face | 0xB0000) : (face | 0x2B0000));
        if (HIT(r)) {
            fn_800B7A28(&obj->pos, vel, &box, box.unk0, box.unk4, nf ? (face | 0xA0000) : (face | 0x2A0000));
        }
    }
    return 0;
}
