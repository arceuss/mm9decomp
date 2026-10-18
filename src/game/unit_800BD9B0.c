#include "types.h"

typedef struct UnkBD9B0Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} UnkBD9B0Pos;

typedef struct UnkBD9B0Node {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ struct UnkBD9B0Node* next;
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 pad9[0x20 - 0x9];
    /* 0x20 */ u8 unk20;
} UnkBD9B0Node;

typedef struct UnkBD9B0List {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ UnkBD9B0Node* iter;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ UnkBD9B0Node head;
} UnkBD9B0List;

typedef struct UnkBD9B0Parent {
    /* 0x000 */ u8 pad0[0x1FC];
    /* 0x1FC */ u8 unk1FC[4];
    /* 0x200 */ u8 unk200[4];
} UnkBD9B0Parent;

typedef struct UnkBD9B0 {
    /* 0x00 */ u8 pad0[0x15];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x34 - 0x16];
    /* 0x34 */ UnkBD9B0Parent* parent;
} UnkBD9B0;

extern UnkBD9B0List* lbl_804EE738;
extern UnkBD9B0List* lbl_804EE664;

void fn_800E8BE0(UnkBD9B0List* l);
s32 fn_800BDD9C(UnkBD9B0Node* node, UnkBD9B0Pos* pos);
u32 fn_800EB16C(s32 dx, s32 dy);

UnkBD9B0Node* fn_800BD9B0(UnkBD9B0* obj, UnkBD9B0Pos* from, UnkBD9B0Pos* out) {
    UnkBD9B0Pos pos;
    UnkBD9B0Node* alt = NULL;
    UnkBD9B0Node* found = NULL;
    u32 best = 0xFFFFFFFF;
    UnkBD9B0Node* node;
    UnkBD9B0List* l;
    s32 i;
    u32 d;
    s32 k;
    s32 id;
    s32 tp;
    UnkBD9B0Parent* par;

    l = lbl_804EE738;
    if (l->unk8 != l->unkA) {
        fn_800E8BE0(l);
        while ((node = l->iter = l->iter->next) != &l->head) {
            if (fn_800BDD9C(node, &pos)) {
                k = obj->unk15;
                id = node->unk8;
                tp = node->unk20;
                par = obj->parent;
                for (i = 0; i < 3; i++) {
                    if (i != k && tp == par->unk1FC[i] && id == par->unk200[i]) {
                        break;
                    }
                }
                if (i >= 3) {
                    d = fn_800EB16C(pos.x - from->x, pos.y - from->y);
                    if (d < best) {
                        best = d;
                        found = node;
                        *out = pos;
                    }
                } else {
                    alt = node;
                }
            }
        }
    }
    l = lbl_804EE664;
    if (l->unk8 != l->unkA) {
        fn_800E8BE0(l);
        while ((node = l->iter = l->iter->next) != &l->head) {
            if (fn_800BDD9C(node, &pos)) {
                k = obj->unk15;
                id = node->unk8;
                tp = node->unk20;
                par = obj->parent;
                for (i = 0; i < 3; i++) {
                    if (i != k && tp == par->unk1FC[i] && id == par->unk200[i]) {
                        break;
                    }
                }
                if (i >= 3) {
                    d = fn_800EB16C(pos.x - from->x, pos.y - from->y);
                    if (d < best) {
                        best = d;
                        found = node;
                        *out = pos;
                    }
                } else {
                    alt = node;
                }
            }
        }
    }
    if (found == NULL && alt != NULL) {
        found = alt;
        *out = pos;
    }
    return found;
}
