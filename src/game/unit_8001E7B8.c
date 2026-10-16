#include "types.h"

typedef struct Unk8001E7B8 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x54 - 0x17];
    /* 0x54 */ struct {
        u32 hi : 21;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0x7C - 0x6C];
    /* 0x7C */ u8 anim;
    /* 0x7D */ u8 pad7D[0xD8 - 0x7D];
    /* 0xD8 */ struct Unk8001E7B8* sats[4];
    /* 0xE8 */ u8 padE8[0xEC - 0xE8];
    /* 0xEC */ u8 unkEC;
    /* 0xED */ u8 unkED;
    /* 0xEE */ u16 unkEE;
} Unk8001E7B8;

extern void* lbl_804EE984;

void fn_800E946C(Unk8001E7B8* obj, u8 anim);
void fn_800E9750(Unk8001E7B8* obj, u16 arg1);
s32 fn_800A3CD4(s32 x, s32 y);
s32 fn_800A3FAC(s32 x, s32 y);
BOOL fn_800B673C(void* player);

void fn_8001E7B8(Unk8001E7B8* obj) {
    BOOL hit;
    BOOL attack;
    s32 d;
    Unk8001E7B8* a;
    Unk8001E7B8* b;
    Unk8001E7B8* c;
    Unk8001E7B8* e;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 2);
        obj->timer = 2;
        obj->step++;
    case 1:
        hit = FALSE;
        obj->vx = (((obj->flagsA >> 3) & 2) - 1) * 0x180;
        obj->x += obj->vx;
        if (obj->flagsA & 0x10) {
            d = fn_800A3CD4(obj->x + 0x1000, obj->y);
        } else {
            d = fn_800A3FAC(obj->x - 0x1000, obj->y);
        }
        if (d != 0) {
            hit = TRUE;
        }
        if (hit) {
            obj->x += d;
            obj->bits54.flip = !(obj->flagsA & 0x10);
            if (obj->bits54.flip) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            if (obj->timer == 0) {
                attack = FALSE;
                a = obj->sats[0];
                b = obj->sats[1];
                c = obj->sats[2];
                e = obj->sats[3];
                if ((a->unk10 < 2 && a->step <= 1 && a->anim != 0xB) ||
                    (b->unk10 < 2 && b->step <= 1 && a->anim != 0xB) ||
                    (c->unk10 < 2 && c->step <= 1 && a->anim != 0xB) ||
                    (e->unk10 < 2 && e->step <= 1 && a->anim != 0xB)) {
                    if (obj->unkED == 0 && obj->unkEE == 0) {
                        attack = TRUE;
                    }
                }
                if (attack) {
                    obj->state = 3;
                    obj->step = 0;
                    obj->unkEC = 0;
                    break;
                }
            } else {
                obj->timer--;
            }
        }
        if (fn_800B673C(lbl_804EE984)) {
            obj->state = 2;
            obj->step = 0;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
