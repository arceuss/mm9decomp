#include "types.h"

typedef struct Unk80082514Cmd {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 slot;
    /* 0x2 */ s16 id;
    /* 0x4 */ u32 flags;
} Unk80082514Cmd;

typedef struct Unk80082514Slot {
    /* 0x0 */ void* obj;
    /* 0x4 */ u8 pad4[0x9 - 0x4];
    /* 0x9 */ u8 bits;
    /* 0xA */ u8 padA[0x10 - 0xA];
} Unk80082514Slot;

typedef struct Unk80082514 {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Unk80082514Cmd* pc;
    /* 0x2C */ Unk80082514Slot slots[1];
} Unk80082514;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 bits[8];
    /* 0x08 */ u8 vals[0x30];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;

BOOL fn_80082514(Unk80082514* obj) {
    Unk80082514Cmd* cmd = obj->pc;
    u32 f = cmd->flags;
    Unk80082514Slot* slot;

    if (f & 8) {
        if (f & 1) {
            if (lbl_803051D8.bits[cmd->id >> 3] & (1 << (cmd->id & 7))) {
                obj->pc = cmd - 1;
                return TRUE;
            }
        } else if (!(lbl_803051D8.bits[cmd->id >> 3] & (1 << (cmd->id & 7)))) {
            obj->pc = cmd - 1;
            return TRUE;
        }
        return FALSE;
    }
    if (f & 0x10) {
        slot = &obj->slots[cmd->slot];
        if (slot->obj == NULL) {
            return FALSE;
        }
        if (f & 1) {
            if (cmd->id | slot->bits) {
                obj->pc = cmd - 1;
                return TRUE;
            }
        } else if (!(cmd->id | slot->bits)) {
            obj->pc = cmd - 1;
            return TRUE;
        }
        return FALSE;
    }
    if (f & 4) {
        lbl_803051D8.vals[cmd->id] = cmd->slot;
        return FALSE;
    }
    if (f & 2) {
        if (f & 1) {
            lbl_803051D8.bits[cmd->id >> 3] |= 1 << (cmd->id & 7);
        } else {
            lbl_803051D8.bits[cmd->id >> 3] &= ~(1 << (cmd->id & 7));
        }
        return FALSE;
    }
    slot = &obj->slots[cmd->slot];
    if (slot->obj == NULL) {
        return FALSE;
    }
    if (f) {
        slot->bits |= cmd->id;
    } else {
        slot->bits &= cmd->id ^ 0xFF;
    }
    return FALSE;
}
