#include "types.h"

typedef struct Unk80081EA8Cmd {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 op;
    /* 0x2 */ u8 pad2[0x4 - 0x2];
    /* 0x4 */ s32 arg;
} Unk80081EA8Cmd;

typedef struct Unk80081EA8Cam {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ u8 flags1D;
    /* 0x1E */ u8 pad1E[0x26 - 0x1E];
    /* 0x26 */ s16 t;
    /* 0x28 */ u8 pad28[0x38 - 0x28];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u8 pad40[0x48 - 0x40];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ void* focus;
    /* 0x54 */ u8 pad54[0x5C - 0x54];
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ s32 unk78;
} Unk80081EA8Cam;

typedef struct Unk80081EA8Slot {
    /* 0x0 */ u8* obj;
    /* 0x4 */ u8 pad4[0x10 - 0x4];
} Unk80081EA8Slot;

typedef struct Unk80081EA8 {
    /* 0x000 */ u8 pad0[0x28];
    /* 0x028 */ Unk80081EA8Cmd* pc;
    /* 0x02C */ Unk80081EA8Slot slots[(0xF4 - 0x2C) / 0x10];
    /* 0x0EC */ u8 padEC[0xF4 - 0xEC];
    /* 0x0F4 */ u8 unkF4;
    /* 0x0F5 */ u8 padF5[0xF8 - 0xF5];
    /* 0x0F8 */ Unk80081EA8Cam cam;
    /* 0x174 */ u8 pad174[0x1A8 - 0x174];
    /* 0x1A8 */ u8 unk1A8[1];
} Unk80081EA8;

typedef struct Unk80301280Sub {
    /* 0x0 */ u32 flags;
} Unk80301280Sub;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ Unk80301280Sub* unk40;
} Unk80301280;

extern Unk80301280 lbl_80301280;

void fn_80080168(Unk80081EA8Cam* cam, s32 arg1);
void fn_8009E1B0(void);
void fn_800BB378(void);
void fn_800BB428(void);
void fn_8009E1F4(void);

BOOL fn_80081EA8(Unk80081EA8* obj) {
    Unk80081EA8Cam* cam = &obj->cam;
    Unk80081EA8Cmd* cmd = obj->pc;
    s32 idx;
    u8* target;

    switch (cmd->op) {
    case 0:
        fn_80080168(cam, cmd->arg);
        break;
    case 1:
        cam->flags1D = cmd->arg;
        cam->t = 0;
        break;
    case 2:
        if ((s32)cam->unk1C != 1) {
            idx = cmd->arg;
            target = obj->slots[idx].obj;
            if (target != NULL) {
                if (idx == 0) {
                    cam->focus = obj->unk1A8;
                } else {
                    cam->focus = target + 0x60;
                }
            }
        }
        break;
    case 3:
        cam->unk38 = cmd->arg;
        break;
    case 4:
        cam->unk3C = cmd->arg;
        break;
    case 5:
        cam->unk48 = cmd->arg;
        break;
    case 6:
        cam->unk4C = cmd->arg;
        break;
    case 7:
        cam->unk5C = cmd->arg;
        break;
    case 8:
        cam->unk60 = cmd->arg;
        break;
    case 9:
        cam->unk64 = cmd->arg;
        break;
    case 10:
        cam->unk68 = cmd->arg;
        break;
    case 11:
        cam->unk6C = cmd->arg;
        break;
    case 12:
        cam->unk70 = cmd->arg;
        break;
    case 13:
        cam->unk74 = cmd->arg;
        break;
    case 14:
        cam->unk78 = cmd->arg;
        break;
    case 15:
        cam->flags1D |= 8;
        cam->t = 0;
        break;
    case 16:
        obj->unkF4 = cam->unk1C;
        fn_80080168(cam, 0);
        fn_8009E1B0();
        fn_800BB378();
        lbl_80301280.unk40->flags &= ~0xE00;
        break;
    case 17:
        fn_80080168(cam, obj->unkF4);
        fn_800BB428();
        fn_8009E1F4();
        break;
    }
    return FALSE;
}
