#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80054A44 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x34 - 0x15];
    /* 0x34 */ struct Unk80054A44* unk34;
    /* 0x38 */ struct Unk80054A44* unk38;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
} Unk80054A44;

void fn_800E9244(Unk80054A44* obj);
void fn_80040AD0(s32 arg0, Vec2i* pos, s32 arg2, s32 arg3);
void fn_800406E4(s32 arg0, Vec2i* pos);
void fn_80042CF8(Unk80054A44* obj, s32 arg1);

void fn_80054A44(Unk80054A44* obj) {
    Vec2i pos;
    Unk80054A44* a;
    Unk80054A44* b;

    switch (obj->step) {
    case 0:
        fn_800E9244(obj);
        obj->flagsA &= ~1;
        pos.x = obj->x;
        pos.y = obj->y;
        fn_80040AD0(2, &pos, 0, 0);
        fn_800406E4(0, &pos);
        obj->step++;
    case 1:
        if (obj->unk14 == 2) {
            a = obj->unk34;
            b = obj->unk38;
            if (a != NULL && a->unk10 >= 2) {
                goto hit;
            }
            if (b != NULL && b->unk10 >= 2) {
                goto hit;
            }
        } else if (obj->unk14 != 1) {
            goto hit;
        } else if (obj->unk38 != NULL && obj->unk38->unk10 >= 2) {
            goto hit;
        }
        break;
    }
    return;
hit:
    fn_80042CF8(obj, 4);
}
