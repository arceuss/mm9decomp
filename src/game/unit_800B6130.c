#include "types.h"

typedef struct Unk19C_6130 {
    /* 0x00 */ u8 pad[0x5C];
} Unk19C_6130;

typedef struct UnkB6130 {
    /* 0x000 */ u8 pad000[0x0A];
    /* 0x00A */ u8 unk0A;
    /* 0x00B */ u8 pad00B[0x60 - 0x0B];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 pad068[0x104 - 0x68];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x19C - 0x108];
    /* 0x19C */ Unk19C_6130 unk19C;
} UnkB6130;

void fn_800B7A28(void*, void*, void*, u32, u32, u32);
void fn_800B8F08(s32*, void*, s32*, u32);

s32 fn_800B6130(UnkB6130* obj, s32* a) {
    Unk19C_6130 c;
    s32 pos[2];
    u32 flags;

    c = *(Unk19C_6130*)((u8*)obj + 0x19C);
    pos[0] = obj->unk60;
    pos[0] += a[0];
    pos[1] = obj->unk64;
    pos[1] += a[1];
    if (obj->unk104 & 2) {
        flags = ((obj->unk0A << 14) & 0x40000) | 0x290001;
    } else {
        flags = ((obj->unk0A << 14) & 0x40000) | 0x090001;
    }
    fn_800B7A28(pos, (u8*)obj + 0x60, (s32*)&c, ((u32*)&c)[0], ((u32*)&c)[1], flags);
    fn_800B8F08(pos, &c, (s32*)((u32*)&c)[0], 0x90000);
    return pos[1] - (obj->unk64 + a[1]);
}
