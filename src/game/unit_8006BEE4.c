#include "types.h"

typedef struct Unk8006BEE4 {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 pad11;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ struct Unk8006BEE4* parent;
    /* 0x38 */ struct Unk8006BEE4* unk38;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ u8 pad74[0xC8 - 0x74];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 padC9[0xCC - 0xC9];
    /* 0xCC */ s32 unkCC;
} Unk8006BEE4;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 cam[0x260 - 0x21C];
    /* 0x260 */ s32 unk260;
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern Unk8006BEE4* lbl_804EE984;

void fn_80042D30(Unk8006BEE4* obj);
void fn_800E946C(Unk8006BEE4* obj, u8 id);
s32 fn_800A36F8(s32 x, s32 y);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
void fn_800E9750(Unk8006BEE4* obj, u16 arg1);

void fn_8006BEE4(Unk8006BEE4* obj) {
    Unk8006BEE4* parent = obj->parent;
    s32 r;
    s32 lim;
    Unk8006BEE4* o;

    if (parent->unk10 >= 2) {
        fn_80042D30(obj);
        return;
    }
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 2);
        obj->timer = 0x14;
        obj->unk70 = 0;
        obj->vy = (((obj->unkC8 == 1) << 1) - 1) * 0x4C0;
        obj->step++;
    case 1:
        if (obj->timer == 0) {
        obj->y += obj->vy;
        if (obj->vy < 0) {
            lim = lbl_80304B90.unk260 - 0x6A00;
            if (obj->y < lim) {
                obj->y = lim;
                obj->step++;
            }
        } else {
            r = fn_800A36F8(obj->x, obj->y + 0x600);
            if (r != 0) {
                obj->y += r;
                obj->step++;
            }
        }
        } else {
            obj->timer--;
        }
        break;
    case 2:
        if (obj->unkCC == 0) {
            obj->vx = (((lbl_804EE984->x - obj->x) >> 31) * 2 + 1) * 0x4C0;
        } else {
            o = parent->unk38;
            if (o->unk70 != 0) {
                obj->vx = o->vx;
                if (o->vx < 0) {
                    if (obj->x - o->unk70 < obj->unkCC << 13) {
                        obj->vx = -obj->vx;
                        obj->unk13 = 1;
                    }
                } else if (o->unk70 - obj->x < obj->unkCC << 13) {
                    obj->vx = -obj->vx;
                    obj->unk13 = 1;
                }
            } else {
                obj->vx = o->vx;
            }
        }
        obj->vy = -obj->vy;
        obj->timer = 0;
        obj->step++;
    case 3:
        if (obj->timer == 0) {
            obj->x += obj->vx;
            if (obj->unkC8 == 0) {
                if (obj->unkCC == 0) {
                    if (obj->vx < 0) {
                        if (obj->x < (lim = lbl_804EE984->x)) {
                            obj->x = lim;
                            obj->unk70 = lim;
                            obj->timer++;
                        }
                    } else if (obj->x > (lim = lbl_804EE984->x)) {
                        obj->x = lim;
                        obj->unk70 = lim;
                        obj->timer++;
                    }
                } else {
                    o = parent->unk38;
                    if (o->unk70 != 0) {
                        if (obj->vx < 0) {
                            lim = o->unk70 + -(((obj->unk13 == 1) << 1) - 1) * (obj->unkCC << 13);
                            if (obj->x < lim) {
                                obj->x = lim;
                                obj->timer++;
                            }
                        } else {
                            lim = o->unk70 + (((obj->unk13 == 1) << 1) - 1) * (obj->unkCC << 13);
                            if (obj->x > lim) {
                                obj->x = lim;
                                obj->timer++;
                            }
                        }
                    }
                }
            }
        } else {
            obj->y += obj->vy;
        }
        if (fn_80080484(lbl_80304B90.cam, &obj->x, 1) > 0xA00) {
            fn_80042D30(obj);
            return;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
