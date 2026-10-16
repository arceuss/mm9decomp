#include "types.h"

typedef struct Unk800BDC4CNode {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ struct Unk800BDC4CNode* next;
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 pad9[0x20 - 0x9];
    /* 0x20 */ u8 unk20;
} Unk800BDC4CNode;

typedef struct Unk800BDC4CList {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ Unk800BDC4CNode* cur;
    /* 0x10 */ u8 pad10[0x4];
    /* 0x14 */ Unk800BDC4CNode head;
} Unk800BDC4CList;

typedef struct Unk800BDC4CRef {
    /* 0x000 */ u8 pad0[0x1FC];
    /* 0x1FC */ u8 unk1FC[3];
    /* 0x1FF */ u8 pad1FF;
    /* 0x200 */ u8 unk200[3];
} Unk800BDC4CRef;

typedef struct Unk800BDC4C {
    /* 0x00 */ u8 pad0[0x15];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x34 - 0x16];
    /* 0x34 */ Unk800BDC4CRef* unk34;
} Unk800BDC4C;

typedef struct Unk800BDC4CVec {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
} Unk800BDC4CVec;

extern void* lbl_804EE878;

void fn_800E8BE0(Unk800BDC4CList* list);
s32 fn_800BDD9C(Unk800BDC4CNode* node, Unk800BDC4CVec* v);
u32 fn_800EB16C(s32 a0, s32 a1);

Unk800BDC4CNode* fn_800BDC4C(Unk800BDC4C* p, Unk800BDC4CVec* a1, Unk800BDC4CVec* a2) {
    Unk800BDC4CList* list = lbl_804EE878;
    Unk800BDC4CNode* best = NULL;
    Unk800BDC4CNode* node;
    u32 bestd = -1;
    Unk800BDC4CVec v;
    s32 i;
    u32 d;

    if (list->unk8 != list->unkA) {
        fn_800E8BE0(list);
        while ((node = list->cur = list->cur->next) != &list->head) {
            if (fn_800BDD9C(node, &v) == 0) {
                continue;
            }
            for (i = 0; i < 3; i++) {
                if (i != p->unk15 && node->unk20 == p->unk34->unk1FC[i] && (s8)node->unk8 == p->unk34->unk200[i]) {
                    break;
                }
            }
            if (i == 3) {
                d = fn_800EB16C(v.unk0 - a1->unk0, v.unk4 - a1->unk4);
                if (d < bestd) {
                    bestd = d;
                    best = node;
                    a2->unk4 = v.unk4;
                    a2->unk0 = v.unk0;
                }
            }
        }
    }
    return best;
}
