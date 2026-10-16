#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80024854 {
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
    /* 0x34 */ struct Unk80024854* parent;
    /* 0x38 */ u8 pad38[0x40 - 0x38];
    /* 0x40 */ u8 unk40[0x8];
    /* 0x48 */ struct Unk80024854* unk48;
    /* 0x4C */ void* unk4C;
    /* 0x50 */ u8 pad50[0x60 - 0x50];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x88 - 0x68];
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 unk89;
    /* 0x8A */ u8 unk8A;
    /* 0x8B */ u8 unk8B;
    /* 0x8C */ u8 pad8C[0xAC - 0x8C];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk80024854;


typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

extern const Vec2i lbl_80263938[];

void fn_800E9424(Unk80024854* obj, s32 arg1);
void fn_800E7960(void* node, void* func);
void fn_80024620(void* owner, void* rect);
void fn_80024438(Unk80024854* obj);

void fn_80024854(Unk80024854* obj) {
    const Vec2i* pos;

    switch (obj->step) {
    case 0:
        fn_800E9424(obj, 8);
        obj->unk88 = 0;
        obj->unk89 = 7;
        obj->unk8B = 0;
        obj->flagsA |= 1;
        pos = &lbl_80263938[obj->unk14];
        obj->unk60 = pos->x;
        obj->unk64 = pos->y;
        obj->unk2A = obj->unk14 * 7;
        fn_800E7960(obj->unk40, fn_80024620);
        obj->unk48 = obj;
        obj->flagsA &= 0xF7;
        fn_80024438(obj);
        obj->step++;
    case 1:
        if (obj->unk8A != 0) {
            switch (obj->unk8A) {
            case 1:
                obj->flagsA |= 1;
                obj->unk8B = 1;
                obj->unk8A = 0;
                break;
            case 2:
                obj->flagsA &= ~1;
                obj->unk8B = 0;
                obj->unk8A = 0;
                break;
            }
        }
        break;
    }
}
