#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800B9F74 {
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
    /* 0x22 */ u8 pad22[0x24 - 0x22];
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u8 pad26[0x2A - 0x26];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ struct Unk800B9F74* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7D - 0x68];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 unk7E;
    /* 0x7F */ u8 pad7F[0xAC - 0x7F];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xF8 - 0xCD];
    /* 0xF8 */ u32 unkF8;
} Unk800B9F74;


extern u16* lbl_8027EB54[];

void fn_800E9424(Unk800B9F74* obj, u16 anim);
void fn_800E947C(Unk800B9F74* obj, u8 id, s8 arg2, s8 arg3);
void fn_800E946C(Unk800B9F74* obj, u8 id);
void fn_800B68FC(Unk800B9F74* obj, u32 id, u8 arg2);

void fn_800B9F74(Unk800B9F74* obj, u32 id) {
    u8 a;
    s32 b;
    u16 anim;

    if (((id >> 24) & 0xF) != 0 && ((id >> 24) & 0xF) == ((obj->unkF8 >> 24) & 0xF)) {
        obj->unkF8 = id;
        b = (s8)obj->unk7E;
        anim = lbl_8027EB54[obj->unk9][(id >> 8) & 0xF];
        a = obj->unk7D;
        if (anim != obj->unk24) {
            fn_800E9424(obj, anim);
        }
        fn_800E947C(obj, id, a, b);
        fn_800B68FC(obj, id, a);
    } else {
        obj->unkF8 = id;
        anim = lbl_8027EB54[obj->unk9][(id >> 8) & 0xF];
        if (anim != obj->unk24) {
            fn_800E9424(obj, anim);
        }
        fn_800E946C(obj, id);
        fn_800B68FC(obj, id, 0);
    }
}
