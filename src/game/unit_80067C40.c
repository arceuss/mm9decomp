#include "types.h"

typedef struct Unk80067C40Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk80067C40Pos;

typedef struct Unk80067C40 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB;
    /* 0x0C */ u8 flagsC;
    /* 0x0D */ u8 padD[0x10 - 0xD];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x34 - 0x15];
    /* 0x34 */ struct Unk80067C40* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ Unk80067C40Pos pos;
    /* 0x68 */ u8 pad68[0xAB - 0x68];
    /* 0xAB */ u8 unkAB;
    /* 0xAC */ void (*unkAC)(struct Unk80067C40*);
    /* 0xB0 */ u8 padB0[0xCC - 0xB0];
    /* 0xCC */ s32 unkCC;
    /* 0xD0 */ u8 padD0[0xD4 - 0xD0];
    /* 0xD4 */ u8 unkD4;
    /* 0xD5 */ u8 unkD5;
} Unk80067C40;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern u8 lbl_804ECC28[8];
extern u8 lbl_80267EA0[];
extern void (*lbl_80267E90[])(Unk80067C40* obj);
extern Unk803051D8 lbl_803051D8;

void fn_80042CF8(Unk80067C40* obj, s32 mode);
void fn_800E9424(Unk80067C40* obj, u16 anim);
void fn_800E91F0(Unk80067C40* obj, void* data, s32 arg2);
void fn_80067C04(Unk80067C40* obj);
void fn_80042D30(Unk80067C40* obj);
void fn_80040AD0(s32 arg0, Unk80067C40Pos* pos, s32 arg2, s32 arg3);
void fn_800E9244(Unk80067C40* obj);

static inline BOOL Check(Unk80067C40* obj) {
    if (obj->state != 1 && (u32)(obj->unkAB & 0xF) == 3) {
        obj->state = 1;
        obj->step = 0;
        return obj->step;
    }
    return FALSE;
}

void fn_80067C40(Unk80067C40* obj) {
    Unk80067C40Pos pos;

    fn_80042CF8(obj, 1);
    obj->state = lbl_804ECC28[obj->unk14];
    obj->flagsA |= 3;
    fn_800E9424(obj, 0x44);
    if (obj->unk14 == 0) {
        fn_800E91F0(obj, lbl_80267EA0, 1);
        obj->unkAC = fn_80067C04;
        obj->unkCC = 0;
        obj->unkD4 = 0x14;
        obj->unkD5 = 1;
    } else {
        fn_800E91F0(obj, NULL, 1);
    }
    obj->flagsC |= 0x10;
    if (obj->parent->unk10 >= 2) {
        fn_80042D30(obj);
    } else if (lbl_803051D8.unk2 & 0x20) {
        fn_80042D30(obj);
    } else if (Check(obj)) {
        pos.x = obj->pos.x;
        pos.y = obj->pos.y;
        fn_80040AD0(2, &pos, 0, 0);
        fn_800E9244(obj);
        obj->flagsA &= ~1;
        fn_80042CF8(obj, 4);
    } else {
        lbl_80267E90[obj->state](obj);
    }
}
