#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80069954 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 pad12[0x34 - 0x12];
    /* 0x34 */ struct Unk80069954* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(struct Unk80069954* obj);
} Unk80069954;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern u8 lbl_802680E8[];
extern void (*lbl_802680DC[])(Unk80069954* obj);

void fn_80042CF8(Unk80069954* obj, s32 mode);
void fn_800E9424(Unk80069954* obj, u16 id);
void fn_800E91F0(Unk80069954* obj, void* data, s32 arg2);
void fn_800698C8(Unk80069954* obj);
void fn_80040AD0(s32 arg0, Vec2i* pos, s32 arg2, s32 arg3);
void fn_800E9244(Unk80069954* obj);
void fn_80042D30(Unk80069954* obj);
BOOL fn_8006A384(Unk80069954* obj);

void fn_80069954(Unk80069954* obj) {
    Vec2i pos2;
    Vec2i pos;

    fn_80042CF8(obj, 1);
    obj->state = 0;
    obj->flagsA |= 3;
    fn_800E9424(obj, 0x4A);
    fn_800E91F0(obj, lbl_802680E8, 2);
    obj->unkAC = fn_800698C8;
    if (obj->parent->unk10 >= 2) {
        fn_80042CF8(obj, 2);
        pos.x = obj->x;
        pos.y = obj->y;
        fn_80040AD0(2, &pos, 0, 0);
        fn_800E9244(obj);
        obj->flagsA &= ~1;
        fn_80042CF8(obj, 4);
        return;
    }
    if (lbl_803051D8.unk2 & 0x20) {
        fn_80042D30(obj);
        return;
    }
    if (fn_8006A384(obj)) {
        pos2.x = obj->x;
        pos2.y = obj->y;
        fn_80040AD0(2, &pos2, 0, 0);
        fn_800E9244(obj);
        obj->flagsA &= ~1;
        fn_80042CF8(obj, 4);
        return;
    }
    lbl_802680DC[obj->state](obj);
}
