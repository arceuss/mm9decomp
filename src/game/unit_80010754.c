#include "types.h"
#include "game/sound.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80010754 {
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
    /* 0x34 */ struct Unk80010754* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk80010754;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x125];
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x2D8 - 0x126];
    /* 0x2D8 */ u32 unk2D8;
} Unk80304B90;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern Unk80280390Entry* lbl_802638A0[];
extern Unk80304B90 lbl_80304B90;
extern s32 lbl_80262060[];
extern s32 lbl_80262078[];
extern void* lbl_804EE984;

void fn_800E9244(Unk80010754* obj);
void fn_800E9750(Unk80010754* obj, u16 arg1);
void fn_800E9AA0(Unk80010754* obj, s32 arg1, s32 arg2);
void fn_800E9C90(Unk80010754* obj);
void fn_800E9CB8(Unk80010754* obj);
void fn_80040AD0(s32 kind, Vec2i* pos, s32 arg2, s32 arg3);
void fn_800D5234(s32 id);
void fn_800C7770(void* player);

static inline void Explode(Unk80010754* obj, Vec2i* pos) {
    if (obj->unk16 % 16 == 0) {
        pos->x = obj->unk60 + lbl_80262060[obj->unk17];
        pos->y = obj->unk64 + lbl_80262078[obj->unk17];
        obj->unk17++;
        fn_80040AD0(3, pos, 0, 0);
        fn_800D5234(SE_EXPLOSION);
    }
}

void fn_80010754(Unk80010754* obj) {
    Vec2i pos;

    switch (obj->step) {
    case 0:
        fn_800E9244(obj);
        obj->unk16 = 0x5F;
        obj->unk17 = 0;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        Explode(obj, &pos);
        obj->unk16--;
        if (obj->unk17 == 3) {
            obj->step++;
        }
        break;
    case 2:
        fn_800E9AA0(obj, 3, 0);
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        fn_800E9C90(obj);
        Explode(obj, &pos);
        if (obj->unk16 == 0) {
            fn_800C7770(lbl_804EE984);
            if (!(lbl_80304B90.unk2D8 & 1)) {
                lbl_80304B90.unk2D8 |= 2;
            }
            obj->step++;
        } else {
            obj->unk16--;
        }
        break;
    case 4:
        obj->flagsA &= ~1;
        lbl_80304B90.unk125 |= 2;
        lbl_80304B90.unk2D8 &= 0xFFFD;
        fn_800E9CB8(obj);
        obj->unk18 = lbl_802638A0[obj->unk9]->unk10;
        obj->unk10 = 4;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
        break;
    }
}
