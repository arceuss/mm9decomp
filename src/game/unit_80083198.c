#include "types.h"

typedef struct Unk80083198Cmd {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 op;
    /* 0x2 */ s16 arg;
    /* 0x4 */ u32 arg2;
} Unk80083198Cmd;

typedef struct Unk80083198 {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Unk80083198Cmd* pc;
} Unk80083198;

typedef struct Unk8037C3D8 {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 pad1[0x5 - 0x1];
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 pad6[0x8 - 0x6];
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 pad9[0x50 - 0x9];
} Unk8037C3D8;

extern Unk8037C3D8 lbl_8037C3D8;

void fn_800A69C8(void);
void fn_800A7084(u8 arg0, u16 arg1, u8 arg2, s32 arg3, s32 arg4);
void fn_800A6D90(void);

BOOL fn_80083198(Unk80083198* obj) {
    Unk80083198Cmd* cmd = obj->pc;

    switch (cmd->op) {
    case 0:
        fn_800A69C8();
        break;
    case 1:
        fn_800A7084(cmd->arg >> 8, cmd->arg2, cmd->arg, 0, 0);
        break;
    case 2:
        fn_800A7084(cmd->arg >> 8, cmd->arg2, cmd->arg, 1, 0);
        break;
    case 3:
        fn_800A6D90();
        if (lbl_8037C3D8.unk0 != 0 || lbl_8037C3D8.unk5 != 0) {
            obj->pc--;
            return TRUE;
        }
        break;
    case 4:
        lbl_8037C3D8.unk8 = 0;
        fn_800A6D90();
        break;
    case 5:
        fn_800A6D90();
        if (lbl_8037C3D8.unk5 != 1) {
            obj->pc--;
            return TRUE;
        }
        break;
    case 6:
        fn_800A6D90();
        if (lbl_8037C3D8.unk5 != 2) {
            obj->pc--;
            return TRUE;
        }
        break;
    case 7:
        fn_800A6D90();
        if (lbl_8037C3D8.unk5 != 3) {
            obj->pc--;
            return TRUE;
        }
        break;
    }
    return FALSE;
}
