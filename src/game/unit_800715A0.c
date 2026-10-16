#include "types.h"

typedef struct Unk800715A0 {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x60 - 0x13];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ s32 targetX;
    /* 0xCC */ s32 targetY;
} Unk800715A0;

void fn_800E9244(Unk800715A0* obj);
s32 fn_800EB16C(s32 dx, s32 dy);
void fn_80042CF8(Unk800715A0* obj, s32 arg1);
void fn_800E9758(Unk800715A0* obj);

void fn_800715A0(Unk800715A0* obj) {
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
            fn_80042CF8(obj, 2);
            fn_80042CF8(obj, 4);
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
