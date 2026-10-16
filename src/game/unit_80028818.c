#include "types.h"

typedef struct Unk80028818File {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
} Unk80028818File;

typedef struct Unk80028818List {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ Unk80028818File* files;
} Unk80028818List;

typedef struct Unk80301320State {
    /* 0x00 */ u8 cur;
    /* 0x01 */ u8 prev;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ Unk80028818List* list;
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

s32 fn_8024C4D4(void);
void fn_80028F44(s32 arg0);
void fn_8002533C(void);
void fn_8002609C(s32 arg0, s32 arg1, s32 arg2);
BOOL fn_80027A38(u32 arg0, u32 arg1);

void fn_80028818(void) {
    s32 ret;
    u32 flags;
    u32 bit;

    fn_80025484();
    ret = fn_8024C4D4();
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
    if (lbl_80301320.unk4 & 0x1000000) {
        return;
    }
    fn_80028F44(0);
    flags = lbl_80301320.unk4;
    bit = flags & 0x80;
    if (bit || (flags & 0x100)) {
        if (bit) {
            lbl_80301320.state->prev = lbl_80301320.state->cur;
            lbl_80301320.state->cur = 0x10;
            fn_8002533C();
        } else if (flags & 0x100) {
            fn_8002609C(2, 0, 0);
        }
    } else {
        fn_80027A38(lbl_80301320.state->list->files[0].unk0, lbl_80301320.state->list->files[0].unk4);
        lbl_80301320.state->prev = lbl_80301320.state->cur;
        lbl_80301320.state->cur = 0x10;
        fn_8002533C();
    }
}
