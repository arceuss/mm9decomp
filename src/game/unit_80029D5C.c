#include "types.h"

typedef struct Unk80029D5CNode {
    /* 0x0 */ struct Unk80029D5CNode* next;
    /* 0x4 */ u8 pad4[0x8 - 0x4];
    /* 0x8 */ void (*func)(void* arg);
    /* 0xC */ u8 unkC[1];
} Unk80029D5CNode;

typedef struct Unk80029D5CQueue {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ Unk80029D5CNode* head;
    /* 0x08 */ u8 pad8[0x18 - 0x8];
} Unk80029D5CQueue;

typedef struct Unk80029D5C {
    /* 0x000 */ u8 pad0[0x318];
    /* 0x318 */ u8 mutex[0x348 - 0x318];
    /* 0x348 */ u8 cond[0x350 - 0x348];
    /* 0x350 */ Unk80029D5CQueue queues[2];
    /* 0x380 */ u16 cur;
    /* 0x382 */ u16 flags;
} Unk80029D5C;

void fn_80029AB8(Unk80029D5CQueue* queue, Unk80029D5CNode* node);
void fn_800F615C(void* mutex);
void fn_800F6238(void* mutex);
void fn_800F642C(void* cond, void* mutex);

s32 fn_80029D5C(Unk80029D5C* p) {
    Unk80029D5CQueue* queue;
    Unk80029D5CNode* node;
    u8 next;

    queue = &p->queues[p->cur];
    p->flags |= 2;
    for (;;) {
        for (node = queue->head; node != NULL; node = node->next) {
            node->func(node->unkC);
            fn_80029AB8(queue, node);
        }
        next = p->cur + 1;
        if (next >= 2) {
            next = 0;
        }
        queue = &p->queues[next];
        fn_800F615C(p->mutex);
        if (queue->head == NULL) {
            p->flags &= ~2;
            if (p->flags & 1) {
                fn_800F6238(p->mutex);
                break;
            }
            fn_800F642C(p->cond, p->mutex);
            p->flags |= 2;
        }
        p->cur = next;
        fn_800F6238(p->mutex);
    }
    return 0;
}
