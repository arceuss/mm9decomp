#include "types.h"

typedef struct Unk80022F84 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x54 - 0x17];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
} Unk80022F84;

extern Unk80022F84* lbl_804EE984;

void fn_800E946C(Unk80022F84* obj, u8 anim);
s32 fn_800A3FAC(s32 x, s32 y);
s32 fn_800A3CD4(s32 x, s32 y);
BOOL fn_800B590C(void* player, s32 arg1);
void fn_800E9750(Unk80022F84* obj, u16 arg1);

static inline void FacePlayer(Unk80022F84* obj, s32 px) {
    s32 d = px - obj->x;

    obj->flipX = (u32)(-d & ~d) >> 31;
    if (obj->flipX) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
}

static inline void Turn(Unk80022F84* obj) {
    obj->timer = 0x1E;
    obj->vx = (((obj->flagsA >> 3) & 2) - 1) * 0x1C0;
}

static inline void Flip(Unk80022F84* obj) {
    obj->flipX = !(obj->flagsA & 0x10);
    if (obj->flipX) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
    Turn(obj);
}

void fn_80022F84(Unk80022F84* obj) {
    s32 d;
    s32 px;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        obj->timer = 0;
        obj->step++;
        obj->vx = (((obj->flagsA >> 3) & 2) - 1) * 0x1C0;
    case 1:
        obj->x += obj->vx;
        if (obj->timer == 0) {
            if (obj->vx < 0) {
                px = lbl_804EE984->x;
                if (obj->x < px - 0x2000) {
                    FacePlayer(obj, px);
                    Turn(obj);
                }
            } else {
                px = lbl_804EE984->x;
                if (obj->x > px + 0x2000) {
                    FacePlayer(obj, px);
                    Turn(obj);
                }
            }
        } else {
            obj->timer--;
        }
        if (!(obj->flagsA & 0x10)) {
            d = fn_800A3FAC(obj->x - 0x1000, obj->y);
            if (d != 0) {
                obj->x += d;
                Flip(obj);
            }
        } else {
            d = fn_800A3CD4(obj->x + 0x1000, obj->y);
            if (d != 0) {
                obj->x += d;
                Flip(obj);
            }
        }
        if (fn_800B590C(lbl_804EE984, 1)) {
            obj->state = 2;
            obj->step = 0;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
