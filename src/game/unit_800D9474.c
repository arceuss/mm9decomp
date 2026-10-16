#include "types.h"

typedef struct Unk800D9474Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800D9474Pos;

typedef struct Unk800D9474Parent {
    /* 0x000 */ u8 pad0[0x277];
    /* 0x277 */ u8 slots[6];
    /* 0x27D */ u8 pad27D[0x28A - 0x27D];
    /* 0x28A */ u8 row;
} Unk800D9474Parent;

typedef struct Unk800D9474 {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ Unk800D9474Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x88 - 0x68];
    /* 0x88 */ u8 slot;
    /* 0x89 */ u8 unk89;
} Unk800D9474;

extern s32 lbl_80280CD0[][6];
extern s32 lbl_80280D60[][6];
extern Unk800D9474Pos lbl_804ED3A0;
extern Unk800D9474Pos lbl_804ED398;

void fn_800D9474(Unk800D9474* obj) {
    Unk800D9474Parent* parent = obj->parent;

    switch (obj->slot) {
    case 0:
        obj->unk89 = parent->slots[0];
        obj->x = lbl_80280CD0[parent->row][0];
        obj->y = lbl_80280D60[parent->row][0] + (obj->unk89 << 12);
        break;
    case 1:
        obj->unk89 = parent->slots[1];
        obj->x = lbl_80280CD0[parent->row][1];
        obj->y = lbl_80280D60[parent->row][1] + (obj->unk89 << 12);
        break;
    case 2:
        obj->unk89 = parent->slots[2];
        obj->x = lbl_80280CD0[parent->row][2];
        obj->y = lbl_80280D60[parent->row][2] + (obj->unk89 << 12);
        break;
    case 3:
        obj->unk89 = parent->slots[3];
        obj->x = lbl_80280CD0[parent->row][3];
        obj->y = lbl_80280D60[parent->row][3] + (obj->unk89 << 12);
        break;
    case 4:
        obj->unk89 = parent->slots[4];
        obj->x = lbl_80280CD0[parent->row][4];
        obj->y = lbl_80280D60[parent->row][4] + (obj->unk89 << 12);
        break;
    case 5:
        obj->unk89 = parent->slots[5];
        obj->x = lbl_80280CD0[parent->row][5];
        obj->y = lbl_80280D60[parent->row][5] + (obj->unk89 << 12);
        break;
    case 6:
        obj->x = lbl_804ED3A0.x;
        obj->y = lbl_804ED3A0.y;
        break;
    case 7:
        obj->x = lbl_804ED398.x;
        obj->y = lbl_804ED398.y;
        break;
    }
}
