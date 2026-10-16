#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80024620 {
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
    /* 0x34 */ struct Unk80024620* parent;
    /* 0x38 */ u8 pad38[0x40 - 0x38];
    /* 0x40 */ u8 unk40[0x8];
    /* 0x48 */ struct Unk80024620* unk48;
    /* 0x4C */ void* unk4C;
    /* 0x50 */ u8 pad50[0x60 - 0x50];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk80024620;


typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80024620Rect {
    /* 0x00 */ Vec2i pos;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
} Unk80024620Rect;

typedef struct Unk80024620Owner {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ void (*func)(struct Unk80024620Owner* owner, Unk80024620Rect* rect);
    /* 0x8 */ Unk80024620* obj;
} Unk80024620Owner;

void fn_800E9424(Unk80024620* obj, s32 arg1);
void fn_800E946C(Unk80024620* obj, u8 id);
void fn_800E9750(Unk80024620* obj, u16 arg1);
void fn_800E7960(void* node, void* func);

void fn_80024620(Unk80024620Owner* owner, Unk80024620Rect* src) {
    Unk80024620* obj = owner->obj;
    Vec2i pos;
    Unk80024620Rect rect;

    pos.x = src->pos.x;
    pos.x += obj->unk60;
    pos.y = src->pos.y;
    pos.y += obj->unk64;
    fn_800E9424(obj, 8);
    fn_800E946C(obj, obj->unk14);
    fn_800E9750(obj, 0xFFFF);
    obj->unk4C = &pos;
    rect = *src;
    rect.unk8 -= rect.unk10 & ~0xFF;
    rect.unkC -= rect.unk14 & ~0xFF;
    owner->func(owner, &rect);
    fn_800E7960(obj->unk40, fn_80024620);
    obj->unk48 = obj;
    obj->flagsA &= 0xF7;
}
