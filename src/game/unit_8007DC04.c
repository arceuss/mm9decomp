#include "types.h"

typedef struct Unk8007DC04Spawn {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s32 x;
    /* 0x0C */ s32 y;
    /* 0x10 */ s32 facing;
} Unk8007DC04Spawn;

typedef struct Unk8007DC04Stage {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ Unk8007DC04Spawn* spawns;
} Unk8007DC04Stage;

typedef struct Unk8007DC04Player {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 flagsA;
    /* 0x00B */ u8 padB[0x60 - 0xB];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 pad68[0x164 - 0x68];
    /* 0x164 */ u32 unk164;
} Unk8007DC04Player;

typedef struct Unk80304B90 {
    /* 0x000 */ Unk8007DC04Stage* stage;
    /* 0x004 */ void* unk4;
    /* 0x008 */ Unk8007DC04Player* player;
    /* 0x00C */ u8 spawnIndex;
    /* 0x00D */ u8 padD[0x124 - 0xD];
    /* 0x124 */ u8 unk124[0x2DC - 0x124];
    /* 0x2DC */ u32 unk2DC;
    /* 0x2E0 */ u8 pad2E0[0x300 - 0x2E0];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_800814EC(void* anim, void* arg1, s32 arg2);

void fn_8007DC04(s32 arg0) {
    fn_800814EC(lbl_80304B90.unk124, lbl_80304B90.unk4, arg0);
}
