#include "types.h"

typedef struct Unk800E8D30Node {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ struct Unk800E8D30Node* next;
    /* 0x08 */ u8 pad8[0x18 - 0x8];
    /* 0x18 */ void (*func)(struct Unk800E8D30Node*);
    /* 0x1C */ u8 pad1C[0x32 - 0x1C];
    /* 0x32 */ s16 unk32;
} Unk800E8D30Node;

typedef struct Unk800E8D30List {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk800E8D30Node* cur;
    /* 0x10 */ u8 pad10[0x4];
    /* 0x14 */ Unk800E8D30Node head;
} Unk800E8D30List;

void fn_800E8BD0(Unk800E8D30List* list);

void fn_800E8D30(Unk800E8D30List* list, s16 value) {
    Unk800E8D30Node* node;

    fn_800E8BD0(list);
    while ((node = list->cur = list->cur->next) != &list->head) {
        node->unk32 = value;
        node->func(node);
    }
}
