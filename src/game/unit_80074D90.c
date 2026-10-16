#include "types.h"

typedef struct Unk80074D90 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x17 - 0x14];
    /* 0x17 */ u8 bounces;
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x54 - 0x1C];
    /* 0x54 */ struct {
        u32 hi : 21;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x88 - 0x70];
    /* 0x88 */ u8 unk88[0xA0 - 0x88];
    /* 0xA0 */ u32 hitFlags;
} Unk80074D90;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern void** lbl_80270168[];
extern u8 lbl_8026FC68[];

void fn_800E9244(Unk80074D90* obj);
void fn_800E946C(Unk80074D90* obj, s32 anim);
void fn_800E9750(Unk80074D90* obj, u16 arg1);
void fn_800D5234(s32 id);
void fn_8009996C(void* arg0, void* arg1);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);

static inline void SetMode(Unk80074D90* obj, u8 mode) {
    obj->unk18 = lbl_80270168[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_80074D90(Unk80074D90* obj) {
    u8 f;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 3);
        obj->bounces = 0;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (obj->hitFlags & 0x100) {
            if (obj->bounces == 0) {
                obj->vx = obj->vx * -3 / 2;
                obj->vy = obj->vy * -3 / 2;
            } else if (obj->bounces == 1) {
                obj->vx = -obj->vx;
                obj->vy = -obj->vy;
            }
            fn_800D5234(0x3E);
            fn_8009996C(obj->unk88, lbl_8026FC68);
            f = !(obj->flagsA & 0x10);
            if (f) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->bits54.flip = f;
            obj->bounces++;
        }
        obj->x += obj->vx;
        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0x800) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            SetMode(obj, 3);
        }
        break;
    }
}
