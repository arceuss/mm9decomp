#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80041028 {
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
    /* 0x34 */ struct Unk80041028* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 flags54_hi : 21;
    /* 0x54 */ u32 flags54_b10 : 1;
    /* 0x54 */ u32 flags54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x88 - 0x68];
    /* 0x88 */ s32 unk88;
    /* 0x8C */ s32 unk8C;
    /* 0x90 */ u8 pad90[0xAC - 0x90];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk80041028;

extern Unk80280390Entry* lbl_80265138[];

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern void* lbl_804EE730;
extern const u16 lbl_804ECA28[4];

Unk80041028* fn_800E8C44(void* pool);
void fn_800E9A84(Unk80041028* obj, s32 arg1);
void fn_800E9424(Unk80041028* obj, s32 id);
void fn_800E946C(Unk80041028* obj, u8 id);

Unk80041028* fn_80041028(u8 arg0, u8 kind, Vec2i* vel, BOOL facing) {
    Unk80041028* obj = fn_800E8C44(lbl_804EE730);

    if (obj != NULL) {
        obj->unk2E = 0x10;
        obj->unk9 = 2;
        obj->unk18 = lbl_80265138[2]->unk0;
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->flagsB |= 0x20;
        obj->unk21 = obj->unk20;
        obj->unk88 = vel->x;
        obj->unk8C = vel->y;
        fn_800E9A84(obj, lbl_804ECA28[kind]);
        fn_800E9424(obj, 0);
        if (facing) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->flags54_b10 = facing;
        obj->unk14 = arg0;
        obj->unk15 = kind;
    }
    return obj;
}
