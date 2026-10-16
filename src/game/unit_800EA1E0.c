#include "types.h"

typedef struct Unk8043CD28Node {
    /* 0x0 */ struct Unk8043CD28Node* next;
    /* 0x4 */ void* obj;
    /* 0x8 */ s16 id;
    /* 0xA */ u8 flags;
} Unk8043CD28Node;

typedef struct Unk8043CD28 {
    /* 0x000 */ u8 pad0[0xC];
    /* 0x00C */ Unk8043CD28Node nodes[0x30];
    /* 0x24C */ Unk8043CD28Node* active;
    /* 0x250 */ Unk8043CD28Node* free;
    /* 0x254 */ u8 pad254[0x2DC - 0x254];
    /* 0x2DC */ u16 numFree;
    /* 0x2DE */ u8 pad2DE[0x2E8 - 0x2DE];
} Unk8043CD28;

extern Unk8043CD28 lbl_8043CD28;

void fn_800E9D78(void);

void fn_800EA1E0(void) {
    s32 i;

    lbl_8043CD28.free = NULL;
    for (i = 0; i < 0x30; i++) {
        lbl_8043CD28.nodes[i].next = lbl_8043CD28.free;
        lbl_8043CD28.free = &lbl_8043CD28.nodes[i];
    }
    lbl_8043CD28.active = NULL;
    lbl_8043CD28.numFree = 0x30;
    fn_800E9D78();
}
