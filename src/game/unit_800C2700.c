#include "types.h"

typedef struct Unk800C2700Parent {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 unkA;
    /* 0x00B */ u8 padB[0x60 - 0xB];
    /* 0x060 */ u32 unk60;
    /* 0x064 */ u8 pad64[0x148 - 0x64];
    /* 0x148 */ struct Unk800C2700* unk148;
} Unk800C2700Parent;

typedef struct Unk800C2700 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 padD[0x10 - 0xD];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800C2700Parent* unk34;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 unk54_b10 : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ u32 unk60;
    /* 0x64 */ u32 unk64;
    /* 0x68 */ u8 pad68[0xC9 - 0x68];
    /* 0xC9 */ u8 unkC9;
} Unk800C2700;

typedef struct Unk8027F228Entry {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u32 unk4;
} Unk8027F228Entry;

typedef void (*Unk800C2700Func)(Unk800C2700*);

extern Unk8027F228Entry* lbl_8027F228[];
extern Unk800C2700Func lbl_8027F20C[];
extern Unk800C2700Func lbl_8027F218[];
extern u8 lbl_80304B90[];

void fn_800E9810(Unk800C2700* obj, s32 v);
void fn_800E9424(Unk800C2700* obj, s32 v);
void fn_800E946C(Unk800C2700* obj, s32 v);
void fn_800E9750(Unk800C2700* obj, u16 v);

void fn_800C2700(Unk800C2700* obj) {
    Unk800C2700Parent* p;
    u32 b;

    fn_800E9810(obj, 0x143);
    obj->unkC &= ~1;
    fn_800E9424(obj, 0x10B);
    obj->unk16 = 0;
    fn_800E946C(obj, 0);
    fn_800E9750(obj, 0xFFFF);
    obj->unkA |= 3;
    p = obj->unk34;
    b = (p->unkA >> 4) & 1;
    if (b != 0) {
        obj->unkA |= 0x10;
    } else {
        obj->unkA &= 0xEF;
    }
    obj->unk54_b10 = b;
    obj->unk60 = p->unk60;
    obj->unk64 = *(u32*)(lbl_80304B90 + 0x260) - 0x7000;
    obj->unkC9 = 0;
    obj->unk18 = lbl_8027F228[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->unk12 = 0;
    obj->unk13 = 0;
    obj->unk11 = 0;
    lbl_8027F20C[obj->unk11](obj);
    lbl_8027F218[obj->unk11](obj);
    obj->unk34->unk148 = obj;
}
