#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80082278Cmd {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 slot;
    /* 0x2 */ s16 op;
    /* 0x4 */ s32 arg;
} Unk80082278Cmd;

typedef struct Unk80082278Obj {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 pad9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x54 - 0xB];
    /* 0x54 */ struct {
        u32 hi : 20;
        u32 b11 : 1;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ Vec2i pos;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ s32 unkA4;
    /* 0xA8 */ u8 unkA8;
} Unk80082278Obj;

typedef struct Unk80082278Slot {
    /* 0x0 */ Unk80082278Obj* obj;
    /* 0x4 */ u8 pad4[0x10 - 0x4];
} Unk80082278Slot;

typedef struct Unk80082278 {
    /* 0x000 */ u8 pad0[0x28];
    /* 0x028 */ Unk80082278Cmd* pc;
    /* 0x02C */ Unk80082278Slot slots[(0xEC - 0x2C) / 0x10];
    /* 0x0EC */ u8 padEC[0xF5 - 0xEC];
    /* 0x0F5 */ u8 unkF5;
    /* 0x0F6 */ u8 padF6[0x1A8 - 0xF6];
    /* 0x1A8 */ Vec2i focusPos;
} Unk80082278;

void fn_800B6500(Unk80082278Obj* obj, s32 arg1);

static inline void RemoveSlot(Unk80082278* obj, u8 idx) {
    Unk80082278Slot* sl = &obj->slots[idx];

    if (idx != 0 && sl->obj != NULL) {
        if (idx == 1) {
            obj->unkF5 &= 0x7D;
        }
        sl->obj = NULL;
    }
}

BOOL fn_80082278(Unk80082278* obj) {
    Unk80082278Cmd* cmd = obj->pc;
    s32 idx = cmd->slot;
    Unk80082278Slot* s = &obj->slots[idx];
    Unk80082278Obj* t = s->obj;
    Unk80082278Obj* other;

    if (t == NULL) {
        return FALSE;
    }
    switch (cmd->op) {
    case 0:
        t->pos.x = ((Vec2i*)cmd->arg)->x;
        t->pos.y = ((Vec2i*)cmd->arg)->y;
        if (t->unk8 == 0) {
            obj->focusPos = obj->slots[0].obj->pos;
        }
        break;
    case 1:
        other = obj->slots[cmd->arg].obj;
        if (other == NULL) {
            return FALSE;
        }
        t->pos.x = other->pos.x;
        t->pos.y = other->pos.y;
        break;
    case 2:
        if (t->unk8 == 0) {
            fn_800B6500(t, cmd->arg);
        } else {
            if (cmd->arg != 0) {
                t->flagsA |= 0x10;
            } else {
                t->flagsA &= 0xEF;
            }
            if (t->flagsA & 8) {
                t->bits54.flip = cmd->arg;
            }
        }
        break;
    case 3:
        if (cmd->arg != 0) {
            t->flagsA |= 0x20;
        } else {
            t->flagsA &= 0xDF;
        }
        if (t->flagsA & 8) {
            t->bits54.b11 = cmd->arg;
        }
        break;
    case 4:
        t->flagsA &= ~1;
        break;
    case 5:
        t->flagsA |= 1;
        break;
    case 6:
        RemoveSlot(obj, idx);
        break;
    case 7:
        s->obj = NULL;
        break;
    case 8:
        t->pos.x = ((Vec2i*)cmd->arg)->x;
        t->pos.y = ((Vec2i*)cmd->arg)->y;
        if (t->unk8 == 0) {
            obj->focusPos = obj->slots[0].obj->pos;
        }
        break;
    case 9:
        t->pos.x = cmd->arg;
        if (t->unk8 == 0) {
            obj->focusPos = obj->slots[0].obj->pos;
        }
        break;
    case 10:
        t->pos.y = cmd->arg;
        if (t->unk8 == 0) {
            obj->focusPos = obj->slots[0].obj->pos;
        }
        break;
    case 11:
        if (t->flagsA & 4) {
            t->unkA0 = 0;
            t->unkA4 = 0;
            t->unkA8 = 0;
        }
        break;
    }
    return FALSE;
}
