#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D3E6C {
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
    /* 0x34 */ struct Unk800D3E6C* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0xAC - 0x70];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800D3E6C;


typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x124];
    /* 0x124 */ u8 unk124[2];
    /* 0x126 */ u8 unk126;
    /* 0x127 */ u8 pad127[0x2B0 - 0x127];
    /* 0x2B0 */ s32 unk2B0;
    /* 0x2B4 */ u8 pad2B4[0x300 - 0x2B4];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern u8 lbl_80272C10[];

void fn_800E9244(Unk800D3E6C* obj);
u8 fn_80072674(s32* pos);
void fn_800BA4D4(Unk800D3E6C* player, s32 arg1);
void fn_8008123C(void* machine, void* state);
void fn_800E9750(Unk800D3E6C* obj, u16 arg1);

void fn_800D3E6C(Unk800D3E6C* obj) {
    Unk800D3E6C* player;
    u8 dir;

    switch (obj->step) {
    case 0:
        obj->unk16 = 0;
        obj->step++;
    case 1:
        if (++obj->unk16 > 8) {
            obj->unk16 = 0;
        }
        if (obj->unk16 < 4) {
            obj->flagsA |= 1;
        } else {
            obj->flagsA &= ~1;
        }
        break;
    case 2:
        obj->flagsA &= ~1;
        fn_800E9244(obj);
        obj->step++;
    case 3:
        player = obj->parent;
        if (lbl_80304B90.unk2B0 == 0) {
            dir = fn_80072674(&obj->unk68);
            player->unk60 = obj->unk68;
            player->unk64 = obj->unk6C;
            fn_800BA4D4(player, dir);
            lbl_80304B90.unk126 &= ~2;
            fn_8008123C(lbl_80304B90.unk124, lbl_80272C10);
            obj->step++;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
