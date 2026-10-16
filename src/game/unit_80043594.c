#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80043594 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ union {
        u8 flagsA;
        struct {
            u8 flagsA_7 : 3;
            u8 flip : 1;
            u8 flagsA_0 : 4;
        } bits;
    };
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
    /* 0x34 */ struct Unk80043594* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_0 : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_22 : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x84 - 0x68];
    /* 0x84 */ s32 unk84;
    /* 0x88 */ u8 unk88[0xAC - 0x88];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD0 - 0xCD];
    /* 0xD0 */ s16 unkD0;
} Unk80043594;


extern u8 lbl_804ECA58[4];
extern u8 lbl_802651C0[];

void fn_800E946C(Unk80043594* obj, u8 id);
void fn_8009996C(void* sprite, void* anim);
void fn_800E9750(Unk80043594* obj, u16 arg1);
void fn_80072BDC(s32* pos, s32 vx, s32 vy);

void fn_80043594(Unk80043594* obj) {
    s32 pos[2];
    s32 dir;
    s32 vx;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, lbl_804ECA58[obj->unk14]);
        fn_8009996C(obj->unk88, lbl_802651C0);
        obj->unk16 = 0x10;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk16 == 0) {
            pos[0] = obj->unk60 + (dir = (obj->bits.flip == 1) * 2 - 1) * 0x800;
            pos[1] = obj->unk64 - 0x800;
            vx = dir * 0x150;
            fn_80072BDC(pos, vx, 0xA0);
            fn_80072BDC(pos, vx, 0x80);
            fn_80072BDC(pos, vx, 0x60);
            obj->step++;
        } else {
            obj->unk16--;
        }
        break;
    case 2:
        obj->unk16 = 0x1E;
        obj->step++;
    case 3:
        if (--obj->unk16 == 0) {
            obj->state = 3;
            obj->step = 0;
        }
        break;
    }
}
