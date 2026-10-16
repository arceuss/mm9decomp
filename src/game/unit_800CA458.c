#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80280390Entry {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
} Unk80280390Entry;

typedef struct Unk800CA458 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 padA[0x10 - 0xA];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ void* unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ Vec2i pos;
} Unk800CA458;

extern Unk80280390Entry* lbl_80280390[];
extern void (*lbl_8027F764[])(Unk800CA458* obj);

void fn_800CA458(Unk800CA458* obj) {
    Vec2i pos;

    pos.x = (obj->pos.x / 0x10000) << 16;
    pos.y = (obj->pos.y / 0xE000) * 0xE000;
    obj->unk18 = lbl_80280390[obj->kind]->unk4;
    obj->unk10 = 1;
    obj->unk13 = 0;
    obj->state = 0;
    obj->step = 0;
    if (obj->unk14 & 3) {
        pos.x += 0x10000;
        if (obj->unk14 & 0x10) {
            pos.y = ((obj->pos.y / 0x1000) << 12) + 0x1000;
        } else {
            pos.y += 0x7000;
        }
    } else {
        pos.y += 0xE000;
        if (obj->unk14 & 0x10) {
            pos.x = ((obj->pos.x / 0x1000) << 12) + 0x1000;
        } else {
            pos.x += 0x8000;
        }
    }
    obj->pos = pos;
    obj->unk34 = NULL;
    lbl_8027F764[obj->state](obj);
}
