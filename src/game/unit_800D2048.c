#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} Unk80280390Entry;

typedef struct Unk800D2048Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800D2048Pos;

typedef struct Unk800D2048 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
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
    /* 0x34 */ struct Unk800D2048* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ Unk800D2048Pos pos;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(struct Unk800D2048*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
} Unk800D2048;

extern Unk80280390Entry* lbl_80280390[];
extern u8 lbl_80280258[];
extern u8 lbl_80280240[];
extern void* lbl_804EE908;

Unk800D2048* fn_800E8C44(void* pool);
void fn_800E9424(Unk800D2048* obj, u16 anim);
void fn_800E91F0(Unk800D2048* obj, void* data, s32 arg2);
void fn_800D24BC(Unk800D2048* obj);
void fn_800D21FC(Unk800D2048* obj);

static inline void Spawn(Unk800D2048* obj, Unk800D2048Pos pos, u8 n) {
    Unk800D2048* child = fn_800E8C44(lbl_804EE908);

    if (child != NULL) {
        child->unk2E = 0x10;
        child->unk9 = 0xE;
        child->unk18 = lbl_80280390[0xE]->unk0;
        child->unk2A = 0;
        child->unk2C = 0;
        child->unk2F = 0;
        child->flagsB |= 0x20;
        child->unk21 = child->unk20;
        child->parent = obj;
        child->pos.x = pos.x;
        child->pos.y = pos.y + n * 0x1700;
        child->unk14 = n;
        child->unkC8 = obj->unkC8;
    }
}

void fn_800D2048(Unk800D2048* obj) {
    Unk800D2048Pos pos;
    u32 i;

    if (obj->unk14 == 0) {
        fn_800E9424(obj, 0x32);
        obj->flagsA |= 1;
        fn_800E91F0(obj, lbl_80280258, 0);
        obj->unkAC = fn_800D24BC;
        obj->unk18 = lbl_80280390[obj->unk9]->unk4;
        obj->unk10 = 1;
        obj->unk13 = 0;
        obj->state = 0;
        obj->step = 0;
        pos = obj->pos;
        for (i = 0; i < 5; i++) {
            Spawn(obj, pos, (u8)i + 1);
        }
    } else {
        fn_800E9424(obj, 0x32);
        obj->flagsA |= 1;
        fn_800E91F0(obj, lbl_80280240, 0);
        obj->unkAC = fn_800D24BC;
        obj->unk18 = lbl_80280390[obj->unk9]->unk4;
        obj->unk10 = 1;
        obj->unk13 = 0;
        obj->state = 1;
        obj->step = 0;
    }
    fn_800D21FC(obj);
}
