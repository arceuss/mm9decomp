#include "types.h"
#include "game/sound.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8000F3CC {
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
    /* 0x1C */ struct Unk8000F3CC* unk1C;
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2A - 0x22];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ struct Unk8000F3CC* parent;
    /* 0x38 */ void* unk38;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x88 - 0x68];
    /* 0x88 */ u8 unk88[0xAC - 0x88];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xB6 - 0xB0];
    /* 0xB6 */ s16 unkB6;
    /* 0xB8 */ s16 unkB8;
    /* 0xBA */ u8 padBA[0xC8 - 0xBA];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk8000F3CC;

typedef struct Unk8031BF70 {
    /* 0x000 */ u8 pad0[0x28C];
    /* 0x28C */ u16 unk28C;
} Unk8031BF70;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x125];
    /* 0x125 */ u8 unk125;
} Unk80304B90;

extern Unk8031BF70 lbl_8031BF70;
extern Unk80304B90 lbl_80304B90;
extern u8 lbl_80261EB0[];

void fn_800A2294(void);
void fn_800E946C(Unk8000F3CC* obj, u8 id);
void fn_800E9AA0(Unk8000F3CC* obj, s32 arg1, s32 arg2);
void fn_800C7594(s32 arg0);
void fn_800E9750(Unk8000F3CC* obj, u16 arg1);
void fn_800E9C90(Unk8000F3CC* obj);
void* fn_8005FBA8(Unk8000F3CC* obj, s32 x, s32 y, s32 kind, s32 arg4);
void fn_800D5234(s32 id);
void fn_8009996C(void* sprite, void* anim);

void fn_8000F3CC(Unk8000F3CC* obj) {
    switch (obj->step) {
    case 0:
        if ((lbl_8031BF70.unk28C & 0x7F) == 10) {
            fn_800A2294();
        }
        obj->unk60 = obj->unk60 / 0x10000 * 0x10000 + 0x8000;
        fn_800E946C(obj, 0);
        fn_800E9AA0(obj, 0, 0);
        fn_800C7594(0);
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        fn_800E9C90(obj);
        if (obj->unk1C->unk9 & 1) {
            obj->step++;
        } else {
            obj->unk16--;
        }
        break;
    case 2:
        fn_800E9AA0(obj, 1, 0);
        fn_8005FBA8(obj, obj->unk60, obj->unk64, 3, 0);
        obj->unk38 = fn_8005FBA8(obj, obj->unk60 - 0x6C00, obj->unk64 + 0x1000, 1, 0);
        fn_8005FBA8(obj, obj->unk60 - 0x6C00, obj->unk64 + 0x1000, 0, 0);
        obj->unk17 = 0;
        obj->unk16 = 0x78;
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        fn_800E9C90(obj);
        if (obj->unk16 == 0) {
            obj->step++;
        } else {
            obj->unk16--;
        }
        break;
    case 4:
        obj->unk17 = 0;
        obj->unk13 = 0;
        obj->unk16 = 0x78;
        obj->step++;
    case 5:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk17 <= 0x1C && obj->unk13 % 4 == 0) {
            fn_800D5234(SE_GAGE);
            obj->unkB8 = obj->unk17;
            obj->unkB6 = obj->unk17;
            obj->unk13 = 0;
            obj->unk17++;
        }
        obj->unk13++;
        if (!(lbl_80304B90.unk125 & 1)) {
            fn_8009996C(obj->unk88, lbl_80261EB0);
            obj->state = 1;
            obj->step = 0;
        }
        break;
    }
}
