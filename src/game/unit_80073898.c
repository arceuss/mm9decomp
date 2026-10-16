#include "types.h"

typedef struct Unk80073898 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ s32 targetX;
    /* 0xCC */ s32 targetY;
} Unk80073898;

void fn_800E9244(Unk80073898* obj);
s32 fn_800EB16C(s32 dx, s32 dy);
extern void** lbl_80270168[];
void fn_80073B24(Unk80073898* obj);
void fn_800E9758(Unk80073898* obj);

void fn_80073898(Unk80073898* obj) {
    s32 dx;
    s32 dy;
    s32 dist;
    s32 speed;
    s32 v;

    switch (obj->step) {
    case 0:
        fn_800E9244(obj);
        obj->step++;
    case 1:
        dx = obj->targetX - obj->x;
        dy = obj->targetY - obj->y;
        dist = fn_800EB16C(dx, dy);
        if (dist <= 0x800) {
            obj->unk18 = lbl_80270168[obj->kind][2];
            obj->unk10 = 2;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
            fn_80073B24(obj);
            break;
        }
        speed = 0x100 - (dist << 8) / 0x2000;
        if (speed < 0x40) {
            speed = 0x40;
        }
        v = (speed * 1024) / 256;
        dx = (dx * 256) / dist;
        dy = (dy * 256) / dist;
        dx = (dx * v) / 256;
        dy = (dy * v) / 256;
        obj->x += dx;
        obj->y += dy;
        fn_800E9758(obj);
        break;
    }
}
