#include "types.h"

typedef struct Unk80265138Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk80265138Entry;

typedef struct Unk800413D4 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 padA[0x10 - 0xA];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x18 - 0x16];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x32 - 0x1C];
    /* 0x32 */ u16 scale;
    /* 0x34 */ u8 pad34[0x60 - 0x34];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 ay;
    /* 0x78 */ u8 pad78[0x7F - 0x78];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0x88 - 0x80];
    /* 0x88 */ s32 startX;
    /* 0x8C */ s32 groundY;
    /* 0x90 */ s32 startY;
} Unk800413D4;

extern Unk80265138Entry* lbl_80265138[];

void fn_800E9474(Unk800413D4* obj, s32 anim);
void fn_800E9750(Unk800413D4* obj, u16 arg1);
void fn_800D5234(s32 se);

static inline void SetMode2(Unk800413D4* obj) {
    obj->unk18 = lbl_80265138[obj->kind]->unk8;
    obj->unk10 = 2;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800413D4(Unk800413D4* obj) {
    switch (obj->step) {
    case 0:
        fn_800E9474(obj, 8);
        fn_800D5234(0x12);
        obj->x = obj->startX;
        obj->y = obj->groundY;
        obj->step++;
    case 1:
        fn_800E9750(obj, obj->scale);
        if (obj->unk7F == 3) {
            if (obj->unk15 == 2) {
                SetMode2(obj);
            } else {
                obj->step++;
            }
        }
        break;
    case 2:
        fn_800E9474(obj, 6);
        obj->vy = -0x200;
        obj->ay = -0x80;
        obj->step++;
    case 3:
        obj->y += (obj->vy * obj->scale) / 256 + ((obj->scale * ((obj->ay * obj->scale) / 256)) / 256) / 2;
        if (obj->y < obj->startY) {
            SetMode2(obj);
        }
        obj->vy += (obj->ay * obj->scale) / 256;
        if (obj->vy < -0x600) {
            obj->vy = -0x600;
        }
        fn_800E9750(obj, obj->scale);
        break;
    }
}
