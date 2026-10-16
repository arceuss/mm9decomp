#include "types.h"

typedef struct Unk80305210Node {
    /* 0x0 */ struct Unk80305210Node* next;
    /* 0x4 */ struct Unk80305210Node* prev;
} Unk80305210Node;

typedef struct Unk80305210 {
    /* 0x000 */ u8 pad0[0x1C];
    /* 0x01C */ Unk80305210Node head;
    /* 0x024 */ u8 pad24[0x438 - 0x24];
} Unk80305210;

extern Unk80305210 lbl_80305210;

void fn_80083608(void) {
    lbl_80305210.head.next = &lbl_80305210.head;
    lbl_80305210.head.prev = &lbl_80305210.head;
}
