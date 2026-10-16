#include "game/work_8031BF70.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800CF398 {
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
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
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
    /* 0x34 */ struct Unk800CF398* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ u8 unkC8;
} Unk800CF398;

extern Unk80280390Entry* lbl_80280390[];

extern u8 lbl_8027D2D8[];
extern u8 lbl_8027FB50[];
extern void (*lbl_804ED058[2])(Unk800CF398* obj);

void fn_800E9424(Unk800CF398* obj, s32 id);

static inline s32 TileIndex(s32 x, s32 y) {
    u8* map = lbl_8031BF70.unk288->unkF4;

    return (x >> 16) + (lbl_8027D2D8[y >> 12] << map[0]);
}

void fn_800CF398(Unk800CF398* obj) {
    obj->unk18 = lbl_80280390[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = 0;
    if ((lbl_8031BF70.unk28C & 0x7F) == 0xD) {
        obj->unk15 = lbl_8027FB50[TileIndex(obj->unk60, obj->unk64)];
        obj->unk2F = obj->unk15 >> 4;
        fn_800E9424(obj, 0x4C);
    } else {
        obj->unk15 = 0;
        fn_800E9424(obj, 0x27);
    }
    obj->flagsA |= 2;
    lbl_804ED058[obj->state](obj);
}
