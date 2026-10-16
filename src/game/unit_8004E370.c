#include "types.h"

typedef struct Unk8004E370 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 frame;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 baseY;
    /* 0x78 */ u8 pad78[0xCC - 0x78];
    /* 0xCC */ u8 animTimer;
} Unk8004E370;

void fn_800E947C(Unk8004E370* obj, s32 arg1, s32 frame, s32 arg3);
void fn_800E9758(Unk8004E370* obj);
s32 fn_800A36F8(s32 x, s32 y);
s32 fn_800A39F0(s32 x, s32 y);
s32 fn_800A3CD4(s32 x, s32 y);
s32 fn_800A3FAC(s32 x, s32 y);

void fn_8004E370(Unk8004E370* obj) {
    s32 d;

    switch (obj->step) {
    case 0:
        fn_800E947C(obj, 0, (s8)obj->frame, 0);
        obj->timer = 0x60;
        obj->step++;
    case 1:
        fn_800E947C(obj, 0, (s8)obj->frame, 0);
        if (++obj->animTimer > 2) {
            if (obj->frame == 0) {
                obj->frame++;
            } else {
                obj->frame = 0;
            }
            obj->animTimer = 0;
        }
        fn_800E9758(obj);
        obj->y += obj->vy;
        if (--obj->timer == 0) {
            obj->state = 1;
            obj->step = 0;
        }
        if (obj->vy > 0) {
            d = fn_800A36F8(obj->x + (((obj->flagsA >> 3) & 2) - 1) * -0x700, obj->y + 0xE00);
            if (d < 0) {
                obj->y += d;
                obj->vy = -obj->vy;
            } else if (!(obj->flagsA & 0x10)) {
                if (fn_800A3CD4(obj->x + 0x800, obj->y + 0xE00) == 0) {
                    obj->vy = -obj->vy;
                    break;
                }
                goto lower;
            } else {
                if (fn_800A3FAC(obj->x - 0x800, obj->y + 0xE00) == 0) {
                    obj->vy = -obj->vy;
                    break;
                }
            lower:
                if (obj->y > obj->baseY + 0x2000) {
                    obj->y = obj->baseY + 0x2000;
                    obj->vy = -obj->vy;
                }
            }
        } else {
            d = fn_800A39F0(obj->x + (((obj->flagsA >> 3) & 2) - 1) * -0x700, obj->y - 0xE00);
            if (d > 0) {
                obj->y += d;
                obj->vy = -obj->vy;
            } else if (!(obj->flagsA & 0x10)) {
                if (fn_800A3CD4(obj->x + 0x800, obj->y - 0xE00) == 0) {
                    obj->vy = -obj->vy;
                    break;
                }
                goto upper;
            } else {
                if (fn_800A3FAC(obj->x - 0x800, obj->y - 0xE00) == 0) {
                    obj->vy = -obj->vy;
                    break;
                }
            upper:
                if (obj->y < obj->baseY - 0x2000) {
                    obj->y = obj->baseY - 0x2000;
                    obj->vy = -obj->vy;
                }
            }
        }
        break;
    }
}
