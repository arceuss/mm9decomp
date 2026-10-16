#include "types.h"

typedef struct Unk80026254Pair {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
} Unk80026254Pair;

typedef struct Unk80026254Req {
    /* 0x0 */ u8 count;
    /* 0x1 */ u8 numEntries;
    /* 0x2 */ u8 pad2[0x4 - 0x2];
    /* 0x4 */ Unk80026254Pair* entries;
    /* 0x8 */ void* buf;
} Unk80026254Req;

typedef struct Unk80301320Slot {
    /* 0x0 */ u8 pad0[0x10];
} Unk80301320Slot;

typedef struct Unk80301320State {
    /* 0x00 */ u8 cur;
    /* 0x01 */ u8 prev;
    /* 0x02 */ u8 pad2[0x14 - 0x2];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ void* unk18;
    /* 0x1C */ u32 unk1C[16];
} Unk80301320State;

typedef struct Unk80301320 {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ Unk80301320Slot slots[2];
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 pad29[0x5C - 0x29];
    /* 0x5C */ Unk80301320State* state;
} Unk80301320;

extern Unk80301320 lbl_80301320;
extern Unk80026254Pair lbl_804EC880[1];

u8 fn_80027234(u32* out, u32 mask, BOOL withList);
void fn_80029B30(Unk80301320Slot* slot);
void* fn_80029B4C(Unk80301320Slot* slot, u32 size, u32 align);
void fn_80028E00(void* arg);
void fn_80025C34(void (*cb)(void*), void* arg, u32 size);

void fn_80026254(u32 flags, Unk80026254Pair* entries, u32 count) {
    Unk80026254Req req;
    u8 n;
    void* buf;
    s32 total;
    s32 i;

    if (lbl_80301320.state->cur != 0x10) {
        return;
    }
    n = fn_80027234(lbl_80301320.state->unk1C, flags & 0x3F80, TRUE);
    fn_80029B30(&lbl_80301320.slots[lbl_80301320.unk28]);
    lbl_80301320.state->unk18 = fn_80029B4C(&lbl_80301320.slots[lbl_80301320.unk28], 0x780, 0x20);
    buf = fn_80029B4C(&lbl_80301320.slots[lbl_80301320.unk28], 0x8000, 0x20);
    total = count + 1;
    req.count = n;
    req.entries = fn_80029B4C(&lbl_80301320.slots[lbl_80301320.unk28], total * 8, 0x20);
    req.numEntries = total;
    req.buf = buf;
    for (i = 0; i < total; i++) {
        if (i < 1) {
            req.entries[i].unk0 = lbl_804EC880[i].unk0;
            req.entries[i].unk4 = lbl_804EC880[i].unk4;
        } else {
            req.entries[i].unk0 = entries[i - 1].unk0;
            req.entries[i].unk4 = entries[i - 1].unk4;
        }
    }
    lbl_80301320.state->unk14 = 0;
    lbl_80301320.state->unk15 = 0;
    lbl_80301320.state->unk17 = 1;
    lbl_80301320.state->prev = lbl_80301320.state->cur;
    lbl_80301320.state->cur = 0x11;
    fn_80025C34(fn_80028E00, &req, sizeof(req));
}
