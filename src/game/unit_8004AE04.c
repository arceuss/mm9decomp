#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8004AE04 {
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
    /* 0x34 */ struct Unk8004AE04* parent;
    /* 0x38 */ u8 pad38[0x40 - 0x38];
    /* 0x40 */ u8 unk40[0x48 - 0x40];
    /* 0x48 */ struct Unk8004AE04* unk48;
    /* 0x4C */ u8 pad4C[0x60 - 0x4C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD0 - 0xCD];
    /* 0xD0 */ u8 unkD0;
    /* 0xD1 */ u8 unkD1;
} Unk8004AE04;

extern Unk80280390Entry* lbl_80265138[];

typedef struct Unk8004AE04Node {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ Unk8004AE04* obj;
} Unk8004AE04Node;

extern Unk8004AE04* lbl_804EE984;

void fn_800E9424(Unk8004AE04* obj, s32 id);
void fn_800E947C(Unk8004AE04* obj, s32 arg1, s32 arg2, s32 arg3);
void fn_800E9750(Unk8004AE04* obj, u16 arg1);
void fn_800E8700(Unk8004AE04Node* node, s32 arg1);
void fn_800E7960(void* link, void (*func)(Unk8004AE04Node*, s32));

void fn_8004AE04(Unk8004AE04Node* node, s32 arg1) {
    Unk8004AE04* obj = node->obj;

    fn_800E9424(obj, 0xE);
    fn_800E947C(obj, 1, (s8)obj->unkD1, (s8)obj->unkD0);
    fn_800E9750(obj, 0xFFFF);
    if (obj->state == 0) {
        obj->unk60 = lbl_804EE984->unk60;
        obj->unk64 = lbl_804EE984->unk64 - 0x1800;
    }
    fn_800E8700(node, arg1);
    fn_800E7960(obj->unk40, fn_8004AE04);
    obj->unk48 = obj;
    obj->flagsA &= 0xF7;
}
