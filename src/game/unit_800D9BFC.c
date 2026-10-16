#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk802819B0Entry;

typedef struct Unk800D9BFCPos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800D9BFCPos;

typedef struct Unk800D9BFCParent {
    /* 0x000 */ u8 pad0[0x26D];
    /* 0x26D */ s8 selA;
    /* 0x26E */ s8 selB;
    /* 0x26F */ s8 column;
    /* 0x270 */ u8 unk270;
    /* 0x271 */ u8 pad271[0x276 - 0x271];
    /* 0x276 */ u8 unk276;
} Unk800D9BFCParent;

typedef struct Unk800D9BFC {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 column;
    /* 0x15 */ u8 pad15[0x17 - 0x15];
    /* 0x17 */ u8 blink;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800D9BFCParent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x8A - 0x68];
    /* 0x8A */ u8 selA;
    /* 0x8B */ u8 selB;
} Unk800D9BFC;

extern Unk802819B0Entry* lbl_802819B0[];
extern Unk800D9BFCPos lbl_80280E28[];

void fn_800E9750(Unk800D9BFC* obj, u16 arg1);

static inline void Blink(Unk800D9BFC* obj) {
    u8 t = obj->blink + 1;

    obj->blink = t & 0x1F;
    if ((t >> 4) & 1) {
        obj->flagsA &= ~1;
    } else {
        obj->flagsA |= 1;
    }
}

static inline void Place(Unk800D9BFC* obj) {
    Unk800D9BFCParent* parent = obj->parent;
    s8 col = parent->column;

    if (col == obj->column && col == 0) {
        obj->x = lbl_80280E28[parent->selA].x;
        obj->y = lbl_80280E28[parent->selA].y;
        obj->selA = parent->selA;
    } else if (col == obj->column && col == 1) {
        obj->x = lbl_80280E28[parent->selB + 2].x;
        obj->y = lbl_80280E28[parent->selB + 2].y;
        obj->selB = parent->selB;
    }
}

void fn_800D9BFC(Unk800D9BFC* obj) {
    Unk800D9BFCParent* parent = obj->parent;

    if (parent->unk276 == 1) {
        obj->unk18 = lbl_802819B0[obj->kind]->unk8;
        obj->unk10 = 2;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
        return;
    }
    if (parent->unk270 == 1) {
        if (parent->column == obj->column) {
            if (obj->selA == parent->selA && parent->column == 0) {
                Blink(obj);
            } else if (obj->selB == parent->selB && parent->column == 1) {
                Blink(obj);
            } else {
                obj->blink = 0;
                obj->flagsA |= 1;
            }
        }
    } else {
        obj->flagsA |= 1;
    }
    fn_800E9750(obj, 0xFFFF);
    Place(obj);
}
