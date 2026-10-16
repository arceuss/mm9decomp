#include "types.h"

typedef struct Unk800C2FD8Owner {
    /* 0x000 */ u8 pad0[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} Unk800C2FD8Owner;

typedef struct Unk800C2FD8 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x14 - 0xC];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16;
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
    /* 0x34 */ Unk800C2FD8Owner* owner;
    /* 0x38 */ u8 pad38[0xC9 - 0x38];
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 unkCA;
} Unk800C2FD8;

extern void* lbl_804EE8F8;
extern u8 lbl_804EE900[8];

Unk800C2FD8* fn_800E8C44(void* pool);
void fn_800C2F8C(Unk800C2FD8* obj, s32 arg1, s32 arg2);

Unk800C2FD8* fn_800C2FD8(Unk800C2FD8Owner* owner, u8 arg1, u8 kind, u8 arg3, u8 arg4) {
    Unk800C2FD8* obj = fn_800E8C44(lbl_804EE8F8);

    if (obj != NULL) {
        obj->owner = owner;
        obj->unk15 = kind;
        obj->unk14 = lbl_804EE900[kind];
        obj->unk17 = arg1;
        fn_800C2F8C(obj, 0, 0);
        obj->unkC9 = arg3;
        owner->unk1F8 = arg3 + owner->unk1F8;
        obj->unkCA = arg4;
    }
    return obj;
}
