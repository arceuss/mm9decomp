#include "types.h"

typedef struct Unk800C0788Owner {
    /* 0x000 */ u8 pad0[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} Unk800C0788Owner;

typedef struct Unk800C0788 {
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
    /* 0x34 */ Unk800C0788Owner* owner;
    /* 0x38 */ u8 pad38[0xC9 - 0x38];
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 unkCA;
} Unk800C0788;

typedef struct Unk8027F228Entry {
    /* 0x0 */ s32 unk0;
} Unk8027F228Entry;

extern void* lbl_804EE8C0;
extern const u8 lbl_804EE8F0[8];
extern Unk8027F228Entry* lbl_8027F228[10];

Unk800C0788* fn_800E8C44(void* pool);
void fn_800BBBFC(Unk800C0788* obj, s32 arg1);

static inline void SetKind(Unk800C0788* obj, u8 kind) {
    obj->unk9 = kind;
    obj->unk18 = lbl_8027F228[obj->unk9]->unk0;
}

Unk800C0788* fn_800C0788(Unk800C0788Owner* owner, u8 arg1, u8 kind, u8 arg3, u8 arg4) {
    Unk800C0788* obj = fn_800E8C44(lbl_804EE8C0);

    if (obj != NULL) {
        obj->owner = owner;
        obj->unk15 = kind;
        obj->unk14 = lbl_804EE8F0[kind];
        obj->unk17 = arg1;
        SetKind(obj, 7);
        fn_800BBBFC(obj, 0);
        obj->unk2E = 0x10;
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->flagsB &= 0xDF;
        obj->unk21 = obj->unk20;
        obj->unkC9 = arg3;
        owner->unk1F8 = arg3 + owner->unk1F8;
        obj->unkCA = arg4;
    }
    return obj;
}
