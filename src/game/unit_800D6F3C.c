#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D6F3C {
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
    /* 0x34 */ struct Unk800D6F3C* parent;
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
} Unk800D6F3C;

extern Unk80280390Entry* lbl_802819B0[];

typedef struct Unk80316D78Sub {
    /* 0x00D41000 */ u8 pad0[0xD41000];
    /* 0x00D41000 */ u8 unk1000;
    /* 0x00D41001 */ u8 pad1001;
    /* 0x00D41002 */ u8 unk1002;
} Unk80316D78Sub;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ Unk80316D78Sub* unk3004;
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;
extern u8 lbl_804ED320[8];

void fn_800E946C(Unk800D6F3C* obj, u8 id);
void fn_800E97F0(Unk800D6F3C* obj, u8 frame);
void fn_800E9750(Unk800D6F3C* obj, u16 arg1);

void fn_800D6F3C(Unk800D6F3C* obj) {
    Unk80316D78Sub* sub;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, lbl_804ED320[obj->unk15]);
        if (obj->unk15 != 2 && obj->unk15 != 5) {
            fn_800E97F0(obj, obj->unk88 + 1);
        }
        obj->step++;
    case 1:
        if (obj->unk15 != 2 && obj->unk15 != 5) {
            sub = lbl_80316D78.unk3004;
            if (sub->unk1002 != 0 && sub->unk1000 == obj->unk15) {
                fn_800E97F0(obj, obj->unk88);
            } else {
                fn_800E97F0(obj, obj->unk88 + 1);
            }
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
