#ifndef GAME_POOL_H
#define GAME_POOL_H

#include "types.h"

// Fixed-size object pool: a singly linked free list plus a circular doubly
// linked list of live nodes with a sentinel (fn_800E8C44 inserts at the front,
// fn_800E8BEC at the back, fn_800E8C9C returns a node to lbl_804EE968's pool).
typedef struct PoolNode {
    /* 0x00 */ struct PoolNode* next;
    /* 0x04 */ struct PoolNode* prev;
    /* 0x08 */ u8 pad8[0xA - 0x8];
    /* 0x0A */ s16 unkA; // zeroed on allocation
    /* 0x0C */ s32 unkC; // zeroed on allocation
    /* 0x10 */ s32 unk10; // zeroed on allocation
    /* 0x14 */ s32 unk14; // zeroed on allocation
} PoolNode;

typedef struct Pool {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ s16 freeCount;
    /* 0x0C */ PoolNode* cur; // iterator, reset to &head by fn_800E8BE0
    /* 0x10 */ PoolNode* free;
    /* 0x14 */ PoolNode head;
} Pool;

extern Pool* lbl_804EE968; // pool fn_800E8C9C frees into, set by fn_800E8BD0

#endif
