#include "types.h"

typedef struct Unk800EA8DCEntry {
    /* 0x0 */ s32 unk0;
} Unk800EA8DCEntry;

typedef struct Unk800EA8DC {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 padA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x18 - 0xC];
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
} Unk800EA8DC;

extern Unk800EA8DCEntry* lbl_8027EB98[];
extern Unk800EA8DCEntry* lbl_802638A0[];
extern Unk800EA8DCEntry* lbl_80270168[];
extern Unk800EA8DCEntry* lbl_80265138[];
extern Unk800EA8DCEntry* lbl_80280390[];
extern Unk800EA8DCEntry* lbl_804ECDE0[];
extern Unk800EA8DCEntry* lbl_8027F228[];
extern void* lbl_804EE664;
extern void* lbl_804EE738;
extern void* lbl_804EE810;
extern void* lbl_804EE730;
extern void* lbl_804EE908;
extern void* lbl_804EE878;
extern void* lbl_804EE8C0;

Unk800EA8DC* fn_800AB87C(void);
Unk800EA8DC* fn_800E8C44(void* pool);
Unk800EA8DC* fn_800E8BEC(void* pool);
void fn_80042DA0(Unk800EA8DC* obj, u8 kind);
void fn_800BBBFC(Unk800EA8DC* obj, s32 arg1);

Unk800EA8DC* fn_800EA8DC(u32 type, u8 kind) {
    Unk800EA8DC* obj;

    switch (type) {
    case 0:
        obj = fn_800AB87C();
        if (obj != NULL) {
            obj->unk2E = 0x10;
            obj->kind = kind;
            obj->unk18 = lbl_8027EB98[kind]->unk0;
        }
        break;
    case 1:
        obj = fn_800E8C44(lbl_804EE664);
        if (obj != NULL) {
            obj->unk2E = 0x10;
            obj->kind = kind;
            obj->unk18 = lbl_802638A0[kind]->unk0;
            obj->unk2A = 0;
            obj->unk2C = 0;
            obj->unk2F = 0;
            obj->flagsB |= 0x20;
            obj->unk21 = obj->unk20;
        }
        break;
    case 2:
        obj = fn_800E8C44(lbl_804EE738);
        if (obj != NULL) {
            fn_80042DA0(obj, kind);
        }
        break;
    case 3:
        obj = fn_800E8C44(lbl_804EE810);
        if (obj != NULL) {
            obj->unk2E = 0x10;
            obj->kind = kind;
            obj->unk18 = lbl_80270168[kind]->unk0;
            obj->unk2A = 0;
            obj->unk2C = 0;
            obj->unk2F = 0;
        }
        break;
    case 4:
        obj = fn_800E8C44(lbl_804EE730);
        if (obj != NULL) {
            obj->unk2E = 0x10;
            obj->kind = kind;
            obj->unk18 = lbl_80265138[kind]->unk0;
            obj->unk2A = 0;
            obj->unk2C = 0;
            obj->unk2F = 0;
            obj->flagsB |= 0x20;
            obj->unk21 = obj->unk20;
        }
        break;
    case 5:
        obj = fn_800E8BEC(lbl_804EE908);
        if (obj != NULL) {
            obj->unk2E = 0x10;
            obj->kind = kind;
            obj->unk18 = lbl_80280390[kind]->unk0;
            obj->unk2A = 0;
            obj->unk2C = 0;
            obj->unk2F = 0;
            obj->flagsB |= 0x20;
            obj->unk21 = obj->unk20;
        }
        break;
    case 6:
        obj = fn_800E8C44(lbl_804EE878);
        if (obj != NULL) {
            obj->unk2E = 0x10;
            obj->kind = kind;
            obj->unk18 = lbl_804ECDE0[kind]->unk0;
            obj->unk2A = 0;
            obj->unk2C = 0;
            obj->unk2F = 0;
            obj->flagsB |= 0x20;
            obj->unk21 = obj->unk20;
        }
        break;
    case 8:
        obj = fn_800E8C44(lbl_804EE8C0);
        if (obj != NULL) {
            obj->kind = kind;
            obj->unk18 = lbl_8027F228[kind]->unk0;
            fn_800BBBFC(obj, 0xFF);
            obj->unk2E = 0x10;
            obj->unk2A = 0;
            obj->unk2C = 0;
            obj->unk2F = 0;
            obj->flagsB &= 0xDF;
            obj->unk21 = obj->unk20;
        }
        break;
    default:
        obj = NULL;
        break;
    }
    return obj;
}
