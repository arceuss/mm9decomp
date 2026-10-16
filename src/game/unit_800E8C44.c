#include "game/pool.h"

PoolNode* fn_800E8C44(Pool* pool) {
    PoolNode* node = pool->free;

    if (node != NULL) {
        pool->free = node->next;
        pool->freeCount--;
        node->prev = &pool->head;
        node->next = pool->head.next;
        pool->head.next->prev = node;
        pool->head.next = node;
        node->unkA = 0;
        node->unkC = 0;
        node->unk10 = 0;
        node->unk14 = 0;
    }
    return node;
}
