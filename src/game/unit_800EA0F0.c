#include "types.h"

typedef struct Unk8043CD28Node {
    /* 0x0 */ struct Unk8043CD28Node* next;
    /* 0x4 */ void* obj;
    /* 0x8 */ s16 id;
} Unk8043CD28Node;

typedef struct Unk8043CD28Spawn {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ u16 unk4;
    /* 0x6 */ u16 type;
} Unk8043CD28Spawn;

typedef struct Unk8043CD28Type {
    /* 0x0 */ u8 flags;
    /* 0x1 */ u8 pad1[0xC - 0x1];
} Unk8043CD28Type;

typedef struct Unk8043CD28 {
    /* 0x000 */ Unk8043CD28Type* types;
    /* 0x004 */ Unk8043CD28Spawn* spawns;
    /* 0x008 */ u8 pad8[0x24C - 0x8];
    /* 0x24C */ Unk8043CD28Node* active;
    /* 0x250 */ Unk8043CD28Node* free;
    /* 0x254 */ u32 bits[0x20];
    /* 0x2D4 */ s32 unk2D4;
    /* 0x2D8 */ s32 unk2D8;
    /* 0x2DC */ u16 unk2DC;
    /* 0x2DE */ u16 unk2DE;
    /* 0x2E0 */ u8 unk2E0;
    /* 0x2E1 */ u8 unk2E1;
    /* 0x2E2 */ u8 unk2E2;
    /* 0x2E3 */ u8 unk2E3;
    /* 0x2E4 */ u8 unk2E4;
    /* 0x2E5 */ u8 unk2E5;
    /* 0x2E6 */ u8 pad2E6[0x2];
} Unk8043CD28;

extern Unk8043CD28 lbl_8043CD28;

void fn_800EA0F0(u8 arg0) {
    Unk8043CD28Node* node;
    u16 i;
    Unk8043CD28Spawn* spawns;
    Unk8043CD28Type* types;

    for (node = lbl_8043CD28.active; node != NULL; node = node->next) {
        if (node->obj != NULL) {
            lbl_8043CD28.bits[node->id >> 5] |= 1 << (node->id & 31);
        }
    }
    lbl_8043CD28.unk2DE = 1;
    lbl_8043CD28.unk2E1 = arg0;
    lbl_8043CD28.unk2E3 = 0;
    lbl_8043CD28.unk2E4 = 1;
    lbl_8043CD28.unk2E2 = 0xFF;
    lbl_8043CD28.unk2D4 = 0x80000000;
    lbl_8043CD28.unk2D8 = 0x7FFFFFFF;
    types = lbl_8043CD28.types;
    spawns = lbl_8043CD28.spawns;
    for (i = 1; spawns[i].unk0 != 0x7FFFFFFF; i++) {
        if (!(lbl_8043CD28.bits[i >> 5] & (1 << (i & 31))) && !(types[spawns[i].type].flags & 2)) {
            lbl_8043CD28.bits[i >> 5] |= 1 << (i & 31);
        }
    }
}
