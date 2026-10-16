#include "types.h"
#include "game/sound.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80022294 {
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
    /* 0x1C */ struct Unk80022294* unk1C;
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2A - 0x22];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ struct Unk80022294* unk34;
    /* 0x38 */ struct Unk80022294* unk38;
    /* 0x3C */ u8 pad3C[0x54 - 0x3C];
    /* 0x54 */ u32 unk54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x88 - 0x78];
    /* 0x88 */ u8 unk88[0xAC - 0x88];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xB6 - 0xB0];
    /* 0xB6 */ s16 unkB6;
    /* 0xB8 */ s16 unkB8;
    /* 0xBA */ u8 padBA[0xC8 - 0xBA];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD8 - 0xCD];
    /* 0xD8 */ u8 unkD8;
    /* 0xD9 */ u8 unkD9;
    /* 0xDA */ u8 unkDA;
    /* 0xDB */ u8 unkDB;
} Unk80022294;

typedef struct Unk8031BF70 {
    /* 0x000 */ u8 pad0[0x28C];
    /* 0x28C */ u16 unk28C;
} Unk8031BF70;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x125];
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x21C - 0x126];
    /* 0x21C */ u8 unk21C[0x25C - 0x21C];
    /* 0x25C */ s32 unk25C;
    /* 0x260 */ s32 unk260;
} Unk80304B90;

extern Unk8031BF70 lbl_8031BF70;
extern Unk80304B90 lbl_80304B90;
extern u8 lbl_80263270[];

void fn_800A2294(void);
void fn_800E946C(Unk80022294* obj, u8 id);
void fn_800E9AA0(Unk80022294* obj, s32 arg1, s32 arg2);
void fn_800C7594(s32 arg0);
void fn_800E9750(Unk80022294* obj, u16 arg1);
void fn_800E9C90(Unk80022294* obj);
void* fn_8005FBA8(Unk80022294* obj, s32 x, s32 y, s32 kind, s32 arg4);
void fn_800D5234(s32 id);
void fn_8009996C(void* sprite, void* anim);

s32 fn_800A36F8(s32 x, s32 y);
void fn_80041C44(Unk80022294* obj, s32 arg1, s32 arg2);
void fn_800C7594(s32 arg0);

extern Unk80280390Entry* lbl_802638A0[];
extern void* lbl_804EE664;

Unk80022294* fn_800E8C44(void* pool);
void fn_8006CA38(Unk80022294* obj, s32 x, s32 y, s32 arg3, s32 arg4, u8 idx);

static inline Unk80022294* Spawn(Unk80022294* parent) {
    s32 y = parent->unk64;
    s32 x = parent->unk60;
    Unk80022294* obj = fn_800E8C44(lbl_804EE664);

    if (obj != NULL) {
        obj->unk2E = 0x10;
        obj->unk9 = 0xE;
        obj->unk18 = lbl_802638A0[0xE]->unk0;
        obj->unk2A = 0;
        obj->unk2C = 0;
        obj->unk2F = 0;
        obj->flagsB |= 0x20;
        obj->unk21 = obj->unk20;
        obj->unk34 = parent;
        obj->unk60 = x;
        obj->unk64 = y;
        obj->unk14 = 1;
    }
    return obj;
}

void fn_80022294(Unk80022294* obj) {
    u32 i;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 7);
        obj->unk38 = Spawn(obj);
        obj->unkDA = 0;
        obj->unkD8 = 0;
        for (i = 0; i < 12; i++) {
            fn_8006CA38(obj, obj->unk60, obj->unk64, 1, 0, i);
        }
        obj->unk60 = lbl_80304B90.unk25C - 0x10000 + 0x6200;
        obj->unk64 = lbl_80304B90.unk260 + 0x27FF;
        obj->step++;
    case 1:
        if (obj->unk1C->unk9 & 1) {
            obj->step++;
        }
        break;
    case 2:
        obj->unk68 = 0x180;
        obj->unk16 = 0x3C;
        obj->unk17 = 0;
        obj->step++;
    case 3:
        if (obj->unk17 == 0) {
            obj->unk60 += obj->unk68;
            if (obj->unk60 > lbl_80304B90.unk25C - 0x6000) {
                obj->unk60 = lbl_80304B90.unk25C - 0x6000;
                obj->unk17++;
            }
        } else if (obj->unk16 == 0) {
            obj->step++;
        } else {
            obj->unk16--;
        }
        break;
    case 4:
        obj->unk17 = 0;
        obj->unkB8 = 0;
        obj->unkB6 = 0;
        obj->unk13 = 0;
        obj->step++;
    case 5:
        if (obj->unk17 <= 0x1C) {
            if (obj->unk13 % 4 == 0) {
                fn_800D5234(SE_GAGE);
                obj->unkB8 = obj->unk17;
                obj->unkB6 = obj->unk17;
                obj->unk13 = 0;
                obj->unk17++;
            }
        } else if (!(lbl_80304B90.unk125 & 1)) {
            obj->state = 2;
            obj->step = 0;
            break;
        }
        obj->unk13++;
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
