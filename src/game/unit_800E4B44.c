#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} Unk802819B0Entry;

typedef struct Unk800E4B44Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800E4B44Pos;

typedef struct Unk800E4B44Parent {
    /* 0x0000 */ u8 pad0[0x1022];
    /* 0x1022 */ u8 cue;
    /* 0x1023 */ u8 pad1023[0x227C - 0x1023];
    /* 0x227C */ u8 unk227C;
} Unk800E4B44Parent;

typedef struct Unk800E4B44 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16;
    /* 0x17 */ u8 count;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x2A - 0x1C];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x32 - 0x30];
    /* 0x32 */ u16 scale;
    /* 0x34 */ Unk800E4B44Parent* parent;
    /* 0x38 */ struct Unk800E4B44* child;
    /* 0x3C */ u8 pad3C[0x54 - 0x3C];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ Unk800E4B44Pos pos;
    /* 0x68 */ u8 pad68[0x84 - 0x68];
    /* 0x84 */ s32 timer;
} Unk800E4B44;

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

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x38 - 0x4];
} Unk803051D8;

extern Unk802819B0Entry* lbl_802819B0[];
extern Unk8037CC40 lbl_8037CC40;
extern u8 lbl_8027EBA8[][0x10];
extern u8 lbl_8027ECD8[];
extern Unk803051D8 lbl_803051D8;
extern void* lbl_804EE948;

void fn_800E9A84(Unk800E4B44* obj, s32 arg1);
void fn_800E9424(Unk800E4B44* obj, u16 anim);
void fn_800E9474(Unk800E4B44* obj, s32 anim);
void fn_800BAFDC(void* src, u32 dst, s32 size);
Unk800E4B44* fn_80041028(s32 arg0, s32 arg1, Unk800E4B44Pos* pos, u32 flip);
void fn_800D5234(s32 se);
Unk800E4B44* fn_800E8C44(void* pool);
void fn_800E9750(Unk800E4B44* obj, u16 arg1);

static inline Unk8037CC40Slot* Slot(u8 idx) {
    Unk8037CC40Slot* p = NULL;

    if (idx != 0xFF) {
        p = &lbl_8037CC40.slots[idx];
    }
    return p;
}

void fn_800E4B44(Unk800E4B44* obj) {
    Unk800E4B44Parent* parent = obj->parent;
    Unk800E4B44* child;
    u8* src;
    u32 v;

    switch (obj->step) {
    case 0:
        obj->flagsA &= ~1;
        fn_800E9A84(obj, 0x144);
        if (parent->unk227C == 1) {
            fn_800E9424(obj, 0x180);
            obj->pos.x = 0xD800;
            obj->pos.y = 0x7400;
            v = 0x10;
        } else {
            if (lbl_803051D8.unk3 & 0x20) {
                fn_800E9424(obj, 0x141);
            } else {
                fn_800E9424(obj, 0x140);
            }
            obj->pos.x = 0xE000;
            obj->pos.y = 0x7800;
            v = 0;
        }
        fn_800E9474(obj, 0);
        obj->flipX = 0;
        if (obj->flipX) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        src = lbl_8027EBA8[v];
        fn_800BAFDC(src, (Slot(lbl_8037CC40.slotB) != NULL ? Slot(lbl_8037CC40.slotB)->unk8 : 0) * 32 + 0x200, 8);
        src = lbl_8027ECD8;
        fn_800BAFDC(src, (Slot(lbl_8037CC40.slotB) != NULL ? Slot(lbl_8037CC40.slotB)->unk8 : 0) * 32 + 0x208, 8);
        obj->child = fn_80041028(0, 0, &obj->pos, (obj->flagsA >> 4) & 1);
        obj->step++;
    case 1:
        if (obj->child == NULL || obj->child->unk10 >= 2) {
            obj->flagsA |= 1;
            obj->step++;
        }
        break;
    case 2:
        if (parent->cue == 1) {
            obj->step++;
        }
        break;
    case 3:
        fn_800E9474(obj, 0xA);
        obj->timer = 1;
        obj->count = 0;
        obj->step++;
    case 4:
        obj->timer -= obj->scale;
        if (obj->timer > 0) {
            break;
        }
        fn_800D5234(0x21);
        v = obj->count;
        obj->timer += 0xC00;
        child = fn_800E8C44(lbl_804EE948);
        if (child != NULL) {
            child->unk2E = 0x10;
            child->kind = 0xE;
            child->unk18 = lbl_802819B0[0xE]->unk0;
            child->unk2A = 0;
            child->unk2C = 0;
            child->unk2F = 0;
            child->parent = parent;
            child->unk14 = 2;
            child->unk15 = v;
        }
        if (++obj->count >= 0x10) {
            obj->step++;
        }
        break;
    case 5:
        obj->timer = 0x1000;
        obj->step++;
    case 6:
        obj->timer -= obj->scale;
        if (obj->timer <= 0) {
            obj->step++;
        }
        break;
    case 7:
        fn_800E9474(obj, 0);
        obj->step++;
    case 8:
        if (parent->cue == 2) {
            obj->step++;
        }
        break;
    case 9:
        obj->child = fn_80041028(1, 0, &obj->pos, (obj->flagsA >> 4) & 1);
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        obj->unk18 = lbl_802819B0[obj->kind]->unkC;
        obj->unk10 = 3;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
        return;
    }
    fn_800E9750(obj, obj->scale);
}
