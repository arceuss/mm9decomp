#include "types.h"

typedef struct Unk800BFD48 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ void* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 vy;
    /* 0x70 */ s32 offX;
    /* 0x74 */ s32 offY;
} Unk800BFD48;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x25C];
    /* 0x25C */ s32 camX;
    /* 0x260 */ s32 camY;
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern void** lbl_8027F228[];
extern u8 lbl_804ECF74[4];
extern void (*lbl_804ECF68[2])(Unk800BFD48* obj);

void fn_800E9244(Unk800BFD48* obj);
void fn_800B6448(void* player, s32 arg1);

static inline void SetMode(Unk800BFD48* obj, u8 mode) {
    obj->unk18 = lbl_8027F228[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800BFD48(Unk800BFD48* obj) {
    void* parent = obj->parent;

    switch (obj->step) {
    case 0:
        obj->offX = 0x8000;
        obj->offY = 0x10000;
        obj->vy = 0;
        obj->step++;
    case 1:
        if ((obj->offY += obj->vy) < -0x4000) {
            SetMode(obj, 2);
            SetMode(obj, 4);
            fn_800E9244(obj);
            obj->flagsA &= ~1;
            lbl_804ECF68[lbl_804ECF74[obj->unk14]](obj);
            return;
        }
        obj->vy -= 0x60;
        if (obj->vy < -0x580) {
            obj->vy = -0x580;
        }
        break;
    }
    fn_800B6448(parent, 0x41);
    obj->x = lbl_80304B90.camX - 0x8000 + obj->offX;
    obj->y = lbl_80304B90.camY - 0x7000 + obj->offY;
}
