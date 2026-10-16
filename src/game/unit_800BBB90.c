#include "types.h"

typedef struct Unk800BBB90Node {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ struct Unk800BBB90Node* next;
} Unk800BBB90Node;

typedef struct Unk800BBB90List {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk800BBB90Node* cur;
    /* 0x10 */ u8 pad10[0x4];
    /* 0x14 */ Unk800BBB90Node head;
} Unk800BBB90List;

extern Unk800BBB90List* lbl_804EE8C0;

void fn_800E8BE0(Unk800BBB90List* list);

void fn_800BBB90(void (*callback)(Unk800BBB90Node*)) {
    Unk800BBB90List* list = lbl_804EE8C0;
    Unk800BBB90Node* node;

    fn_800E8BE0(list);
    while ((node = list->cur = list->cur->next) != &list->head) {
        callback(node);
    }
}
