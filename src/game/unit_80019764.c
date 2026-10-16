#include "types.h"

typedef struct Unk802638A0Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
} Unk802638A0Entry;

typedef struct Unk80019764 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x50 - 0x1C];
    /* 0x50 */ u32 unk50;
    /* 0x54 */ u8 pad54[0x60 - 0x54];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0xAC - 0x6C];
    /* 0xAC */ void (*unkAC)(struct Unk80019764*);
} Unk80019764;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x38 - 0x4];
} Unk803051D8;

extern Unk802638A0Entry* lbl_802638A0[];
extern u8 lbl_804EC78C[4];
extern u8 lbl_80262A18[];
extern u32 lbl_804EE988;
extern Unk803051D8 lbl_803051D8;

void fn_800E9424(Unk80019764* obj, u16 anim);
void fn_800E91F0(Unk80019764* obj, void* data, s32 arg2);
void fn_80019760(Unk80019764* obj);
void fn_800E946C(Unk80019764* obj, u8 anim);
void fn_800198FC(Unk80019764* obj);

void fn_80019764(Unk80019764* obj) {
    u32 rnd;

    obj->unk18 = lbl_802638A0[obj->kind]->unk4;
    obj->unk10 = 1;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = lbl_804EC78C[obj->unk14];
    obj->flagsA |= 3;
    fn_800E9424(obj, 0x3E);
    fn_800E91F0(obj, lbl_80262A18, 0xF);
    obj->unkAC = fn_80019760;
    obj->y = (obj->y / 0xE000) * 0xE000 + 0x1000;
    obj->x = (obj->x / 0x10000) << 16;
    rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
    lbl_804EE988 = rnd & 0x7FFFFFFF;
    obj->unk50 |= 3;
    obj->x += (u8)(((rnd >> 16) & 0x7FFF) % 7 + 1) << 13;
    lbl_803051D8.unk3 |= 8;
    fn_800E946C(obj, 2);
    obj->vx = 0;
    obj->unk50 |= 3;
    obj->timer = 0x10;
    obj->step = 3;
    fn_800198FC(obj);
}
