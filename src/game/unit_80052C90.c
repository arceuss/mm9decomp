#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80052C90 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x60 - 0x13];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x7F - 0x68];
    /* 0x7F */ u8 unk7F;
} Unk80052C90;

extern u8 lbl_804ECA94[4];
extern u8 lbl_804ECA98[4];
extern u8 lbl_804ECA9C[4];
extern Vec2i lbl_80266508[];
extern s32 lbl_80266528[];

u8 fn_800533F0(Unk80052C90* obj);
void fn_800E946C(Unk80052C90* obj, u8 anim);
void fn_80075CF8(Vec2i* pos, s32 speed, u8 dir);
void fn_800D5234(s32 id);
void fn_800E9750(Unk80052C90* obj, u16 arg1);

void fn_80052C90(Unk80052C90* obj) {
    Vec2i pos;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, lbl_804ECA94[fn_800533F0(obj)]);
        pos.x = obj->x + (((obj->flagsA >> 3) & 2) - 1) * lbl_80266508[fn_800533F0(obj)].x;
        pos.y = obj->y - lbl_80266508[fn_800533F0(obj)].y;
        if (!(obj->flagsA & 0x10)) {
            fn_80075CF8(&pos, lbl_80266528[fn_800533F0(obj)], lbl_804ECA98[fn_800533F0(obj)]);
        } else {
            fn_80075CF8(&pos, lbl_80266528[fn_800533F0(obj)], lbl_804ECA9C[fn_800533F0(obj)]);
        }
        fn_800D5234(0x3F);
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7F == 3) {
            obj->state = 0;
            obj->step = 0;
        }
        break;
    }
}
