#include "types.h"

typedef struct Unk80028F44File {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
} Unk80028F44File;

typedef struct Unk80028F44List {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ Unk80028F44File* files;
} Unk80028F44List;

typedef struct Unk80301320State {
    /* 0x00 */ u8 cur;
    /* 0x01 */ u8 prev;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ Unk80028F44List* list;
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
s32 fn_8024F334(u32 arg0, u32 arg1, s32 arg2, void* arg3);
void fn_800F8E30(u64 ticks);


typedef struct Unk80301388 {
    /* 0x00 */ u8 mutex[0x18];
    /* 0x18 */ void* heap;
    /* 0x1C */ u8 pad1C[0x2A - 0x1C];
    /* 0x2A */ u16 flags;
    /* 0x2C */ void* buf;
    /* 0x30 */ u32 count;
} Unk80301388;

extern Unk80301388 lbl_80301388;

void fn_800F615C(void* mutex);
void fn_800F6238(void* mutex);
void fn_80116038(void* heap, void* p);
void* fn_80115F88(void* heap, u32 size, s32 align);
void fn_8002541C(void* p);
void* fn_800253B0(u32 size, s32 align);
void fn_80029170(u32* count);

static inline void Free(void* p) {
    if (!(lbl_80301388.flags & 1)) {
        fn_800F615C(&lbl_80301388);
        fn_80116038(lbl_80301388.heap, p);
        fn_800F6238(&lbl_80301388);
    } else {
        fn_8002541C(p);
    }
}

static inline void* Alloc(u32 size) {
    void* p;

    if (!(lbl_80301388.flags & 1)) {
        fn_800F615C(&lbl_80301388);
        p = fn_80115F88(lbl_80301388.heap, size, 0x20);
        fn_800F6238(&lbl_80301388);
    } else {
        p = fn_800253B0(size, 0x20);
    }
    return p;
}

void fn_80028F44(s32 arg0) {
    u32 count;
    void* p;
    s32 ret;

    fn_80029170(&count);
    p = lbl_80301388.buf;
    if (p != NULL && lbl_80301388.count != count) {
        Free(p);
        lbl_80301388.buf = NULL;
    }
    lbl_80301388.count = count;
    if (count == 0) {
        return;
    }
    lbl_80301388.buf = Alloc(count * 16);
    if (lbl_80301388.buf == NULL) {
        return;
    }
    fn_80025484();
    ret = fn_8024F334(lbl_80301320.state->list->files[lbl_80301320.state->unk14].unk0,
                      lbl_80301320.state->list->files[lbl_80301320.state->unk14].unk4, (s32)lbl_80301388.buf,
                      &lbl_80301388.count);
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
}
