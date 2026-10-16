#include "types.h"

typedef struct Unk80081A54Cmd {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 op;
    /* 0x2 */ s16 id;
    /* 0x4 */ struct Unk80081A54Cmd* target;
} Unk80081A54Cmd;

typedef struct Unk80081A54 {
    /* 0x00 */ u8 pad0[0x3];
    /* 0x03 */ u8 sp;
    /* 0x04 */ Unk80081A54Cmd* stack[(0x28 - 0x4) / 4];
    /* 0x28 */ Unk80081A54Cmd* pc;
} Unk80081A54;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 bits[8];
    /* 0x08 */ u8 vals[0x30];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;

static inline void Call(Unk80081A54* obj, Unk80081A54Cmd* cmd) {
    obj->stack[obj->sp] = cmd + 1;
    obj->sp++;
    obj->pc = obj->pc->target - 1;
}

BOOL fn_80081A54(Unk80081A54* obj) {
    Unk80081A54Cmd* cmd = obj->pc;

    switch (cmd->op) {
    case 0:
        obj->pc = cmd->target - 1;
        break;
    case 1:
        Call(obj, cmd);
        break;
    case 2:
        if (lbl_803051D8.bits[cmd->id >> 3] & (1 << (cmd->id & 7))) {
            Call(obj, cmd);
        }
        break;
    case 3:
        if (!(lbl_803051D8.bits[cmd->id >> 3] & (1 << (cmd->id & 7)))) {
            Call(obj, cmd);
        }
        break;
    case 4:
        if ((cmd->id >> 8) == lbl_803051D8.vals[(u8)cmd->id]) {
            Call(obj, cmd);
        }
        break;
    case 5:
        if ((cmd->id >> 8) != lbl_803051D8.vals[(u8)cmd->id]) {
            Call(obj, cmd);
        }
        break;
    }
    return FALSE;
}
