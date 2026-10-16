#include "types.h"

typedef struct Unk800836B0Node {
    /* 0x0 */ struct Unk800836B0Node* next;
    /* 0x4 */ struct Unk800836B0Node* prev;
} Unk800836B0Node;

typedef struct Unk80305210 {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ Unk800836B0Node head;
} Unk80305210;

extern Unk80305210 lbl_80305210;

void fn_800836B0(Unk800836B0Node* node) {
    node->next = lbl_80305210.head.next;
    node->prev = &lbl_80305210.head;
    lbl_80305210.head.next->prev = node;
    lbl_80305210.head.next = node;
}
