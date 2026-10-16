#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D7494 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2A - 0x22];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ struct Unk800D7494* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x88 - 0x68];
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 pad89[0xAC - 0x89];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800D7494;


typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x2247];
    /* 0x2247 */ u8 unk2247;
} Unk803140C0;

extern Unk803140C0 lbl_803140C0;
extern u8 lbl_80280908[];
extern Vec2i lbl_80280918[];

void fn_800E946C(Unk800D7494* obj, u8 id);
u8 fn_800E976C(Unk800D7494* obj);
u8 fn_800D7BF8(Unk800D7494* obj);
void fn_800E97F0(Unk800D7494* obj, u8 frame);
void fn_800E9750(Unk800D7494* obj, u16 arg1);

static inline u8 Flag(Unk803140C0* w) {
    return w->unk2247 & 0x20;
}

void fn_800D7494(Unk800D7494* obj) {
    Unk803140C0* w = &lbl_803140C0;
    s32 lit;

    switch (obj->step) {
    case 0:
        if (obj->unk15 == 10) {
            fn_800E946C(obj, 0xC);
        } else if (obj->unk15 == 9) {
            fn_800E946C(obj, ((w->unk2247 >> 5) & 1) + 0xC);
            obj->unk16 = (w->unk2247 >> 5) & 1;
        } else {
            fn_800E946C(obj, lbl_80280908[obj->unk15]);
        }
        obj->unk88 = fn_800E976C(obj);
        obj->unk60 = lbl_80280918[obj->unk15].x;
        obj->unk64 = lbl_80280918[obj->unk15].y + 0x1000;
        obj->step++;
    case 1:
        if (fn_800D7BF8(obj)) {
            fn_800E97F0(obj, obj->unk88 + 1);
        }
        if (obj->unk15 == 9) {
            lit = Flag(w) != 0;
            if (obj->unk15 != lit) {
                fn_800E946C(obj, lit + 0xC);
                obj->unk16 = (w->unk2247 >> 5) & 1;
            }
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
