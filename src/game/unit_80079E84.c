#include "types.h"

typedef struct Unk80079E84 {
    u8 pad0[9]; u8 unk9; u8 unkA;
    u8 padB[5]; u8 unk10; u8 unk11; u8 step; u8 unk13;
    u8 pad14[2]; u8 unk16; u8 pad17;
    u32 unk18;
    u8 pad1C[0x60-0x1C];
    s32 x; s32 y; s32 vx; s32 vy;
    u8 pad70[0xC8-0x70];
    u8 dir; u8 mode;
} Unk80079E84;
typedef struct Unk80304B90 { u8 pad0[0x21C]; u8 cam[4]; } Unk80304B90;
extern Unk80304B90 lbl_80304B90;
extern Unk80079E84* lbl_804EE984;
extern u32* lbl_80270168[18];
s32 fn_800A3FAC(s32, s32);
s32 fn_800A3CD4(s32, s32);
s32 fn_800A36F8(s32, s32);
s32 fn_800A39F0(s32, s32);
s32 fn_800A43B4(s32, s32);
s32 fn_800A48EC(s32, s32);
s32 fn_800A4C0C(s32, s32);
u32 fn_80080484(void*, s32*, s32);
void fn_800E9244(Unk80079E84*);
void fn_800E9750(Unk80079E84*, u16);

void fn_80079E84(Unk80079E84* obj) {
    s32 d;
    s32 e;
    switch (obj->step) {
    case 0:
        obj->vx = 0x380;
        obj->vy = 0x380;
        obj->unk16 = 0x78;
        obj->step++;
    case 1:
        if (obj->dir == 2 || obj->dir == 3) {
            obj->vy = (((u8)(obj->dir - 2) == 1) * 2 - 1) * 0x380;
            obj->y += obj->vy;
            if (obj->dir == 3) {
                if (obj->mode == 0) {
                    if (!(obj->unkA & 0x10)) {
                        d = fn_800A3FAC(obj->x-0x600, obj->y-0x600);
                        if (d) obj->x += d;
                        if (fn_800A3FAC(obj->x-0x600, obj->y+0x600)) obj->x += d;
                    } else {
                        d = fn_800A3CD4(obj->x+0x600, obj->y-0x600);
                        if (d) obj->x += d;
                        fn_800A3CD4(obj->x+0x600, obj->y+0x600);
                        if (d) obj->x += d;
                    }
                }
                d = fn_800A36F8(obj->x-0x600, obj->y+0x600);
                e = fn_800A36F8(obj->x+0x600, obj->y+0x600);
                if (d || e) {
                    obj->y += d;
                    if (obj->mode == 0) {
                        if (!(obj->unkA & 0x10)) obj->dir = 0;
                        else obj->dir = 1;
                    } else if (obj->mode == 4) obj->dir = 0;
                    else if (obj->mode == 3) obj->dir = 1;
                    obj->mode = 1;
                }
            } else if (obj->dir == 2) {
                d = fn_800A39F0(obj->x, obj->y-0x600);
                if (d) {
                    obj->y += d;
                    if (obj->mode == 4) obj->dir = 0;
                    else if (obj->mode == 3) obj->dir = 1;
                    obj->mode = 2;
                }
                if (obj->mode == 3) {
                    if (!fn_800A3FAC(obj->x-0x700, obj->y+0x600)) {
                        obj->y = fn_800A43B4(obj->x-0x700, obj->y) - 0x600;
                        obj->dir = 0;
                        obj->mode = 1;
                    }
                }
                if (obj->mode == 4) {
                    if (!fn_800A3CD4(obj->x+0x700, obj->y+0x600)) {
                        obj->y = fn_800A43B4(obj->x+0x700, obj->y) - 0x600;
                        obj->dir = 1;
                        obj->mode = 1;
                    }
                }
            }
        } else {
            obj->vx = ((obj->dir == 1) * 2 - 1) * 0x380;
            obj->x += obj->vx;
            if (obj->dir == 0) {
                d = fn_800A3FAC(obj->x-0x600, obj->y);
                if (d) {
                    obj->x += d;
                    if (obj->mode == 1) obj->dir = 2;
                    if (obj->mode == 2) obj->step++;
                    obj->mode = 3;
                }
                if (obj->mode == 1) {
                    d = fn_800A36F8(obj->x-0x600, obj->y+0x700);
                    e = fn_800A36F8(obj->x+0x600, obj->y+0x700);
                    if (d == 0 && e == 0) {
                        obj->x = fn_800A48EC(obj->x, obj->y+0x700)-0x600;
                        obj->mode = 4;
                        obj->dir = 3;
                    }
                }
            } else if (obj->dir == 1) {
                d = fn_800A3CD4(obj->x+0x600, obj->y);
                if (d) {
                    obj->x += d;
                    if (obj->mode == 1) obj->dir = 2;
                    if (obj->mode == 2) obj->step++;
                    obj->mode = 4;
                }
                if (obj->mode == 1) {
                    d = fn_800A36F8(obj->x-0x600, obj->y+0x700);
                    e = fn_800A36F8(obj->x+0x600, obj->y+0x700);
                    if (d == 0 && e == 0) {
                        obj->x = fn_800A4C0C(obj->x, obj->y+0x700)+0x600;
                        obj->mode = 3;
                        obj->dir = 3;
                    }
                }
            }
        }
        if (obj->mode == 2) {
            if (obj->dir == 0) {
                if (obj->x < lbl_804EE984->x) obj->step++;
            } else if (obj->dir == 1) {
                if (obj->x > lbl_804EE984->x) obj->step++;
            }
        }
        break;
    case 2:
        obj->vy = 0x380;
        obj->step++;
    case 3:
        obj->y += obj->vy;
        if (fn_80080484(lbl_80304B90.cam, &obj->x, 1) > 0xA00) {
            obj->unkA &= ~1;
            obj->unkA &= 0xFD;
            fn_800E9244(obj);
            obj->unk18 = lbl_80270168[obj->unk9][3];
            obj->unk10 = 3;
            obj->unk11 = 0;
            obj->step = 0;
            obj->unk13 = 0;
            return;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
