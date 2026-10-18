#include "types.h"

typedef struct Unk800E63D0Slot {
    /* 0x0000 */ u8 thread[0x318];
    /* 0x0318 */ u8 stack[0x4000];
    /* 0x4318 */ void* (*func)(void*);
    /* 0x431C */ u8 pad431C[0x4320 - 0x431C];
    /* 0x4320 */ u8 req;
    /* 0x4321 */ u8 state;
    /* 0x4322 */ u8 pad4322[0x4330 - 0x4322];
} Unk800E63D0Slot;

typedef struct Unk8038E7C0 {
    /* 0x0000 */ s32 run;
    /* 0x0004 */ u8 queue[0x10 - 0x4];
    /* 0x0010 */ Unk800E63D0Slot slots[3];
    /* 0xC9A0 */ u8 cond[0xC9A8 - 0xC9A0];
    /* 0xC9A8 */ u8 mutex[0x18];
} Unk8038E7C0;

extern Unk8038E7C0 lbl_8038E7C0;
extern u8 lbl_804ED3F8[3];

s32 fn_800F8130(void* t, void* (*func)(void*), void* param, void* stack, u32 size, s32 prio, u16 attr);
s32 fn_800F8798(void* t);
void OSWakeupThread(void* q);
void OSLockMutex(void* m);
void OSUnlockMutex(void* m);
void OSWaitCond(void* c, void* m);
void OSSignalCond(void* c);
void fn_8009DCB8(void);

static inline void Start(s32 i, void* (*func)(void*), u8 prio) {
    Unk800E63D0Slot* t = &lbl_8038E7C0.slots[i];

    t->func = func;
    t->req = 0;
    t->state = 4;
    fn_800F8130(t, func, t, &t->func, 0x4000, prio, 1);
}

void fn_800E63D0(void) {
    Unk800E63D0Slot* s;
    s32 i;
    s32 busy;

    do {
        for (i = 0; i < 3; i++) {
            s = &lbl_8038E7C0.slots[i];
            if (s->req) {
                Start(i, s->func, lbl_804ED3F8[i]);
            }
            if (s->state == 4) {
                s->state = 2;
                fn_800F8798(s);
            }
            if (s->state == 8) {
                s->state = 2;
            }
        }
        OSWakeupThread(lbl_8038E7C0.queue);
        OSLockMutex(lbl_8038E7C0.mutex);
        do {
            busy = 0;
            for (i = 0; i < 3; i++) {
                if (lbl_8038E7C0.slots[i].state == 2) {
                    busy = 1;
                }
            }
            if (busy) {
                OSWaitCond(lbl_8038E7C0.cond, lbl_8038E7C0.mutex);
            }
        } while (busy);
        fn_8009DCB8();
        OSUnlockMutex(lbl_8038E7C0.mutex);
        OSSignalCond(lbl_8038E7C0.cond);
    } while (lbl_8038E7C0.run != 0);
}
