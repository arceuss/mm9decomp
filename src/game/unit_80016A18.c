#include "types.h"

typedef struct Unk80016A18 {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x64 - 0x13];
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 gravity;
    /* 0x78 */ u8 pad78[0x7F - 0x78];
    /* 0x7F */ u8 animState;
    /* 0x80 */ u8 pad80[0xDA - 0x80];
    /* 0xDA */ u8 unkDA;
    /* 0xDB */ u8 lastPick;
    /* 0xDC */ s32 targetY;
} Unk80016A18;

extern u32 lbl_804EE988;
extern s32 lbl_80262778[3];

void fn_800E946C(Unk80016A18* obj, u8 anim);
void fn_800E9750(Unk80016A18* obj, u16 arg1);
void fn_80017CC4(Unk80016A18* obj);

void fn_80016A18(Unk80016A18* obj) {
    u32 rnd;
    u8 pick;
    s32 base;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        obj->step++;
    case 1:
        if (obj->animState == 3) {
            obj->step++;
        }
        break;
    case 2:
        fn_800E946C(obj, 4);
        obj->vy = 0;
        obj->gravity = -0x40;
        base = (obj->y / 0xE000 + 1) * 0xE000 - 0x3000;
        rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
        lbl_804EE988 = rnd & 0x7FFFFFFF;
        pick = ((rnd >> 16) & 0x7FFF) % 3;
        while (obj->lastPick == pick) {
            rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
            lbl_804EE988 = rnd & 0x7FFFFFFF;
            pick = ((rnd >> 16) & 0x7FFF) % 3;
        }
        obj->lastPick = pick;
        obj->targetY = base - lbl_80262778[pick];
        obj->step++;
    case 3:
        obj->y += obj->vy;
        obj->vy += obj->gravity;
        if (obj->vy <= -0x500) {
            obj->vy = -0x500;
        }
        if (obj->y < obj->targetY) {
            obj->y = obj->targetY;
            obj->unkDA = 1;
            fn_80017CC4(obj);
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
