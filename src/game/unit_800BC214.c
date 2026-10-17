#include "types.h"

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

typedef struct Unk8027F3C8Entry {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk8027F3C8Entry;

typedef struct Unk800BC214Owner {
    /* 0x000 */ u8 pad0[0x10C];
    /* 0x10C */ u8 unk10C;
    /* 0x10D */ u8 pad10D[0x1F8 - 0x10D];
    /* 0x1F8 */ u8 unk1F8;
} Unk800BC214Owner;

typedef struct Unk800BC214 {
    /* 0x00 */ u8 pad0[9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x24 - 0x1C];
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u8 pad26[0x34 - 0x26];
    /* 0x34 */ Unk800BC214Owner* unk34;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ struct {
        u32 a : 21;
        u32 f : 1;
        u32 b : 10;
    } unk54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ u8 unk60[0x8];
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0xA0 - 0x70];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xC8 - 0xA4];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 unkCA;
    /* 0xCB */ u8 unkCB;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 unkCD;
} Unk800BC214;

extern Unk8027F3C8Entry* lbl_8027F228[];
extern Unk803051D8 lbl_803051D8;
extern u8 lbl_80304B90[];

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u8 unkC;
} Unk8038DC58;

extern void (*lbl_804ECEB4)(Unk800BC214* obj);
extern u8 lbl_804ECEB8[8];
extern s16 lbl_804ECEC0[4];
extern u16 lbl_8027EE40[];
extern Unk8038DC58 lbl_8038DC58;

u32 fn_80080484(u8* a, u8* b, int c);
void fn_800E9244(Unk800BC214* obj);
void fn_800D5234(s32 se);
void fn_800E9810(Unk800BC214* obj, s32 id);
void fn_800E9A84(Unk800BC214* obj, s32 id);
void fn_800E9424(Unk800BC214* obj, u16 anim);
void fn_800E946C(Unk800BC214* obj, u8 arg1);

static inline void Kill(Unk800BC214* obj) {
    obj->unk18 = lbl_8027F228[obj->unk9]->unk8;
    obj->unk10 = 2;
    obj->unk11 = 0;
    obj->unk12 = 0;
    obj->unk13 = 0;
    obj->unk18 = lbl_8027F228[obj->unk9]->unk10;
    obj->unk10 = 4;
    obj->unk11 = 0;
    obj->unk12 = 0;
    obj->unk13 = 0;
    fn_800E9244(obj);
    obj->unkA &= ~1;
    lbl_804ECEB4(obj);
}

s32 fn_800BC214(Unk800BC214* obj) {
    u16 anim;
    u32 f;
    s32 v;

    if (obj->unkCB != obj->unk34->unk10C) {
        Kill(obj);
        return 1;
    }
    if (lbl_803051D8.unk2 & 0x20) {
        Kill(obj);
        return 1;
    }
    if (obj->unkC8 != 0) {
        Kill(obj);
        return 1;
    }
    if (obj->unkA0 & 0x80000) {
        Kill(obj);
        return 1;
    }
    if (obj->unkA0 & 0x1000) {
        fn_800D5234(0x3E);
        if (obj->unk15 == 2) {
            obj->unk15 = 1;
            obj->unk14 = 1;
            anim = lbl_8027EE40[2];
            if (anim == 0x100) {
                fn_800E9810(obj, 0x141);
            } else {
                obj->unkB &= 0xFB;
            }
            fn_800E9A84(obj, 0x144);
            if (obj->unk24 != anim) {
                fn_800E9424(obj, anim);
            }
            obj->unk16 = 1;
            fn_800E946C(obj, lbl_804ECEB8[3]);
        }
        v = (obj->vx >> 31) * 2 + 1;
        obj->vy = -0x390;
        obj->vx = 0x4C0;
        obj->vx = -(obj->vx * v);
        f = ((obj->unkA >> 4) & 1) ^ 1;
        if (f) {
            obj->unkA |= 0x10;
        } else {
            obj->unkA &= 0xEF;
        }
        obj->unk54.f = f;
        fn_800E9244(obj);
    }
    if (fn_80080484(lbl_80304B90 + 0x21C, obj->unk60, 1) > lbl_804ECEC0[obj->unk15]) {
        if (obj->unkA & 4) {
            lbl_8038DC58.unkC |= 2;
        }
        Kill(obj);
        return 1;
    }
    return 0;
}
