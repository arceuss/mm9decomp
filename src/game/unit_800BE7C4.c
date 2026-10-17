#include "types.h"

typedef struct Unk800BE7C4Parent {
    /* 0x000 */ u8 pad0[0x14];
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad15[0xA0 - 0x15];
    /* 0x0A0 */ u32 unkA0;
    /* 0x0A4 */ u8 padA4[0xB6 - 0xA4];
    /* 0x0B6 */ s16 unkB6;
    /* 0x0B8 */ u8 padB8[0x10C - 0xB8];
    /* 0x10C */ u8 unk10C;
    /* 0x10D */ u8 pad10D[0x1F8 - 0x10D];
    /* 0x1F8 */ u8 unk1F8;
} Unk800BE7C4Parent;

typedef struct Unk800BE7C4 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800BE7C4Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 padC9;
    /* 0xCA */ u8 unkCA;
} Unk800BE7C4;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
    /* 0x21D */ u8 pad21D[0x2A0 - 0x21D];
    /* 0x2A0 */ u16 unk2A0[1];
} Unk80304B90;

extern Unk803051D8 lbl_803051D8;
extern Unk80304B90 lbl_80304B90;
extern void** lbl_8027F228[];
extern s16 lbl_804ECF24[2];

void fn_800E9244(Unk800BE7C4* obj);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);

static inline void SetMode(Unk800BE7C4* obj, u8 mode) {
    obj->unk18 = lbl_8027F228[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

static inline void SetHP(Unk800BE7C4Parent* p, u8 amount) {
    s32 hp = p->unk1F8;

    hp -= amount;
    if (hp < 0) {
        hp = 0;
    }
    p->unk1F8 = hp;
}

static inline void Finish(Unk800BE7C4* obj) {
    SetMode(obj, 2);
    SetMode(obj, 4);
    fn_800E9244(obj);
    obj->flagsA &= ~1;
    SetHP(obj->parent, obj->unkC8);
}

BOOL fn_800BE7C4(Unk800BE7C4* obj) {
    Unk800BE7C4Parent* parent = obj->parent;

    if (obj->unkCA != parent->unk10C) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return TRUE;
    }
    if (lbl_803051D8.unk2 & 0x20) {
        Finish(obj);
        return TRUE;
    }
    if ((lbl_80304B90.unk2A0[parent->unk14] & 0x8000) &&
        ((parent->unkA0 & 0x200) || parent->unkB6 == 0)) {
        Finish(obj);
        return TRUE;
    }
    {
        u32 idx = obj->unk14;

        if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > lbl_804ECF24[idx]) {
            Finish(obj);
            return TRUE;
        }
    }
    return FALSE;
}
