#include "types.h"

typedef struct Unk800C2F20Node {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ struct Unk800C2F20Node* next;
} Unk800C2F20Node;

typedef struct Unk800C2F20List {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk800C2F20Node* cur;
    /* 0x10 */ u8 pad10[0x4];
    /* 0x14 */ Unk800C2F20Node head;
} Unk800C2F20List;

extern Unk800C2F20List* lbl_804EE8F8;

void fn_800E8BE0(Unk800C2F20List* list);

void fn_800C2F20(void (*callback)(Unk800C2F20Node*)) {
    Unk800C2F20List* list = lbl_804EE8F8;
    Unk800C2F20Node* node;

    fn_800E8BE0(list);
    while ((node = list->cur = list->cur->next) != &list->head) {
        callback(node);
    }
}
