#include "types.h"

typedef struct Unk80071AD8 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x20 - 0x15];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x30 - 0x22];
    /* 0x30 */ s16 unk30;
    /* 0x32 */ u8 pad32[0x34 - 0x32];
    /* 0x34 */ struct Unk80071AD8* parent;
    /* 0x38 */ u8 pad38[0x3C - 0x38];
    /* 0x3C */ void* unk3C;
    /* 0x40 */ u8 pad40[0x60 - 0x40];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x74 - 0x68];
    /* 0x74 */ s32 homeX;
    /* 0x78 */ u8 pad78[0xAC - 0x78];
    /* 0xAC */ void (*unkAC)(struct Unk80071AD8* obj);
    /* 0xB0 */ u8 padB0[0xCC - 0xB0];
    /* 0xCC */ struct Unk80071AD8* target;
} Unk80071AD8;

extern u8 lbl_804EE7F8[8];
extern u8 lbl_804ECCB0[8];
extern u8 lbl_80268AB8[];
extern void (*lbl_80268AAC[])(Unk80071AD8* obj);

void fn_80042CF8(Unk80071AD8* obj, s32 mode);
void fn_800E9424(Unk80071AD8* obj, u16 id);
void fn_800E946C(Unk80071AD8* obj, s32 anim);
void fn_800E91F0(Unk80071AD8* obj, void* data, s32 arg2);
void fn_80071864(Unk80071AD8* obj);
s32 fn_800A36F8(s32 x, s32 y);
s32 fn_800A43B4(s32 x, s32 y);
void fn_80071CF8(Unk80071AD8* obj);
void fn_800E9750(Unk80071AD8* obj, u16 arg1);

void fn_80071AD8(Unk80071AD8* obj) {
    s32 d;
    Unk80071AD8* t;

    fn_80042CF8(obj, 1);
    obj->state = lbl_804EE7F8[obj->unk14];
    obj->flagsA |= 3;
    fn_800E9424(obj, 0x35);
    fn_800E946C(obj, 10);
    fn_800E91F0(obj, lbl_80268AB8, 0x80);
    obj->unkAC = fn_80071864;
    d = fn_800A36F8(obj->x, obj->y);
    if (d < 0) {
        obj->y += d;
    } else {
        d = fn_800A43B4(obj->x, obj->y);
        if (d != 0 && d != 0x7FFFFFFF && d != -1) {
            obj->y = d;
        }
    }
    obj->flagsB |= 0x10;
    obj->flagsB &= 0xDF;
    obj->unk3C = lbl_804ECCB0;
    obj->unk30 = 1;
    obj->unk21 = obj->unk20;
    obj->homeX = obj->x;
    t = NULL;
    obj->target = t;
    if (obj->parent->unk10 >= 2) {
        fn_80042CF8(obj, 2);
        fn_80071CF8(obj);
        return;
    }
    if (t != NULL && t->unk10 >= 2) {
        obj->target = t;
    }
    lbl_80268AAC[obj->state](obj);
    fn_800E9750(obj, 0xFFFF);
}
