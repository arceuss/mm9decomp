#include "types.h"

typedef struct Unk8027F3C8Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk8027F3C8Entry;

typedef struct Unk800C341C {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 anim;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x24 - 0x1C];
    /* 0x24 */ u16 bank;
    /* 0x26 */ u8 pad26[0x30 - 0x26];
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u8 pad32[0x34 - 0x32];
    /* 0x34 */ void* parent;
    /* 0x38 */ u8 pad38[0x3C - 0x38];
    /* 0x3C */ void* unk3C;
    /* 0x40 */ u8 pad40[0x54 - 0x40];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 ay;
    /* 0x78 */ u8 pad78[0xCB - 0x78];
    /* 0xCB */ u8 timer;
    /* 0xCC */ u8 unkCC;
} Unk800C341C;

extern Unk8027F3C8Entry* lbl_8027F3C8[];
extern u8 lbl_804ECFA0[8];

void fn_800E9424(Unk800C341C* obj, u16 bank);
void fn_800E946C(Unk800C341C* obj, u8 anim);
u16 fn_800A3458(s32 x, s32 y);
BOOL fn_800C3E4C(Unk800C341C* obj);
s32 fn_800A507C(s32 x, s32 y);
s32 fn_800C3D38(Unk800C341C* obj);
BOOL fn_800B6010(void* parent, Unk800C341C* obj);
void fn_800C3354(Unk800C341C* obj);
void fn_800E9750(Unk800C341C* obj, u16 arg1);

static inline void SetAnim(Unk800C341C* obj, u8 anim) {
    if (obj->bank != 0x108) {
        fn_800E9424(obj, 0x108);
    }
    obj->anim = anim;
    fn_800E946C(obj, anim);
}

static inline void SetBox(Unk800C341C* obj, void* box, u16 v) {
    obj->flagsB |= 0x10;
    obj->unk3C = box;
    obj->unk30 = v;
}

static inline BOOL Blocked(Unk800C341C* obj) {
    if (fn_800A3458(obj->x - 0x800, obj->y - 0x800)) {
        return TRUE;
    }
    if (fn_800A3458(obj->x - 0x800, obj->y + 0x800)) {
        return TRUE;
    }
    if (fn_800A3458(obj->x + 0x800, obj->y + 0x800)) {
        return TRUE;
    }
    return fn_800A3458(obj->x + 0x800, obj->y - 0x800) != 0;
}

extern u8 lbl_80304B90[0x300];
u32 fn_80080484(void*, void*, s32);

void fn_800C341C(Unk800C341C* obj) {
    s32 hit;

    switch (obj->step) {
    case 0:
        SetAnim(obj, 0);
        obj->step++;
    case 1:
        obj->x += obj->vx;
        hit = fn_800C3D38(obj);
        obj->y += obj->vy;
        hit |= fn_800C3E4C(obj);
        if (hit && Blocked(obj)) {
            if (fn_80080484(lbl_80304B90 + 0x21C, &obj->x, 1) > 0x400) {
                obj->unk18 = lbl_8027F3C8[obj->kind]->unk8;
                obj->unk10 = 2;
                obj->state = 0;
                obj->step = 0;
                obj->unk13 = 0;
                fn_800C3354(obj);
                return;
            }
            obj->state = 1;
            obj->step = 0;
        }
        obj->vy += obj->ay;
        if (obj->vy > 0x700) {
            obj->vy = 0x700;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
