#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk802819B0Entry;

typedef struct Unk800DCB7CPos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800DCB7CPos;

typedef struct Unk800DCB7CParent {
    /* 0x0000 */ u8 pad0[0xFF4];
    /* 0x0FF4 */ u8 cue;
    /* 0x0FF5 */ u8 done;
} Unk800DCB7CParent;

typedef struct Unk800DCB7CChild {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
} Unk800DCB7CChild;

typedef struct Unk800DCB7C {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 set;
    /* 0x15 */ u8 idx;
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800DCB7CParent* parent;
    /* 0x38 */ Unk800DCB7CChild* child;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ Unk800DCB7CPos pos;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0x7F - 0x6C];
    /* 0x7F */ u8 unk7F;
} Unk800DCB7C;

typedef struct Unk8037CC40Slot {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 pad9[0x10 - 0x9];
} Unk8037CC40Slot;

typedef struct Unk8037CC40 {
    /* 0x0000 */ u8 pad0[0x1618];
    /* 0x1618 */ Unk8037CC40Slot slots[(0x1FD8 - 0x1618) / 0x10];
    /* 0x1FD8 */ u8 slotA;
    /* 0x1FD9 */ u8 pad1FD9[0x1FDC - 0x1FD9];
    /* 0x1FDC */ u8 slotB;
} Unk8037CC40;

extern Unk802819B0Entry* lbl_802819B0[];
extern Unk800DCB7CPos lbl_802810E0[][18];
extern Unk8037CC40 lbl_8037CC40;
extern u8 lbl_8027EBA8[][0x10];

void fn_800E946C(Unk800DCB7C* obj, u8 anim);
void fn_800E9750(Unk800DCB7C* obj, u16 arg1);
void fn_800BAFDC(void* src, u32 dst, s32 size);
Unk800DCB7CChild* fn_80041028(s32 arg0, s32 arg1, Unk800DCB7CPos* pos, s32 arg3);

static inline Unk8037CC40Slot* Slot(u8 idx) {
    Unk8037CC40Slot* p = NULL;

    if (idx != 0xFF) {
        p = &lbl_8037CC40.slots[idx];
    }
    return p;
}

void fn_800DCB7C(Unk800DCB7C* obj) {
    Unk800DCB7CParent* parent = obj->parent;
    u8* src;
    u8 f;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 4);
        obj->pos.x = lbl_802810E0[obj->set][obj->idx].x;
        obj->pos.y = lbl_802810E0[obj->set][obj->idx].y;
        obj->vx = -0x160;
        obj->step++;
    case 1:
        obj->pos.x += obj->vx;
        if (obj->pos.x <= 0xC000) {
            parent->done = 1;
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 2:
        fn_800E946C(obj, 3);
        obj->step++;
    case 3:
        if (parent->cue == 6) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 4:
        f = obj->flagsA;
        obj->step++;
        obj->flagsA = f & ~1;
    case 5:
        if (parent->cue == 7) {
            obj->step++;
        }
        break;
    case 6:
        f = obj->flagsA;
        obj->step++;
        obj->flagsA = f | 1;
    case 7:
        if (parent->cue == 8) {
            obj->step++;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 8:
        fn_800E946C(obj, 5);
        obj->timer = 0x1E;
        obj->step++;
    case 9:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk7F == 3 && --obj->timer == 0) {
            obj->step++;
        }
        break;
    case 10:
        src = lbl_8027EBA8[0];
        fn_800BAFDC(src, (Slot(lbl_8037CC40.slotB) != NULL ? Slot(lbl_8037CC40.slotB)->unk8 : 0) * 32 + 0x200, 8);
        obj->child = fn_80041028(1, 0, &obj->pos, 0);
        obj->flagsA &= ~1;
        obj->step++;
    case 11:
        if (obj->child == NULL || obj->child->unk10 >= 2) {
            parent->done = 1;
            obj->unk18 = lbl_802819B0[obj->kind]->unk8;
            obj->unk10 = 2;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
        }
        break;
    }
}
