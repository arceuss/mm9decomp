#include "types.h"

typedef struct Unk80071E94Parent {
    /* 0x00 */ u8 pad0[0xEC];
    /* 0x0EC */ u8 hitA[4];
    /* 0x0F0 */ u8 padF0[0xF4 - 0xF0];
    /* 0x0F4 */ u8 hitB[4];
} Unk80071E94Parent;

typedef struct Unk80071E94 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 dir;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ Unk80071E94Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0x70 - 0x6C];
    /* 0x70 */ s32 ax;
    /* 0x74 */ u8 pad74[0x84 - 0x74];
    /* 0x84 */ s32 unk84;
    /* 0x88 */ u8 pad88[0xC8 - 0x88];
    /* 0xC8 */ u32 slot;
} Unk80071E94;

s32 fn_800A3CD4(s32 x, s32 y);
s32 fn_800A3FAC(s32 x, s32 y);

static inline void Move(Unk80071E94* obj, s32 scale) {
    obj->x += (obj->vx * scale) / 256 + ((scale * ((obj->ax * scale) / 256)) / 256) / 2;
    obj->vx += (obj->ax * scale) / 256;
}

void fn_80071E94(Unk80071E94* obj) {
    Unk80071E94Parent* parent = obj->parent;
    BOOL stop;
    s32 d;

    switch (obj->step) {
    case 0:
        obj->step++;
        obj->ax = -((((obj->vx > 0) * 2) - 1)) << 6;
    case 1:
        stop = FALSE;
        Move(obj, 0x100);
        if (obj->dir == 1) {
            if (obj->vx <= 0) {
                stop = TRUE;
            }
        } else if (obj->vx >= 0) {
            stop = TRUE;
        }
        if (stop) {
            obj->vx = 0;
            obj->ax = 0;
            obj->state = 0;
            obj->step = 0;
            switch (obj->slot) {
            case 0:
                parent->hitB[0] = 0;
                break;
            case 1:
                parent->hitB[1] = 0;
                break;
            case 2:
                parent->hitB[2] = 0;
                break;
            case 3:
                parent->hitB[3] = 0;
                break;
            }
        } else {
            obj->unk84--;
        }
        d = fn_800A3CD4(obj->x + 0x1800, obj->y);
        if (d != 0) {
            obj->x += d;
        }
        d = fn_800A3FAC(obj->x - 0x1800, obj->y);
        if (d != 0) {
            obj->x += d;
            switch (obj->slot) {
            case 0:
                if (parent->hitB[0] == 0) {
                    parent->hitB[0] = 1;
                }
                break;
            case 1:
                if (parent->hitB[1] == 0) {
                    parent->hitB[1] = 1;
                }
                break;
            case 2:
                if (parent->hitB[2] == 0) {
                    parent->hitB[2] = 1;
                }
                break;
            case 3:
                if (parent->hitB[3] == 0) {
                    parent->hitB[3] = 1;
                }
                break;
            }
        }
        switch (obj->slot) {
        case 0:
            if (parent->hitA[0] != 0 || parent->hitB[0] != 0) {
                obj->state = 2;
                obj->step = 0;
            }
            break;
        case 1:
            if (parent->hitA[1] != 0 || parent->hitB[1] != 0) {
                obj->state = 2;
                obj->step = 0;
            }
            break;
        case 2:
            if (parent->hitA[2] != 0 || parent->hitB[2] != 0) {
                obj->state = 2;
                obj->step = 0;
            }
            break;
        case 3:
            if (parent->hitA[3] != 0 || parent->hitB[3] != 0) {
                obj->state = 2;
                obj->step = 0;
            }
            break;
        }
        break;
    }
}
