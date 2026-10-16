#include "types.h"
#include "game/sound.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8007A5D4 {
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
    /* 0x34 */ struct Unk8007A5D4* parent;
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
} Unk8007A5D4;

extern Unk80280390Entry* lbl_80270168[];

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[0x300 - 0x21C];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_800E9244(Unk8007A5D4* obj);
void fn_800D5234(s32 id);
u32 fn_80080484(void* arg0, s32* pos, s32 arg2);
void fn_800E9758(Unk8007A5D4* obj);

void fn_8007A5D4(Unk8007A5D4* obj) {
    switch (obj->step) {
    case 0:
        fn_800E9244(obj);
        obj->unk68 = -obj->unk68;
        obj->unk6C = -obj->unk6C;
        fn_800D5234(SE_REFLECT);
        obj->step++;
    case 1:
        obj->unk60 += obj->unk68;
        obj->unk64 += obj->unk6C;
        if (fn_80080484(lbl_80304B90.unk21C, &obj->unk60, 1)) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            fn_800E9244(obj);
            obj->unk18 = lbl_80270168[obj->unk9]->unkC;
            obj->unk10 = 3;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
            return;
        }
        break;
    }
    fn_800E9758(obj);
}
