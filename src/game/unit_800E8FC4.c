#include "types.h"

typedef struct Unk800E8FC4Node {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u32 unk8;
    /* 0xC */ u32 unkC;
    /* 0x10 */ u32 unk10;
} Unk800E8FC4Node;

typedef struct Unk800E8FC4Obj {
    /* 0x00 */ struct Unk800E8FC4Obj* prev;
    /* 0x04 */ struct Unk800E8FC4Obj* next;
    /* 0x08 */ u8 pad8[0xA - 0x8];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x2E - 0xC];
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 pad2F[0x40 - 0x2F];
    /* 0x40 */ Unk800E8FC4Node node;
} Unk800E8FC4Obj;

typedef struct Unk800E8FC4List {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk800E8FC4Obj* iter;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ Unk800E8FC4Obj head;
} Unk800E8FC4List;

extern u8 lbl_804EE971;

void fn_800E8BD0(Unk800E8FC4List* list);
void fn_800E9834(Unk800E8FC4Obj* obj);
void fn_800E69C4(void* ctx, Unk800E8FC4Node* node, s32 layer, s16 prio);

static inline BOOL Next(Unk800E8FC4List* list, Unk800E8FC4Obj** obj) {
    BOOL more;

    if (lbl_804EE971) {
        *obj = list->iter = list->iter->prev;
        more = *obj != &list->head;
    } else {
        *obj = list->iter = list->iter->next;
        more = *obj != &list->head;
    }
    return more;
}

void fn_800E8FC4(Unk800E8FC4List* list, void* ctx) {
    Unk800E8FC4Obj* obj;
    Unk800E8FC4Node* node;

    fn_800E8BD0(list);
    while (Next(list, &obj)) {
        if (!(obj->flagsA & 1)) {
            continue;
        }
        node = &obj->node;
        if (obj->flagsA & 8) {
            if (obj->flagsB & 8) {
                fn_800E9834(obj);
            }
            fn_800E69C4(ctx, node, node->unk10 & 3, 0x1F - obj->unk2E);
        } else {
            fn_800E69C4(ctx, node, 2, obj->unk2E);
        }
    }
}
