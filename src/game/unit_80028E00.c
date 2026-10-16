#include "types.h"

typedef struct Unk80028E00List {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u16 unk10;
} Unk80028E00List;

typedef struct Unk80301320State {
    /* 0x00 */ u8 cur;
    /* 0x01 */ u8 prev;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ Unk80028E00List* list;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 unk10[0x18 - 0x10];
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 unk1C[4];
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

typedef struct Unk80028E00Arg {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 pad2[0x4 - 0x2];
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u32 unk8;
} Unk80028E00Arg;

extern Unk80301320 lbl_80301320;

void fn_80025484(void);
void fn_80025498(void);
void fn_80025860(void);
s32 fn_8024BD64(s32 err);
s32 fn_8024FF30(s32 arg0, void* arg1, u8 arg2, u32 arg3, u8 arg4, u32 arg5, u16 arg6, u32 arg7, s32* arg8, u32 arg9, s32 arg10, void* arg11);

void fn_80028E00(Unk80028E00Arg* arg) {
    s32 ret;

    fn_80025484();
    lbl_80301320.state->unkC = 0x28;
    ret = fn_8024FF30(0, lbl_80301320.state->unk1C, arg->unk0, arg->unk4, arg->unk1,
                      lbl_80301320.state->list->unk8, lbl_80301320.state->list->unk10,
                      lbl_80301320.state->unk18, &lbl_80301320.state->unkC, arg->unk8, 0x8000,
                      lbl_80301320.state->unk10);
    if (ret < 0 && fn_8024BD64(ret) != 0x31D2B) {
        lbl_80301320.unk29 = 5;
        lbl_80301320.unk2C = fn_8024BD64(ret);
        fn_80025860();
        lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
        fn_80025498();
        return;
    }
    lbl_80301320.state->unk8 = ret;
    if (lbl_80301320.unk4 & 0x100) {
        lbl_80301320.state->prev = lbl_80301320.state->cur;
        lbl_80301320.state->cur = 0x14;
    }
    lbl_80301320.state->prev = lbl_80301320.state->cur;
    lbl_80301320.state->cur = 0x12;
    fn_80025498();
}
