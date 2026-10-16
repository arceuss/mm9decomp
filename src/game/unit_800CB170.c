#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct TilePatch {
    /* 0x0 */ u16 w;
    /* 0x2 */ u16 h;
    /* 0x4 */ u16 tiles[4];
} TilePatch;

typedef struct Unk800CB170 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xAB - 0x68];
    /* 0xAB */ u8 hitHi : 4;
    /* 0xAB */ u8 hitType : 4;
} Unk800CB170;

extern void** lbl_80280390[];

u16 fn_800A32FC(s32 x, s32 y);
u32 fn_8009E850(s32 x, s32 y);
void fn_8009EF24(s32 tx, s32 ty, TilePatch* patch);
void fn_80040AD0(s32 arg0, Vec2i* pos, s32 arg2, s32 arg3);
void fn_800D5234(s32 id);
void fn_800E9244(Unk800CB170* obj);

static inline void SetMode(Unk800CB170* obj, u8 mode) {
    obj->unk18 = lbl_80280390[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800CB170(Unk800CB170* obj) {
    TilePatch patch;
    Vec2i pos;
    u16 base;
    s32 tx;
    s32 ty;

    switch (obj->step) {
    case 0:
        if (fn_800A32FC(obj->x, obj->y) == 0) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
            break;
        }
        obj->step++;
    case 1:
        if (obj->hitType == 6) {
            base = fn_8009E850(obj->x, obj->y);
            tx = obj->x >> 12;
            ty = obj->y >> 12;
            patch.w = 2;
            patch.h = 2;
            patch.tiles[0] = base + 4;
            patch.tiles[1] = base + 5;
            patch.tiles[2] = base + 6;
            patch.tiles[3] = base + 7;
            fn_8009EF24(tx, ty, &patch);
            pos.x = obj->x + 0x800;
            pos.y = obj->y + 0x800;
            fn_80040AD0(3, &pos, 0, 0);
            fn_800D5234(0x13);
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
        }
        break;
    }
}
