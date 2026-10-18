#include "types.h"

typedef struct Unk80301320Slot {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ void* buf;
    /* 0xC */ u32 size;
} Unk80301320Slot;

typedef struct Unk80301320 {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 prevState;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ u32 flags;
    /* 0x08 */ Unk80301320Slot slots[2];
    /* 0x28 */ u8 slot;
    /* 0x29 */ u8 pad29[0x38 - 0x29];
    /* 0x38 */ void* unk38;
    /* 0x3C */ u8 unk3C[0x54 - 0x3C];
    /* 0x54 */ void* heap;
    /* 0x58 */ u8 pad58[0x5C - 0x58];
    /* 0x5C */ void* work;
} Unk80301320;

typedef struct Unk802639E0 {
    /* 0x0 */ void (*func)(void* arg);
    /* 0x4 */ u32 heapSize;
    /* 0x8 */ u32 workSize;
} Unk802639E0;

extern Unk80301320 lbl_80301320;
extern Unk802639E0 lbl_802639E0[3];

void fn_80029B30(Unk80301320Slot* slot);
void* fn_80029B4C(Unk80301320Slot* slot, u32 size, u32 align);
void* fn_80115EA8(void* start, u32 size, s32 arg2);
void OSInitMutex(void* arg0);
void fn_80029BCC(void* arg0, void* arg1, void* arg2);
void fn_80029B14(Unk80301320Slot* slot, void* buf, u32 size);

void fn_800250D8(u32 flags, void* arg) {
    s32 mode;
    void* a;
    s32 next;
    u8 cur;

    if (lbl_80301320.state != 1) {
        return;
    }
    lbl_80301320.flags = flags;
    if ((flags & 0xF) == 0) {
        return;
    }
    mode = (flags & 0xF) - 1;
    if (mode >= 3) {
        return;
    }
    fn_80029B30(&lbl_80301320.slots[lbl_80301320.slot]);
    lbl_80301320.work = fn_80029B4C(&lbl_80301320.slots[lbl_80301320.slot], lbl_802639E0[mode].workSize, 0x20);
    lbl_80301320.prevState = lbl_80301320.state;
    lbl_80301320.state = 2;
    a = fn_80029B4C(&lbl_80301320.slots[lbl_80301320.slot], lbl_802639E0[mode].heapSize, 0x20);
    lbl_80301320.heap = fn_80115EA8(a, lbl_802639E0[mode].heapSize, 1);
    OSInitMutex(lbl_80301320.unk3C);
    lbl_80301320.unk38 = fn_80029B4C(&lbl_80301320.slots[lbl_80301320.slot], 0x388, 0x20);
    a = fn_80029B4C(&lbl_80301320.slots[lbl_80301320.slot], 0x2000, 0x20);
    fn_80029BCC(lbl_80301320.unk38, a, fn_80029B4C(&lbl_80301320.slots[lbl_80301320.slot], 0x160, 0x20));
    cur = lbl_80301320.slot;
    next = cur + 1;
    if (next < 2) {
        lbl_80301320.slot = next;
        fn_80029B14(&lbl_80301320.slots[(u8)next], lbl_80301320.slots[cur].buf, lbl_80301320.slots[cur].size);
    }
    lbl_802639E0[mode].func(arg);
}
