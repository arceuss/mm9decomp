#include "types.h"

typedef struct UnkBEB40 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 padC[0x14 - 0xC];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x18 - 0x16];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2A - 0x22];
    /* 0x2A */ u16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ void* unk34;
    /* 0x38 */ void* unk38;
    /* 0x3C */ u8 pad3C[0xCA - 0x3C];
    /* 0xCA */ u8 unkCA;
    /* 0xCB */ u8 unkCB;
    /* 0xCC */ u8 unkCC;
} UnkBEB40;

extern void* lbl_804EE8C0;
extern u8 lbl_8027F228[0x28];

UnkBEB40* fn_800E8C44(void* pool);
void fn_800BBBFC(void*, s32);

UnkBEB40* fn_800BEB40(UnkBEB40* rec, s32 v) {
    UnkBEB40* f = rec->unk34;
    UnkBEB40* r = fn_800E8C44(lbl_804EE8C0);
    if (r != NULL) {
        r->unk38 = rec;
        r->unk34 = f;
        r->unk14 = 1;
        r->unk9 = 4;
        r->unk18 = *(u32*)(*(u32**)(lbl_8027F228 + 0x10));
        fn_800BBBFC(r, 0);
        r->unk2E = 0x10;
        r->unk2A = 0;
        r->unk2C = 0;
        r->unk2F = 0;
        r->unkB = r->unkB & 0xDF;
        r->unk21 = r->unk20;
        r->unkCA = rec->unkCA;
        r->unkCB = v;
    }
    return r;
}
