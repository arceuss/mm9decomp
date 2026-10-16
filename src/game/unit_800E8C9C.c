#include "game/pool.h"

void fn_800E8C9C(PoolNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = lbl_804EE968->free;
    lbl_804EE968->free = node;
    lbl_804EE968->freeCount++;
}
