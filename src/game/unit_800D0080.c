#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} Unk80280390Entry;

typedef struct Unk800D0080Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800D0080Pos;

typedef struct Unk800D0080 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x12 - 0xC];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 count;
    /* 0x17 */ u8 pad17;
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
    /* 0x34 */ struct Unk800D0080* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 timer;
} Unk800D0080;

extern Unk80280390Entry* lbl_80280390[];
extern u8* lbl_804ED0A0[2];
extern u8 lbl_804ED088[8];
extern Unk800D0080Pos lbl_80280058[];
extern Unk800D0080Pos lbl_80280030[];
extern void* lbl_804EE908;

Unk800D0080* fn_800E8C44(void* pool);
s32 fn_800A36F8(s32 x, s32 y);
s32 fn_800A43B4(s32 x, s32 y);

static inline void Spawn(Unk800D0080* obj, s32 x, s32 y, u8 k) {
    Unk800D0080* child = fn_800E8C44(lbl_804EE908);

    if (child != NULL) {
        child->unk2E = 0x10;
        child->unk9 = 0xA;
        child->unk18 = lbl_80280390[0xA]->unk0;
        child->unk2A = 0;
        child->unk2C = 0;
        child->unk2F = 0;
        child->flagsB |= 0x20;
        child->unk21 = child->unk20;
        child->parent = obj;
        child->x = x;
        child->y = y;
        child->unk14 = k;
    }
}

void fn_800D0080(Unk800D0080* obj) {
    s32 d;

    switch (obj->step) {
    case 0:
        obj->timer = 0x50;
        obj->step++;
    case 1:
        if (obj->timer == 0) {
            if (obj->unk14 & 0x10) {
                d = fn_800A36F8(obj->x, obj->y);
                if (d >= 0) {
                    d = fn_800A43B4(obj->x, obj->y);
                    if (d == 0 || d == 0x7FFFFFFF || d == -1) {
                        d = 0;
                    }
                }
                Spawn(obj, obj->x + lbl_80280058[lbl_804ED0A0[obj->unk14 & 0xF][obj->count]].x,
                      d + lbl_80280058[lbl_804ED0A0[obj->unk14 & 0xF][obj->count]].y,
                      lbl_804ED088[lbl_804ED0A0[obj->unk14 & 0xF][obj->count]]);
            } else {
                Spawn(obj, obj->x + lbl_80280030[lbl_804ED0A0[obj->unk14 & 0xF][obj->count]].x,
                      obj->y + lbl_80280030[lbl_804ED0A0[obj->unk14 & 0xF][obj->count]].y,
                      lbl_804ED088[lbl_804ED0A0[obj->unk14 & 0xF][obj->count]]);
            }
            if (obj->count < 4) {
                obj->count++;
            } else {
                obj->count = 0;
            }
            obj->step = 0;
        } else {
            obj->timer--;
        }
        break;
    }
}
