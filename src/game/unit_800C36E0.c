#include "types.h"

typedef struct Unk8027F3C8Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk8027F3C8Entry;

typedef struct Unk800C36E0 {
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
} Unk800C36E0;

extern Unk8027F3C8Entry* lbl_8027F3C8[];
extern u8 lbl_804ECFA0[8];

void fn_800E9424(Unk800C36E0* obj, u16 bank);
void fn_800E946C(Unk800C36E0* obj, u8 anim);
u16 fn_800A3458(s32 x, s32 y);
BOOL fn_800C3E4C(Unk800C36E0* obj);
s32 fn_800A507C(s32 x, s32 y);
void fn_800C3D38(Unk800C36E0* obj);
BOOL fn_800B6010(void* parent, Unk800C36E0* obj);
void fn_800C3354(Unk800C36E0* obj);
void fn_800E9750(Unk800C36E0* obj, u16 arg1);

static inline void SetAnim(Unk800C36E0* obj, u8 anim) {
    if (obj->bank != 0x108) {
        fn_800E9424(obj, 0x108);
    }
    obj->anim = anim;
    fn_800E946C(obj, anim);
}

static inline void SetBox(Unk800C36E0* obj, void* box, u16 v) {
    obj->flagsB |= 0x10;
    obj->unk3C = box;
    obj->unk30 = v;
}

static inline BOOL Blocked(Unk800C36E0* obj) {
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

void fn_800C36E0(Unk800C36E0* obj) {
    void* parent = obj->parent;

    if (obj->step == 0) {
        SetAnim(obj, 2);
        SetBox(obj, lbl_804ECFA0, 0x2001);
        obj->flagsA &= 0xEF;
        obj->flipX = 0;
        if (obj->unkCC != 0 && !Blocked(obj)) {
            obj->step = 1;
        } else {
            obj->step = 3;
        }
    }
    switch (obj->step) {
    case 1:
        obj->vy = 0;
        obj->timer = 8;
        obj->step++;
    case 2:
        if (obj->timer == 0) {
            obj->y += obj->vy;
            if (fn_800C3E4C(obj)) {
                obj->step++;
            }
            obj->vy += obj->ay;
            if (obj->vy > 0x700) {
                obj->vy = 0x700;
            }
        } else {
            obj->timer--;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 3:
        obj->timer = 0x78;
        obj->step++;
    case 4:
        obj->vx = fn_800A507C(obj->x, obj->y + 1);
        obj->x += obj->vx;
        fn_800C3D38(obj);
        if (--obj->timer == 0 || !Blocked(obj)) {
            obj->step++;
        } else if (obj->timer < 0x1E) {
            if (obj->anim != 3) {
                SetAnim(obj, 3);
            }
        } else if (fn_800B6010(parent, obj)) {
            obj->timer = 0x1E;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 5:
        SetAnim(obj, 4);
        obj->timer = 8;
        obj->flagsB &= 0xEF;
        obj->step++;
    case 6:
        if (--obj->timer == 0) {
            obj->unk18 = lbl_8027F3C8[obj->kind]->unk8;
            obj->unk10 = 2;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
            fn_800C3354(obj);
        } else {
            fn_800E9750(obj, 0xFFFF);
        }
        break;
    }
}
