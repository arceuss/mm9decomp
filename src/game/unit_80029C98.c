#include "types.h"

typedef struct Unk80029C98Msg {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s32 type;
    /* 0x0C */ u8 data[0x20];
} Unk80029C98Msg;

typedef struct Unk80029C98 {
    /* 0x000 */ u8 pad0[0x318];
    /* 0x318 */ u8 mutex[0x348 - 0x318];
    /* 0x348 */ u8 cond[0x350 - 0x348];
    /* 0x350 */ u8 slots[2][0x18];
    /* 0x380 */ u16 head;
    /* 0x382 */ u16 flags;
} Unk80029C98;

void fn_800F615C(void* mutex);
void fn_800F6238(void* mutex);
void fn_800F6508(void* cond);
Unk80029C98Msg* fn_80029A70(void* slot);
void* memcpy(void* dst, const void* src, u32 n);

void fn_80029C98(Unk80029C98* q, s32 type, void* data, u32 size) {
    u8 index;
    Unk80029C98Msg* msg;

    if (q->flags & 1) {
        return;
    }
    fn_800F615C(q->mutex);
    index = q->head + 1;
    if (index >= 2) {
        index = 0;
    }
    msg = fn_80029A70(q->slots[index]);
    msg->type = type;
    if (data != NULL && size != 0 && size < 0x20) {
        memcpy(msg->data, data, size);
    }
    fn_800F6238(q->mutex);
    fn_800F6508(q->cond);
}
