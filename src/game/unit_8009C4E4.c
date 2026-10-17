#include "types.h"

typedef struct Unk804ECDE0Entry {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 pad8[0xC - 0x8];
    /* 0x0C */ s32 unkC;
} Unk804ECDE0Entry;

typedef struct Unk8009C4E4 {
    /* 0x00 */ u8 pad0[0x9];
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
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x4C - 0x22];
    /* 0x4C */ void* unk4C;
    /* 0x50 */ u8 pad50[0x60 - 0x50];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 unk70[0xC8 - 0x70];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ s32 unkCC;
    /* 0xD0 */ u8 unkD0;
    /* 0xD1 */ u8 padD1;
    /* 0xD2 */ u8 unkD2;
} Unk8009C4E4;

extern u8 lbl_803140C0[];
extern u8 lbl_80274B88[];
extern u16 lbl_80274B94[];
extern Unk804ECDE0Entry* lbl_804ECDE0[];
extern void* lbl_804EE984;

void fn_800E9244(Unk8009C4E4* obj);
s32 fn_800B58F8(void* parent, s32 arg1);
void fn_800E9A84(Unk8009C4E4* obj, u16 id);
void fn_800E9424(Unk8009C4E4* obj, u16 anim);
void fn_800E946C(Unk8009C4E4* obj, u8 arg1);
s32 fn_800A43B4(s32 x, s32 y);
u16 fn_800A3458(s32 x, s32 y);
void fn_8009C7A0(Unk8009C4E4* obj);

static inline void Kill(Unk8009C4E4* obj) {
    obj->unkA &= ~1;
    obj->unkA &= 0xFD;
    fn_800E9244(obj);
    obj->unk18 = lbl_804ECDE0[obj->unk9]->unkC;
    obj->unk10 = 3;
    obj->unk11 = 0;
    obj->unk12 = 0;
    obj->unk13 = 0;
}

void fn_8009C4E4(Unk8009C4E4* obj) {
    u8 anim = lbl_80274B88[obj->unk14];
    u16 id = lbl_80274B94[obj->unk14];

    if (lbl_803140C0[0x227C] == 3) {
        if ((u8)(obj->unk14 + 0xF9) <= 1) {
            Kill(obj);
            return;
        }
        if (obj->unk14 == 4) {
            Kill(obj);
            return;
        }
    }
    if (fn_800B58F8(lbl_804EE984, 2)) {
        if ((u8)(obj->unk14 + 0xF9) <= 1) {
            Kill(obj);
            return;
        }
        if (anim == 4) {
            anim = 0xD;
        }
    }
    if (id != 1) {
        fn_800E9A84(obj, id);
    }
    fn_800E9424(obj, 1);
    obj->unk4C = obj->unk70;
    fn_800E946C(obj, anim);
    obj->unkA |= 2;
    obj->unkB &= 0xDF;
    obj->unk21 = obj->unk20;
    obj->unk18 = lbl_804ECDE0[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->unk11 = 0;
    obj->unk12 = 0;
    obj->unk13 = 0;
    if (obj->unk15 != 3) {
        if (obj->unk15 == 2) {
            obj->y = fn_800A43B4(obj->x, obj->y);
            obj->vx = 0;
            obj->vy = 0;
        } else {
            obj->vx = 0;
            obj->vy = 0;
            if (obj->unkD0 != 0) {
                obj->unk12 = 0;
            } else {
                obj->unk12 = 10;
            }
            if (fn_800A3458(obj->x, obj->y)) {
                obj->unk11 = 1;
            }
        }
    }
    obj->unk16 = 0xF0;
    obj->unkCC = obj->y;
    obj->unkC8 = 0;
    obj->unkD2 = 0;
    fn_8009C7A0(obj);
}
