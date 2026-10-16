#include "types.h"
#include "game/sound.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80040D50 {
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
    /* 0x34 */ struct Unk80040D50* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0xAC - 0x70];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk80040D50;

extern Unk80280390Entry* lbl_80265138[10];

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern void* lbl_804EE730;
extern const s16 lbl_802537E8[256];

void fn_800D5564(s32 arg0);
Unk80040D50* fn_800E8C44(void* pool);
void fn_800E9A84(Unk80040D50* obj, s32 arg1);
void fn_800E9424(Unk80040D50* obj, s32 arg1);
void fn_800E946C(Unk80040D50* obj, u8 id);

Unk80040D50* fn_80040D50(Vec2i* pos) {
    Unk80040D50* obj;
    s32 i;
    s32 angle;
    s32 speed;

    fn_800D5564(BGM_SE_OUT);
    for (i = 0; i < 16; i++) {
        obj = fn_800E8C44(lbl_804EE730);
        if (obj != NULL) {
            obj->unk2E = 0x10;
            obj->unk9 = 1;
            obj->unk18 = lbl_80265138[1]->unk0;
            obj->unk2A = 0;
            obj->unk2C = 0;
            obj->unk2F = 0;
            obj->flagsB |= 0x20;
            obj->unk21 = obj->unk20;
            obj->unk60 = pos->x;
            obj->unk64 = pos->y;
            fn_800E9A84(obj, 0x144);
            fn_800E9424(obj, 0);
            fn_800E946C(obj, 0);
            speed = (i / 8 + 1) * 0xC0;
            angle = (i * 0x100) / 8;
            obj->unk68 = speed * lbl_802537E8[(u8)angle] / 256;
            obj->unk6C = speed * -lbl_802537E8[(u8)(angle + 0x40)] / 256;
        }
    }
    return obj;
}
