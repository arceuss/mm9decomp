#include "types.h"

typedef struct Unk800CA614Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800CA614Pos;

typedef struct Unk800CA614Player {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 pad9[0x60 - 0x9];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
} Unk800CA614Player;

typedef struct Unk800CA614Obj {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 dir;
    /* 0x14 */ u8 sides;
    /* 0x15 */ u8 pad15[0x34 - 0x15];
    /* 0x34 */ Unk800CA614Player* player;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
} Unk800CA614Obj;

typedef struct Unk800CA614Hit {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk800CA614Hit* other;
    /* 0x10 */ u8 pad10[0x28 - 0x10];
    /* 0x28 */ void* owner;
} Unk800CA614Hit;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x38 - 0x4];
} Unk803051D8;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x126];
    /* 0x126 */ u8 unk126;
    /* 0x127 */ u8 pad127[0x260 - 0x127];
    /* 0x260 */ s32 unk260;
    /* 0x264 */ u8 pad264[0x300 - 0x264];
} Unk80304B90;

extern Unk803051D8 lbl_803051D8;
extern Unk80304B90 lbl_80304B90;

s32 fn_800B6228(Unk800CA614Player* player, Unk800CA614Pos* delta, s32 dir);
BOOL fn_800B5CB4(Unk800CA614Player* player, s32 dir);

void fn_800CA614(Unk800CA614Hit* hit) {
    Unk800CA614Obj* obj = hit->owner;
    Unk800CA614Player* player = hit->other->owner;
    Unk800CA614Pos d;
    u8 dir;
    u8 sides;

    if (player->unk8 != 0) {
        return;
    }
    sides = obj->sides;
    if ((sides & 1) && obj->x > player->x) {
        if (lbl_803051D8.unk3 & 8) {
            return;
        }
        if ((sides & 0x10) && (u32)(obj->y - player->y) > 0x2C00) {
            return;
        }
        d.x = obj->x + 0x2000;
        d.x -= player->x;
        d.y = 0;
        if (fn_800B6228(player, &d, 1) < 0) {
            return;
        }
        if (!fn_800B5CB4(player, 1)) {
            return;
        }
        dir = 1;
    } else if ((sides & 2) && obj->x < player->x) {
        if (lbl_803051D8.unk3 & 8) {
            return;
        }
        if ((sides & 0x10) && (u32)(obj->y - player->y) > 0x2C00) {
            return;
        }
        d.x = obj->x - 0x2000;
        d.x -= player->x;
        d.y = 0;
        if (fn_800B6228(player, &d, -1) > 0) {
            return;
        }
        if (!fn_800B5CB4(player, 0)) {
            return;
        }
        dir = 2;
    } else if ((sides & 4) && lbl_80304B90.unk260 - 1 < player->y) {
        if (!fn_800B5CB4(player, 3)) {
            return;
        }
        dir = 4;
    } else if ((sides & 8) && lbl_80304B90.unk260 > player->y - 0x1400) {
        if (!fn_800B5CB4(player, 2)) {
            return;
        }
        dir = 8;
    } else {
        return;
    }
    obj->dir = dir;
    if (dir & 3) {
        obj->state = 1;
        obj->step = 0;
    } else {
        obj->state = 2;
        obj->step = 0;
    }
    lbl_80304B90.unk126 |= 1;
    obj->player = player;
}
