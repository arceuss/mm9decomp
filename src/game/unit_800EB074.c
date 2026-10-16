#include "types.h"

typedef struct Unk800EB074Obj {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
} Unk800EB074Obj;

typedef struct Unk8043CD28Node {
    /* 0x0 */ struct Unk8043CD28Node* next;
    /* 0x4 */ Unk800EB074Obj* obj;
    /* 0x8 */ s16 id;
    /* 0xA */ u8 flags;
} Unk8043CD28Node;

typedef struct Unk8043CD28 {
    /* 0x000 */ u8 pad0[0x24C];
    /* 0x24C */ Unk8043CD28Node* active;
    /* 0x250 */ Unk8043CD28Node* free;
    /* 0x254 */ u8 pad254[0x2DC - 0x254];
    /* 0x2DC */ u16 unk2DC;
    /* 0x2DE */ u8 pad2DE[0x2E8 - 0x2DE];
} Unk8043CD28;

extern Unk8043CD28 lbl_8043CD28;

void fn_800EABC0(Unk800EB074Obj* obj);

void fn_800EB074(void) {
    Unk8043CD28Node* node;
    Unk8043CD28Node* next;
    Unk8043CD28Node* prev;
    Unk8043CD28Node* cur;

    node = lbl_8043CD28.active;
    while (node != NULL) {
        next = node->next;
        if (node->obj != NULL) {
            if (node->obj->unk10 < 3) {
                fn_800EABC0(node->obj);
            }
            if (node->flags & 4) {
                node->flags |= 1;
            }
            node->flags |= 0x20;
            node->obj = NULL;
        }
        cur = lbl_8043CD28.active;
        prev = cur;
        while (cur != node) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == prev) {
            lbl_8043CD28.active = node->next;
        } else {
            prev->next = node->next;
        }
        node->next = lbl_8043CD28.free;
        lbl_8043CD28.free = node;
        lbl_8043CD28.unk2DC++;
        node = next;
    }
}
