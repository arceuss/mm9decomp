#include "game/pool.h"

PoolNode* fn_800E8BEC(Pool* pool) {
    PoolNode* node = pool->free;

    if (node != NULL) {
        pool->free = node->next;
        pool->freeCount--;
        node->next = &pool->head;
        node->prev = pool->head.prev;
        pool->head.prev->next = node;
        pool->head.prev = node;
        node->unkA = 0;
        node->unkC = 0;
        node->unk10 = 0;
        node->unk14 = 0;
    }
    return node;
}
