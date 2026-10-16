#include "types.h"

typedef struct Unk80072A20Node {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ struct Unk80072A20Node* next;
    /* 0x08 */ u8 pad8[0x18 - 0x8];
    /* 0x18 */ void (*func)(struct Unk80072A20Node*);
    /* 0x1C */ u8 pad1C[0x32 - 0x1C];
    /* 0x32 */ s16 unk32;
} Unk80072A20Node;

typedef struct Unk80072A20List {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk80072A20Node* cur;
    /* 0x10 */ u8 pad10[0x4];
    /* 0x14 */ Unk80072A20Node head;
} Unk80072A20List;

extern Unk80072A20List* lbl_804EE810;

void fn_800E8BD0(Unk80072A20List* list);

void fn_80072A20(s16 value) {
    Unk80072A20List* list = lbl_804EE810;
    Unk80072A20Node* node;

    fn_800E8BD0(list);
    while ((node = list->cur = list->cur->next) != &list->head) {
        node->unk32 = value;
        node->func(node);
    }
}
