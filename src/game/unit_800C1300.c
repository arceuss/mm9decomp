#include "types.h"

typedef struct Unk800C1300Parent {
    /* 0x000 */ u8 pad0[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} Unk800C1300Parent;

typedef struct Unk800C1300Entry {
    /* 0x00 */ u32 unk0;
} Unk800C1300Entry;

typedef struct Unk800C1300 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 pad0C[0x14 - 0x0C];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u32 unk18;
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
    /* 0x34 */ Unk800C1300Parent* unk34;
} Unk800C1300;

extern void* lbl_804EE8C0;
extern Unk800C1300Entry* lbl_8027F228[];

void* fn_800E8C44(void* mgr);
void fn_800BBBFC(Unk800C1300* work, s32 arg);

Unk800C1300* fn_800C1300(Unk800C1300Parent* parent) {
    Unk800C1300* obj = fn_800E8C44(lbl_804EE8C0);

    if (obj != NULL) {
        obj->unk34 = parent;
        obj->unk9 = 8;
        obj->unk18 = lbl_8027F228[8]->unk0;
        fn_800BBBFC(obj, 0);
        obj->unk2E = 0x10;
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->unkB &= 0xDF;
        obj->unk21 = obj->unk20;
    }
    return obj;
}
