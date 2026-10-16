#include "types.h"

typedef struct Unk80029460File {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
} Unk80029460File;

typedef struct Unk80029460List {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ Unk80029460File* files;
} Unk80029460List;

typedef struct Unk80301320State {
    /* 0x00 */ u8 cur;
    /* 0x01 */ u8 prev;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ Unk80029460List* list;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[0x14 - 0xC];
    /* 0x14 */ u8 unk14;
} Unk80301320State;

typedef struct Unk80301320 {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u8 pad8[0x29 - 0x8];
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u8 pad2A[0x2C - 0x2A];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x5C - 0x30];
    /* 0x5C */ Unk80301320State* state;
    /* 0x60 */ void (*cb)(s32 result, s32 arg1, void* arg2);
    /* 0x64 */ void* cbArg;
} Unk80301320;

extern Unk80301320 lbl_80301320;

void fn_80025484(void);
void fn_80025498(void);
void fn_80025860(void);
s32 fn_8024BD64(s32 err);
s32 fn_8023DD4C(u32 arg0, u32 arg1, s32 arg2);
void fn_8002968C(s32 arg0);
void fn_800F8E30(u64 ticks);

typedef struct Unk80301388Entry {
    /* 0x00 */ u64 id;
    /* 0x08 */ u8 pad8[0xC - 0x8];
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x18 - 0x10];
} Unk80301388Entry;

typedef struct Unk80301388 {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ u32 mask;
    /* 0x20 */ Unk80301388Entry* entries;
    /* 0x24 */ u8 pad24[0x28 - 0x24];
    /* 0x28 */ u8 count;
} Unk80301388;

extern Unk80301388 lbl_80301388;

static inline u8 Find(Unk80301388Entry* e, u8 n, u32 mask, u64 id) {
    s32 i;

    for (i = 0; i < n; i++) {
        if ((mask & (1 << i)) && e[i].id == id) {
            return i;
        }
    }
    return 0xFF;
}

static inline s32 Size(Unk80301388Entry* e, u8 n, u32 mask, u64 id) {
    u8 idx = Find(e, n, mask, id);

    if (idx == 0xFF) {
        return 0;
    }
    return e[idx].unkC;
}

void fn_80029460(s32 arg0) {
    s32 ret;

    if (Size(lbl_80301388.entries, lbl_80301388.count, lbl_80301388.mask,
             *(u64*)&lbl_80301320.state->list->files[lbl_80301320.state->unk14]) == 0) {
        fn_80025484();
        ret = fn_8023DD4C(lbl_80301320.state->list->files[lbl_80301320.state->unk14].unk0,
                          lbl_80301320.state->list->files[lbl_80301320.state->unk14].unk4, 0);
        if (ret < 0 && fn_8024BD64(ret) != 0x31D2B) {
            lbl_80301320.unk29 = 5;
            lbl_80301320.unk2C = fn_8024BD64(ret);
            fn_80025860();
            lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
            fn_80025498();
            return;
        }
        lbl_80301320.state->unk8 = ret;
        lbl_80301320.state->prev = lbl_80301320.state->cur;
        lbl_80301320.state->cur = 0x14;
        lbl_80301320.state->prev = lbl_80301320.state->cur;
        lbl_80301320.state->cur = 0x12;
        fn_80025498();
        while (lbl_80301320.state->cur != 0x14 && !(lbl_80301320.unk4 & 0x1000000)) {
            fn_800F8E30((*(u32*)0x800000F8 / 4) / 1000000);
        }
        lbl_80301320.unk4 &= ~0x80;
    }
    if (!(lbl_80301320.unk4 & 0x80) && !(lbl_80301320.unk4 & 0x1000000)) {
        fn_8002968C(0);
    }
}
