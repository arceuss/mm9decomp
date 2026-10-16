#include "types.h"

typedef struct Vec2s {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
} Vec2s;

typedef struct Unk800BE1BCParent {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x60 - 0xB];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
} Unk800BE1BCParent;

typedef struct Unk800BE1BC {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800BE1BCParent* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ struct {
        u32 hi : 21;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0xAC - 0x70];
    /* 0xAC */ void (*unkAC)(struct Unk800BE1BC* obj);
} Unk800BE1BC;

extern u8 lbl_804ECF20[4][2];
extern Vec2s* lbl_804ECF18[2];
extern void (*lbl_804ECF00[2])(Unk800BE1BC* obj);
extern void (*lbl_804ECF08[2])(Unk800BE1BC* obj);
extern void** lbl_8027F228[];

void fn_800E9810(Unk800BE1BC* obj, u16 id);
void fn_800E9A84(Unk800BE1BC* obj, u16 id);
void fn_800E9424(Unk800BE1BC* obj, u16 id);
void fn_800E946C(Unk800BE1BC* obj, u8 anim);
void fn_800E91F0(Unk800BE1BC* obj, void* data, s32 arg2);
void fn_800BEA78(Unk800BE1BC* obj);
BOOL fn_800BE7C4(Unk800BE1BC* obj);

void fn_800BE1BC(Unk800BE1BC* obj) {
    Unk800BE1BCParent* parent;
    u32 v;
    u32 f;
    s32 dir;
    Vec2s* off;

    fn_800E9810(obj, 0x141);
    fn_800E9A84(obj, 0x144);
    v = obj->unk14;
    fn_800E9424(obj, 0x103);
    obj->unk16 = 0;
    fn_800E946C(obj, lbl_804ECF20[v][0]);
    parent = obj->parent;
    obj->flagsA |= 3;
    v = obj->unk17;
    fn_800E91F0(obj, NULL, 0);
    obj->unkAC = fn_800BEA78;
    f = (parent->flagsA >> 4) & 1;
    if (f) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
    obj->bits54.flip = f;
    dir = (f == 1) * 2 - 1;
    obj->vy = 0;
    obj->vx = 0xC0 * dir;
    if (parent->kind == 2) {
        off = &lbl_804ECF18[obj->unk15 + 1][v];
    } else {
        off = &lbl_804ECF18[obj->unk15][v];
    }
    obj->x = parent->x + (dir * off->x - obj->vx);
    obj->y = parent->y + off->y;
    obj->unk18 = lbl_8027F228[obj->kind][1];
    obj->unk10 = 1;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = 0;
    if (!fn_800BE7C4(obj)) {
        lbl_804ECF00[obj->state](obj);
        lbl_804ECF08[obj->state](obj);
    }
}
