#include "types.h"

typedef struct Unk800C4ABC {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x18 - 0x17];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x24 - 0x1C];
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u8 pad26[0x34 - 0x26];
    /* 0x34 */ u8* parent;
    /* 0x38 */ u8 pad38[0x50 - 0x38];
    /* 0x50 */ struct {
        u32 hi : 30;
        u32 lo : 2;
    } unk50;
    /* 0x54 */ u8 pad54[0x60 - 0x54];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 ay;
    /* 0x78 */ u8 pad78[0x7F - 0x78];
    /* 0x7F */ u8 unk7F;
} Unk800C4ABC;

typedef struct Unk8027F3C8 {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ s32 unk10;
} Unk8027F3C8;

typedef struct Unk8027F330 {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk8027F330;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x260];
    /* 0x260 */ s32 unk260;
} Unk80304B90;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern Unk8027F3C8* lbl_8027F3C8[];
extern u16 lbl_8027F308[];
extern Unk8027F330 lbl_8027F330[4];
extern Unk80304B90 lbl_80304B90;

s32 fn_800B58F8(u8* parent, s32 arg1);
void fn_80040AD0(s32 arg0, Vec2i* pos, s32 arg2, s32 arg3);
void fn_800E9244(Unk800C4ABC* obj);
void fn_800E9A84(Unk800C4ABC* obj, s32 id);
void fn_800E9810(Unk800C4ABC* obj, s32 id);
void fn_800E9424(Unk800C4ABC* obj, u16 anim);
void fn_800E946C(Unk800C4ABC* obj, u8 arg1);
u16 fn_8009E894(s32 x, s32 y);
void fn_800E9750(Unk800C4ABC* obj, u16 arg1);

static inline void Probe(Unk800C4ABC* obj) {
    s32 dir;
    s32 i;

    dir = ((obj->unkA >> 3) & 2) - 1;
    obj->unk50.lo = 2;
    if (obj->unk24 == 0x109 || obj->unk24 == 0x181) {
        for (i = 0; i < 4; i++) {
            if (fn_8009E894(obj->x + dir * lbl_8027F330[i].x, obj->y + lbl_8027F330[i].y) & 0x200) {
                obj->unk50.lo = 3;
                break;
            }
        }
    }
    fn_800E9750(obj, 0xFFFF);
}

static inline void Kill(Unk800C4ABC* obj) {
    obj->unk18 = lbl_8027F3C8[obj->unk9]->unk8;
    obj->unk10 = 2;
    obj->unk11 = 0;
    obj->step = 0;
    obj->unk13 = 0;
    obj->unk18 = lbl_8027F3C8[obj->unk9]->unk10;
    obj->unk10 = 4;
    obj->unk11 = 0;
    obj->step = 0;
    obj->unk13 = 0;
    fn_800E9244(obj);
    obj->unkA &= ~1;
    obj->unkB &= 0xEF;
    obj->parent[0x1F9] = 0;
}

void fn_800C4ABC(Unk800C4ABC* obj) {
    Vec2i pos;
    u8* parent;
    u16 anim;

    if (fn_800B58F8(obj->parent, 2)) {
        pos.x = obj->x;
        pos.y = obj->y - 0xA00;
        fn_80040AD0(4, &pos, 0, 0);
        Kill(obj);
        return;
    }
    switch (obj->step) {
    case 0:
        parent = obj->parent;
        anim = lbl_8027F308[4];
        if (anim == 0) {
            obj->unkB &= 0xFB;
        } else {
            if (fn_800B58F8(parent, 2)) {
                anim = 0x181;
            }
            fn_800E9810(obj, 0x141);
        }
        fn_800E9A84(obj, 0x144);
        if (obj->unk24 != anim) {
            fn_800E9424(obj, anim);
        }
        obj->unk16 = 2;
        fn_800E946C(obj, lbl_8027F308[5]);
        obj->unkB &= 0xEF;
        obj->step++;
    case 1:
        Probe(obj);
        if (obj->unk7F == 3) {
            obj->step++;
        }
        break;
    case 2:
        parent = obj->parent;
        anim = lbl_8027F308[0];
        if (anim == 0) {
            obj->unkB &= 0xFB;
        } else {
            if (fn_800B58F8(parent, 2)) {
                anim = 0x181;
            }
            fn_800E9810(obj, 0x141);
        }
        fn_800E9A84(obj, 0x144);
        if (obj->unk24 != anim) {
            fn_800E9424(obj, anim);
        }
        obj->unk16 = 0;
        fn_800E946C(obj, lbl_8027F308[1]);
        obj->vy = -0x200;
        obj->ay = -0x80;
        obj->step++;
    case 3:
        obj->y += obj->vy;
        if (obj->y < lbl_80304B90.unk260 - 0x7000) {
            Kill(obj);
            break;
        }
        obj->vy += obj->ay;
        if (obj->vy < -0x600) {
            obj->vy = -0x600;
        }
        Probe(obj);
        break;
    }
}
