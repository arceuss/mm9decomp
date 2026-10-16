#include "types.h"

typedef struct Unk800BEA7C {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0xB - 0xA];
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x14 - 0xC];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x18 - 0x16];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2A - 0x22];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ void* unk34;
    /* 0x38 */ u8 pad38[0xC9 - 0x38];
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 unkCA;
} Unk800BEA7C;

typedef struct Unk800BEA7CPlayer {
    /* 0x000 */ u8 pad0[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} Unk800BEA7CPlayer;

extern u8 lbl_804EE8D8[8];
extern void* lbl_804EE8C0;
extern s32* lbl_8027F228[];

Unk800BEA7C* fn_800E8C44(void* pool);
void fn_800BBBFC(Unk800BEA7C* obj, s32 arg1);

Unk800BEA7C* fn_800BEA7C(Unk800BEA7CPlayer* p, s32 a1, u8 kind, u8 cost, u8 a4) {
    Unk800BEA7C* obj = fn_800E8C44(lbl_804EE8C0);

    if (obj != NULL) {
        obj->unk9 = 4;
        obj->unk14 = lbl_804EE8D8[kind];
        obj->unk15 = kind;
        obj->unk34 = p;
        obj->unk18 = *lbl_8027F228[obj->unk9];
        fn_800BBBFC(obj, 0);
        obj->unk2E = 0x10;
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->flagsB &= 0xDF;
        obj->unk21 = obj->unk20;
        obj->unkC9 = cost;
        p->unk1F8 += cost;
        obj->unkCA = a4;
    }
    return obj;
}
