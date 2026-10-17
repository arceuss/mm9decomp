#include "types.h"

typedef struct Unk800CC474 {
    /* 0x00 */ u8 pad0[0xB];
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 padC[0x12 - 0xC];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x30 - 0x18];
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u8 pad32[0x3C - 0x32];
    /* 0x3C */ void* unk3C;
    /* 0x40 */ u8 pad40[0x60 - 0x40];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 ax;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0xC9 - 0x78];
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u16 unkCA;
    /* 0xCC */ struct Unk800CC474* parent;
} Unk800CC474;

extern Unk800CC474* lbl_804EE984;
extern u8 lbl_804ECFF8[8];

void fn_800E946C(Unk800CC474* obj, u8 arg1);
void fn_800E9750(Unk800CC474* obj, u16 arg1);
s32 fn_800B6010(Unk800CC474* player, Unk800CC474* obj);
void fn_800D5234(s32 se);
void fn_800CC9D4(Unk800CC474* obj);

void fn_800CC474(Unk800CC474* obj) {
    s32 moved;
    s32 d;
    s32 e;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->unkB |= 0x10;
        obj->unk3C = lbl_804ECFF8;
        obj->unk30 = 0x2001;
        obj->vx = 0;
        obj->ax = 0;
        obj->unk74 = 0;
        obj->unk16 = 0;
        obj->unk17 = 0xFF;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        moved = 0;
        if (fn_800B6010(lbl_804EE984, obj)) {
            if (obj->unk16 == 0 && obj->vx == 0 && obj->unkCA == 0x4000) {
                obj->unk6C = obj->x - lbl_804EE984->x;
                obj->unkC9 = 1;
                if (obj->x - lbl_804EE984->x < 0) {
                    obj->vx = 0x120;
                    obj->unk17 = 0;
                } else {
                    obj->vx = -0x120;
                    obj->unk17 = 1;
                }
                fn_800D5234(0x37);
            }
            obj->unk16 = 1;
            if ((u16)(obj->unkCA + 0xBFFF) <= 0x83FE) {
                obj->ax = -8;
            } else {
                obj->ax = 8;
            }
            if (obj->unk6C != obj->x - lbl_804EE984->x) {
                obj->unkC9 = 1;
                moved = 1;
                if (obj->unk6C > obj->x - lbl_804EE984->x) {
                    if (obj->vx == 0) {
                        if (obj->unkCA == 0x4000) {
                            obj->vx = -0x120;
                            obj->unk17 = 1;
                        }
                    } else if ((u16)(obj->unkCA + 0xBFFF) <= 0x83FE) {
                        obj->vx -= 0x10;
                    } else {
                        obj->vx -= 2;
                    }
                } else {
                    if (obj->vx == 0) {
                        if (obj->unkCA == 0x4000) {
                            obj->vx = 0x120;
                            obj->unk17 = 0;
                        }
                    } else if ((u16)(obj->unkCA + 0xBFFF) <= 0x83FE) {
                        obj->vx += 2;
                    } else {
                        obj->vx += 0x10;
                    }
                }
                obj->unk6C = obj->x - lbl_804EE984->x;
            }
        } else {
            obj->unk16 = 0;
            if (obj->ax != 0) {
                if ((u16)(obj->unkCA + 0xBFFF) <= 0x83FE) {
                    obj->ax = -8;
                } else {
                    obj->ax = 8;
                }
            }
        }
        if (obj->unkC9) {
            obj->vx = (obj->vx + obj->ax) * 255 / 256;
        }
        if (obj->vx < 0) {
            if (obj->vx < -0x1C0) {
                obj->vx = -0x1C0;
            }
        } else if (obj->vx > 0x1C0) {
            obj->vx = 0x1C0;
        }
        if (obj->unk17 != 0xFF) {
            if (obj->unk17 == 0) {
                if (obj->vx > 0) {
                    obj->unk74 = obj->unkCA;
                    obj->unk17 = 1;
                }
            } else if (obj->vx < 0) {
                obj->unk74 = obj->unkCA;
                obj->unk17 = 0;
            }
        }
        if (obj->unk74 != 0 && __abs(obj->vx) < 0x20 && moved == 0) {
            e = obj->unk74 - 0x4000;
            d = -e;
            if (e > 0) {
                d = e;
            }
            if (d <= 0x800 && __abs(obj->unkCA - 0x4000) <= 0x100) {
                obj->unkCA = 0x4000;
                obj->x = obj->parent->x;
                obj->vx = 0;
                obj->ax = 0;
                obj->unk74 = 0;
                obj->unk17 = 0xFF;
                obj->unkC9 = 0;
            }
        }
        fn_800CC9D4(obj);
        break;
    }
}
