#include "types.h"

typedef struct OSThreadQueue {
    /* 0x0 */ void* head;
    /* 0x4 */ void* tail;
} OSThreadQueue;

typedef struct Unk8038E7C0Entry {
    /* 0x0000 */ u8 pad0[0x431C];
    /* 0x431C */ s32 id;
    /* 0x4320 */ u8 unk4320;
    /* 0x4321 */ u8 unk4321;
    /* 0x4322 */ u8 pad4322[0x4330 - 0x4322];
} Unk8038E7C0Entry;

typedef struct Unk8038E7C0 {
    /* 0x0000 */ s32 unk0;
    /* 0x0004 */ OSThreadQueue queue;
    /* 0x000C */ u8 padC[0x10 - 0xC];
    /* 0x0010 */ Unk8038E7C0Entry entries[3];
    /* 0xC9A0 */ u8 unkC9A0[8];
    /* 0xC9A8 */ u8 unkC9A8[0xC9C0 - 0xC9A8];
} Unk8038E7C0;

extern Unk8038E7C0 lbl_8038E7C0;

void OSInitCond(void* arg0);
void OSInitMutex(void* arg0);
void OSInitThreadQueue(OSThreadQueue* queue);

void fn_800E6354(s32 arg0) {
    Unk8038E7C0Entry* entry;
    s32 i;

    lbl_8038E7C0.unk0 = arg0;
    entry = lbl_8038E7C0.entries;
    for (i = 0; i < 3; i++) {
        entry->id = i;
        entry->unk4321 = 1;
        entry++;
    }
    OSInitCond(lbl_8038E7C0.unkC9A0);
    OSInitMutex(lbl_8038E7C0.unkC9A8);
    OSInitThreadQueue(&lbl_8038E7C0.queue);
}
