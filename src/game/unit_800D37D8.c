#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800D37D8 {
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
    /* 0x34 */ struct Unk800D37D8* parent;
    /* 0x38 */ u8 pad38[0x4C - 0x38];
    /* 0x4C */ s32* unk4C;
    /* 0x50 */ u8 pad50[0x60 - 0x50];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 unk68[0x70 - 0x68];
    /* 0x70 */ s32 unk70[2];
    /* 0x78 */ u8 pad78[0xAC - 0x78];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800D37D8;

extern Unk80280390Entry* lbl_80280390[];

typedef struct Unk803051D8 {
    /* 0x00 */ u8 flags[0x38];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern s32 lbl_80280340[8];
extern u8 lbl_80280328[];
extern void (*lbl_804ED2F8[2])(Unk800D37D8* obj);

s32 fn_800E88E4(void* work, s32* pos);
void fn_800E91F0(Unk800D37D8* obj, void* data, s32 arg2);
void fn_800E9424(Unk800D37D8* obj, s32 id);
void fn_800E946C(Unk800D37D8* obj, u8 id);
void fn_800E9244(Unk800D37D8* obj);
void fn_800D372C(void*);

static inline BOOL IsFlagSet(s32 bit) {
    return lbl_803051D8.flags[bit >> 3] & (1 << (bit & 7));
}

void fn_800D37D8(Unk800D37D8* obj) {
    s32 index;
    s32 i;

    if (obj->unk15 == 0) {
        obj->unk60 &= ~0xFFF;
        obj->unk64 &= ~0xFFF;
        index = fn_800E88E4(obj->unk68, &obj->unk60);
        if (index < 0) {
            return;
        }
        obj->unk14 = index;
        obj->unk15++;
    }
    if (obj->unk14 >= 8) {
        for (i = 0; i < 8; i++) {
            if (!IsFlagSet(lbl_80280340[i])) {
                return;
            }
        }
    }
    obj->unk70[0] = obj->unk60;
    obj->unk70[1] = obj->unk64 - 0x2800;
    obj->unk18 = lbl_80280390[obj->unk9]->unk4;
    obj->unk10 = 1;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = 0;
    fn_800E91F0(obj, lbl_80280328, 1);
    obj->unkAC = fn_800D372C;
    obj->flagsA |= 3;
    fn_800E9424(obj, 0x4F);
    fn_800E946C(obj, 0);
    obj->unk16 = 0;
    obj->unk4C = obj->unk70;
    if (obj->unk14 < 8 && IsFlagSet(lbl_80280340[obj->unk14])) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        obj->unk18 = lbl_80280390[obj->unk9]->unkC;
        obj->unk10 = 3;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
    } else {
        lbl_804ED2F8[obj->state](obj);
    }
}
