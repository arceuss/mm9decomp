#include "types.h"

typedef struct Unk800C0C74Parent {
    /* 0x000 */ u8 pad0[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} Unk800C0C74Parent;

typedef struct Unk800C0C74 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800C0C74Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0xC9 - 0x70];
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 padCA;
    /* 0xCB */ u8 dir;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 unkCD;
    /* 0xCE */ u8 timer;
} Unk800C0C74;

extern u32* lbl_8027F228[];
extern s32 (*lbl_8027F160[])(s32 x, s32 y);

void fn_800E9244(Unk800C0C74* obj);
void fn_800E9750(Unk800C0C74* obj, u16 arg1);

static inline void SetState(Unk800C0C74* obj, u8 n) {
    obj->unk18 = lbl_8027F228[obj->kind][n];
    obj->unk10 = n;
    obj->unk11 = 0;
    obj->unk12 = 0;
    obj->unk13 = 0;
}

void fn_800C0C74(Unk800C0C74* obj) {
    s32 n;
    Unk800C0C74Parent* p;
    u32 vert;
    u32 d;
    u32 lo;
    s32 s;
    u8 e;
    s32 x;
    s32 y;
    s32 r;

    if (--obj->timer == 0) {
        SetState(obj, 2);
        SetState(obj, 4);
        fn_800E9244(obj);
        obj->unkA &= ~1;
        p = obj->parent;
        n = p->unk1F8;
        n -= obj->unkC9;
        if (n < 0) {
            n = 0;
        }
        p->unk1F8 = n;
        return;
    }
    d = obj->dir;
    vert = d & 2;
    s = ((d & 1) << 1) - 1;
    lo = d & 1;
    if (!vert) {
        e = obj->unkCD;
        x = 0x601;
        y = 0x601;
        x *= -s;
        y *= ((e & 1) << 1) - 1;
        x += obj->x;
        y += obj->y;
    } else {
        e = obj->unkCC;
        x = 0x601;
        y = 0x601;
        x *= ((e & 1) << 1) - 1;
        y *= -s;
        x += obj->x;
        y += obj->y;
    }
    if (e != 4) {
        r = lbl_8027F160[vert | ((lo + 1) & 1)](x, y);
    } else {
        r = 0;
    }
    if (!vert) {
        if ((u32)(r * s - 1) <= 0x47F) {
            obj->x = obj->x + r - s;
            obj->dir = obj->unkCD;
            obj->unkCC = vert | ((lo + 1) & 1);
        } else {
            r = lbl_8027F160[d]((obj->x += obj->vx * s) + s * 0x600, obj->y);
            if (r * s < 0) {
                obj->x += r;
                if (obj->unkCD == 2) {
                    obj->dir = 3;
                } else if (obj->unkCD == 3) {
                    obj->dir = 2;
                }
                obj->unkCC = d;
            }
        }
    } else {
        if ((u32)(r * s - 1) <= 0x47F) {
            obj->y = obj->y + r - s;
            obj->dir = obj->unkCC;
            obj->unkCD = vert | ((lo + 1) & 1);
        } else {
            r = lbl_8027F160[d](obj->x, (obj->y += obj->vy * s) + s * 0x600);
            if (r * s < 0) {
                obj->y += r;
                if (obj->unkCC == 0) {
                    obj->dir = 1;
                } else if (obj->unkCC == 1) {
                    obj->dir = 0;
                } else {
                    obj->dir = (obj->unkA >> 4) & 1;
                }
                obj->unkCD = d;
            }
        }
    }
    fn_800E9750(obj, 0xFFFF);
}
