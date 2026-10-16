#include "types.h"

typedef struct Unk800C3060 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x34 - 0x22];
    /* 0x34 */ struct Unk800C3060* unk34;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 unk54_b10 : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0xAC - 0x78];
    /* 0xAC */ void* unkAC;
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 padC9[0xCC - 0xC9];
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 unkCD;
} Unk800C3060;

typedef struct Unk3C8Entry {
    /* 0x0 */ u8 pad0[4];
    /* 0x4 */ u32 unk4;
} Unk3C8Entry;

extern u8 lbl_8027F250[];
extern u8 lbl_8027F3C8[];

void fn_800E9810(void* obj, s32 v);
void fn_800E9A84(void* obj, s32 v);
void fn_800E9424(void* obj, s32 v);
void fn_800E946C(void* obj, s32 v);
void fn_800D5234(s32 v);
void fn_800E91F0(void* obj, void* p, s32 v);
u16 fn_800A3458(s32 a, s32 b);
s32 fn_800C3B24(void* obj, s32 a, s32 b);
void fn_800C3D14(void);

void fn_800C3060(Unk800C3060* obj) {
    u8* base;
    Unk800C3060* parent;
    u8 idx;
    u8 flag;
    u32 t;
    s32 dir;
    u8* p;

    base = lbl_8027F250;
    flag = 0;
    obj->unkC8 = 0;
    fn_800E9810(obj, 0x141);
    fn_800E9A84(obj, 0x144);
    fn_800E9424(obj, 0x108);
    obj->unk16 = 0;
    fn_800E946C(obj, 0);
    parent = obj->unk34;
    obj->unkA |= 3;
    idx = obj->unk17;
    fn_800D5234(0x2E);
    fn_800E91F0(obj, base + 0x30, 0);
    obj->unk21 = obj->unk20;
    obj->unkB &= 0xDF;
    obj->unkAC = (void*)fn_800C3D14;
    t = (parent->unkA >> 4) & 1;
    if (t != 0) {
        obj->unkA |= 0x10;
    } else {
        obj->unkA &= 0xEF;
    }
    dir = 2 * (t == 1) - 1;
    obj->unk54_b10 = t;
    obj->unk6C = 0;
    obj->unk68 = 0x380 * dir;
    p = base + 0x60 + idx * 4;
    obj->unk74 = 0x40;
    if (parent->unk9 == 2) {
        p = base + 0x70 + idx * 4;
    }
    obj->unk60 = parent->unk60 + (dir * *(s16*)p - obj->unk68);
    obj->unk64 = parent->unk64 + *(s16*)(p + 2);
    obj->unkCC = 0;
    obj->unkCD = 0;
    if (fn_800A3458(obj->unk60 - 0x7FF, obj->unk64 - 0x7FF) != 0
     || fn_800A3458(obj->unk60 - 0x7FF, obj->unk64 + 0x7FF) != 0
     || fn_800A3458(obj->unk60 + 0x7FF, obj->unk64 + 0x7FF) != 0
     || fn_800A3458(obj->unk60 + 0x7FF, obj->unk64 - 0x7FF) != 0) {
        flag = 1;
    }
    obj->unk18 = ((Unk3C8Entry**)lbl_8027F3C8)[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->unk12 = 0;
    obj->unk13 = 0;
    obj->unk11 = flag;
    if (fn_800C3B24(obj, 1, obj->unk18) == 0) {
        ((void (*)(void*, void*))((void**)(base + 0x14))[obj->unk11])(obj, base + 0x14);
        ((void (*)(void*, void*))((void**)(base + 0x20))[obj->unk11])(obj, base + 0x20);
    }
}
