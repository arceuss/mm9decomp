#include "types.h"

typedef struct Unk800C16AC {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 padD[0x11 - 0xD];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x24 - 0x17];
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u8 pad26[0x34 - 0x26];
    /* 0x34 */ struct Unk800C16AC* parent;
    /* 0x38 */ u8 pad38[0x50 - 0x38];
    /* 0x50 */ struct {
        u32 hi : 30;
        u32 lo : 2;
    } unk50;
    /* 0x54 */ u8 pad54[0x60 - 0x54];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 ay;
    /* 0x78 */ u8 pad78[0x7F - 0x78];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0xCC - 0x80];
    /* 0xCC */ u8 unkCC;
} Unk800C16AC;

typedef struct Unk8027F1D8 {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk8027F1D8;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 cam[0x260 - 0x21C];
    /* 0x260 */ s32 unk260;
} Unk80304B90;

extern u16 lbl_8027F19C[];
extern Unk8027F1D8 lbl_8027F1D8[4];
extern Unk80304B90 lbl_80304B90;

void fn_800E9A84(Unk800C16AC* obj, s32 id);
void fn_800E9810(Unk800C16AC* obj, s32 id);
void fn_800E9424(Unk800C16AC* obj, u16 anim);
void fn_800E946C(Unk800C16AC* obj, u8 arg1);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
s32 fn_800A36F8(s32 x, s32 y);
u16 fn_8009E894(s32 x, s32 y);
void fn_800E9750(Unk800C16AC* obj, u16 arg1);

void fn_800C16AC(Unk800C16AC* obj) {
    Unk800C16AC* parent = obj->parent;
    s32 i;
    s32 dir;
    u16 anim;
    s32 lim;
    s32 r;

    switch (obj->step) {
    case 0:
        anim = lbl_8027F19C[0];
        if (anim == 0) {
            obj->unkB &= 0xFB;
            fn_800E9A84(obj, 0x142);
        } else {
            fn_800E9810(obj, 0x142);
            obj->unkC &= ~1;
        }
        fn_800E9424(obj, anim);
        obj->unk16 = 0;
        fn_800E946C(obj, lbl_8027F19C[1]);
        obj->vy = 0x200;
        obj->ay = 0x80;
        obj->step++;
    case 1:
        obj->y += obj->vy;
        lim = parent->y - 0x1400;
        if (lbl_80304B90.unk260 - 0x7000 <= obj->y && fn_80080484(lbl_80304B90.cam, &obj->x, 1) == 0 && obj->y >= lim) {
            r = fn_800A36F8(obj->x, lim);
            if (r < 0 && r > -0x1000 && obj->unkCC == 0) {
                obj->y = lim + r;
                obj->step++;
            } else {
                r = fn_800A36F8(obj->x, obj->y);
                if (r < 0 && r > -0x1000) {
                    obj->y += r;
                    obj->step++;
                }
            }
            obj->unkCC = 1;
        }
        obj->vy += obj->ay;
        if (obj->vy > 0x600) {
            obj->vy = 0x600;
        }
        dir = ((obj->unkA >> 3) & 2) - 1;
        obj->unk50.lo = 2;
        if (obj->unk24 == 0x10A) {
            for (i = 0; i < 4; i++) {
                if (fn_8009E894(obj->x + dir * lbl_8027F1D8[i].x, obj->y + lbl_8027F1D8[i].y) & 0x200) {
                    obj->unk50.lo = 3;
                    break;
                }
            }
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 2:
        anim = lbl_8027F19C[2];
        if (anim == 0) {
            obj->unkB &= 0xFB;
            fn_800E9A84(obj, 0x142);
        } else {
            fn_800E9810(obj, 0x142);
            obj->unkC &= ~1;
        }
        fn_800E9424(obj, anim);
        obj->unk16 = 1;
        fn_800E946C(obj, lbl_8027F19C[3]);
        obj->step++;
    case 3:
        dir = ((obj->unkA >> 3) & 2) - 1;
        obj->unk50.lo = 2;
        if (obj->unk24 == 0x10A) {
            for (i = 0; i < 4; i++) {
                if (fn_8009E894(obj->x + dir * lbl_8027F1D8[i].x, obj->y + lbl_8027F1D8[i].y) & 0x200) {
                    obj->unk50.lo = 3;
                    break;
                }
            }
        }
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7F == 3) {
            obj->unk11 = 1;
            obj->step = 0;
        }
        break;
    }
}
