#include "types.h"
#include "game/sound.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800E3814 {
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
    /* 0x34 */ struct Unk800E3814* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54_0 : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_22 : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x7F - 0x78];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0x88 - 0x80];
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 unk89;
    /* 0x8A */ u8 unk8A;
    /* 0x8B */ u8 pad8B[0xAC - 0x8B];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800E3814;

extern Unk80280390Entry* lbl_802819B0[];

void fn_800E946C(Unk800E3814* obj, u8 id);
void fn_800E9750(Unk800E3814* obj, u16 arg1);

static inline void SyncFlip(Unk800E3814* obj) {
    if (obj->flipX) {
        obj->flagsA |= 0x10;
    } else {
        obj->flagsA &= 0xEF;
    }
}

extern void* lbl_804EE948;
extern const s16 lbl_802537E8[0x100];

Unk800E3814* fn_800E8C44(void* pool);
void fn_800E9424(Unk800E3814* obj, u16 anim);
void fn_800D5234(s32 id);

void fn_800E3814(Unk800E3814* obj) {
    switch (obj->step) {
    case 0:
        fn_800E9424(obj, 0x108);
        fn_800E946C(obj, 0);
        obj->flipX = 1;
        SyncFlip(obj);
        obj->unk68 = 0x380;
        obj->unk6C = 0;
        obj->unk74 = 0x40;
        fn_800D5234(SE_CEMENTSHOT);
        obj->step++;
    case 1:
        obj->unk60 += obj->unk68;
        obj->unk64 += obj->unk6C;
        obj->unk6C += obj->unk74;
        if (obj->unk64 > 0x7600) {
            obj->unk64 = 0x7600;
            obj->step++;
        }
        break;
    case 2:
        fn_800E946C(obj, 1);
        obj->flipX = 0;
        SyncFlip(obj);
        fn_800D5234(SE_CEMENT_CONGEAL);
        obj->step++;
    case 3:
        if (obj->unk7F == 3) {
            obj->step++;
        }
        break;
    case 4:
        fn_800E946C(obj, 2);
        obj->unk16 = 0x2A;
        obj->step++;
    case 5:
        if (obj->unk16 == 0) {
            obj->step++;
        } else {
            obj->unk16--;
        }
        break;
    case 6:
        fn_800E946C(obj, 3);
        obj->unk16 = 0x1E;
        obj->step++;
    case 7:
        if (obj->unk16 == 0) {
            obj->step++;
        } else {
            obj->unk16--;
        }
        break;
    case 8:
        fn_800E946C(obj, 4);
        obj->unk16 = 8;
        obj->step++;
    case 9:
        if (obj->unk16 == 0) {
            obj->flagsA &= ~1;
            obj->flagsA &= 0xFD;
            obj->unk18 = lbl_802819B0[obj->unk9]->unkC;
            obj->unk10 = 3;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
            return;
        }
        obj->unk16--;
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
