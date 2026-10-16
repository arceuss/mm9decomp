#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80011CE4 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xD8 - 0x68];
    /* 0xD8 */ u32 unkD8;
    /* 0xDC */ s32 unkDC;
    /* 0xE0 */ s32 unkE0;
    /* 0xE4 */ s8 unkE4;
    /* 0xE5 */ u8 unkE5;
} Unk80011CE4;

extern Vec2i lbl_80262178[];
extern u8 lbl_803012C8[64];
extern Unk80011CE4* lbl_804EE984;

void fn_80011CE4(Unk80011CE4* obj) {
    BOOL found = FALSE;
    u8 i;
    u8 idx;
    u8 sel;
    Vec2i* pt;
    Unk80011CE4* player;
    s32 x;
    s32 y;
    s32 px;
    s32 py;
    s32 dx;
    s32 dy;
    s32 angle;

    idx = obj->unkE5;
    for (i = 0; i < 0x40 && !found; i++) {
        idx = (idx + 1) & 0x3F;
        sel = lbl_803012C8[idx];
        if (sel == obj->unkE4) {
            continue;
        }
        pt = &lbl_80262178[sel];
        player = lbl_804EE984;
        y = obj->unkE0 + pt->y;
        py = player->unk64;
        x = obj->unkDC + pt->x;
        px = player->unk60;
        if (py >= y - 0x1C00 && py <= y + 0x800) {
            continue;
        }
        dx = px - x;
        dy = py - y;
        if ((u32)(dx * dx / 256 + dy * dy / 256 + 0x4000) < 0x8000) {
            continue;
        }
        angle = (u8)(((obj->unkD8 >> 1) & 0xFF) + 0x30);
        if (angle < sel << 5 && angle + 0x40 > sel << 5) {
            continue;
        }
        obj->unkE4 = sel;
        found = TRUE;
        obj->unkE5 = idx;
        obj->unk60 = x;
        obj->unk64 = y - 0x300;
    }
}
