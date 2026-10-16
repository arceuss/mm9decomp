#include "types.h"

typedef struct Unk8006E20C {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x34 - 0x13];
    /* 0x34 */ struct Unk8006E20C* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 ay;
    /* 0x78 */ u8 pad78[0x88 - 0x78];
    /* 0x88 */ u8 unk88[0xD0 - 0x88];
    /* 0xD0 */ u8 unkD0;
} Unk8006E20C;

extern u8 lbl_80268730[];

void fn_800E946C(Unk8006E20C* obj, u8 anim);
void fn_8009996C(void* arg0, void* arg1);
u16 fn_800A32FC(s32 x, s32 y);
s32 fn_800A36F8(s32 x, s32 y);
void fn_800D5234(s32 se);
void fn_8006DB44(Unk8006E20C* obj, s32 kind, s32 dir);
void fn_80042D30(Unk8006E20C* obj);
void fn_800E9750(Unk8006E20C* obj, u16 arg1);

void fn_8006E20C(Unk8006E20C* obj) {
    Unk8006E20C* parent = obj->parent;
    BOOL hit = FALSE;
    u32 flip;
    s32 d;

    if (parent != NULL && parent->unk10 >= 2) {
        parent = NULL;
        obj->parent = parent;
    }
    switch (obj->step) {
    case 0:
        obj->flagsA &= ~1;
        fn_800E946C(obj, 3);
        fn_8009996C(obj->unk88, lbl_80268730);
        obj->step++;
    case 1:
        if (parent == NULL || parent->unk10 >= 2 || parent->unkD0 != 0) {
            if (fn_800A32FC(obj->x, obj->y)) {
                hit = TRUE;
            } else {
                obj->flagsA |= 1;
                obj->step++;
            }
        } else {
            flip = (parent->flagsA >> 4) & 1;
            if (flip) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->flipX = flip;
            obj->x = parent->x;
            obj->y = parent->y + 0xA00;
        }
        break;
    case 2:
        obj->flagsA |= 1;
        obj->parent = NULL;
        obj->vy = 0;
        obj->ay = 0x40;
        obj->step++;
    case 3:
        obj->y += obj->vy;
        d = fn_800A36F8(obj->x, obj->y + 0x800);
        if (d < 0) {
            obj->y += d;
            hit = TRUE;
        }
        obj->vy += obj->ay;
        if (obj->vy > 0x700) {
            obj->vy = 0x700;
        }
        break;
    }
    if (hit) {
        fn_800D5234(0x49);
        fn_8006DB44(obj, 3, 0);
        fn_8006DB44(obj, 3, 1);
        fn_8006DB44(obj, 3, 2);
        fn_8006DB44(obj, 3, 3);
        fn_80042D30(obj);
    } else {
        fn_800E9750(obj, 0xFFFF);
    }
}
