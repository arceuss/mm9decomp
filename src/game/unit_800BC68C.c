#include "types.h"

typedef struct Unk800BC68C {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
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
    /* 0x34 */ struct Unk800BC68C* parent;
    /* 0x38 */ u8 pad38[0xC8 - 0x38];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 padCA;
    /* 0xCB */ u8 unkCB;
    /* 0xCC */ u8 unkCC;
} Unk800BC68C;

typedef struct Unk800BC68CPlayer {
    /* 0x000 */ u8 pad0[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} Unk800BC68CPlayer;

extern s32* lbl_8027F228[10];
extern void* lbl_804EE8C0;
extern const u8 lbl_804ECEF4[4];

Unk800BC68C* fn_800E8C44(void* pool);
void fn_800BBBFC(Unk800BC68C* obj, s32 arg1);

Unk800BC68C* fn_800BC68C(Unk800BC68CPlayer* p, u8 arg2, u8 kind, u8 cost, u8 arg5) {
    Unk800BC68C* obj;
    s32 i = 0;

    do {
        obj = fn_800E8C44(lbl_804EE8C0);
        if (obj == NULL) {
            break;
        }
        obj->parent = (Unk800BC68C*)p;
        obj->unk15 = kind;
        obj->unk14 = lbl_804ECEF4[kind];
        obj->unk17 = arg2;
        obj->unk9 = 1;
        obj->unk18 = *lbl_8027F228[1];
        fn_800BBBFC(obj, 0);
        obj->unk2E = 0x10;
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->flagsB &= 0xDF;
        obj->unk21 = obj->unk20;
        obj->unkCC = i;
        i++;
        obj->unkC9 = cost;
        p->unk1F8 += cost;
        obj->unkCB = arg5;
    } while (i < 3);
    return obj;
}
