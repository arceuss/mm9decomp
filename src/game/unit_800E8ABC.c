#include "types.h"

typedef struct Unk800E8ABCNode {
    /* 0x0 */ struct Unk800E8ABCNode* next;
    /* 0x4 */ u8 pad4[0x8 - 0x4];
    /* 0x8 */ s8 pool;
} Unk800E8ABCNode;

typedef struct Unk800E8ABC {
    /* 0x00 */ u8* buf;
    /* 0x04 */ s16 id;
    /* 0x06 */ s16 stride;
    /* 0x08 */ s16 count;
    /* 0x0A */ s16 numFree;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ Unk800E8ABCNode* free;
    /* 0x14 */ void* head;
    /* 0x18 */ void* tail;
} Unk800E8ABC;

void fn_800E8ABC(Unk800E8ABC* pool, s8 id, u8* buf, s16 stride, s16 count) {
    Unk800E8ABCNode* node;

    pool->id = id;
    pool->buf = buf;
    pool->stride = stride;
    pool->count = count;
    pool->tail = &pool->head;
    pool->head = &pool->head;
    pool->free = NULL;
    pool->numFree = count;
    for (; count > 0; count--) {
        node = (Unk800E8ABCNode*)buf;
        node->next = pool->free;
        pool->free = node;
        node->pool = id;
        buf += stride;
    }
}
