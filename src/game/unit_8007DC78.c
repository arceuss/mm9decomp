#include "types.h"

typedef struct Unk8007DC78Spawn {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s32 x;
    /* 0x0C */ s32 y;
    /* 0x10 */ s32 facing;
} Unk8007DC78Spawn;

typedef struct Unk8007DC78Stage {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ Unk8007DC78Spawn* spawns;
} Unk8007DC78Stage;

typedef struct Unk8007DC78Player {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 flagsA;
    /* 0x00B */ u8 padB[0x60 - 0xB];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 pad68[0x164 - 0x68];
    /* 0x164 */ u32 unk164;
} Unk8007DC78Player;

typedef struct Unk80304B90 {
    /* 0x000 */ Unk8007DC78Stage* stage;
    /* 0x004 */ void* unk4;
    /* 0x008 */ Unk8007DC78Player* player;
    /* 0x00C */ u8 spawnIndex;
    /* 0x00D */ u8 padD[0x124 - 0xD];
    /* 0x124 */ u8 unk124[0x2DC - 0x124];
    /* 0x2DC */ u32 unk2DC;
    /* 0x2E0 */ u8 pad2E0[0x300 - 0x2E0];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_8007DC78(void) {
    u32 in = lbl_80304B90.unk2DC;
    Unk8007DC78Player* player = lbl_80304B90.player;
    u32 out = player->unk164;

    if (in & 2) {
        out |= 2;
    }
    if (in & 4) {
        out |= 4;
    }
    if (in & 8) {
        out |= 8;
    }
    if (in & 0x10) {
        out |= 0x20;
    }
    if (in & 0x20) {
        out |= 0x10;
    }
    if (in & 0x40) {
        out |= 0x40;
    }
    if (in & 0x80) {
        out |= 0x80;
    }
    if (in & 0x100) {
        out |= 0x100;
    }
    player->unk164 = out;
}
