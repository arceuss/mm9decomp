#include "types.h"

typedef struct Unk800836D8Node {
    /* 0x0 */ struct Unk800836D8Node* unk0;
    /* 0x4 */ struct Unk800836D8Node* unk4;
} Unk800836D8Node;

typedef struct Unk80305210 {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ Unk800836D8Node head;
} Unk80305210;

extern Unk80305210 lbl_80305210;

BOOL fn_800836D8(Unk800836D8Node* node) {
    Unk800836D8Node* it;
    BOOL found = FALSE;

    for (it = lbl_80305210.head.unk4; it != &lbl_80305210.head; it = it->unk4) {
        if (it == node) {
            found = TRUE;
            break;
        }
    }
    return found;
}
