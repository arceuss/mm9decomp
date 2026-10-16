#include "types.h"

typedef struct Unk80025E54File {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
} Unk80025E54File;

typedef struct Unk80025E54List {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ Unk80025E54File* files;
} Unk80025E54List;

typedef struct Unk80301320State {
    /* 0x00 */ u8 cur;
    /* 0x01 */ u8 prev;
    /* 0x02 */ u8 tmp;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ Unk80025E54List* list;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[0x14 - 0xC];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 progress;
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
BOOL fn_80025470(void);
void fn_800254AC(s32 msg, s32 arg1);
void fn_8002533C(void);

typedef struct Unk80025E54Stat {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u32 total;
    /* 0x14 */ u32 done;
    /* 0x18 */ s32 err;
    /* 0x1C */ u8 pad1C[0xA0 - 0x1C];
} Unk80025E54Stat;

s32 fn_8024C9E8(s32 handle, Unk80025E54Stat* stat);
void fn_800F8E30(u64 ticks);

void fn_80025E54(void) {
    Unk80025E54Stat stat;
    s32 ret;
    Unk80301320State* st;
    Unk80301320* g;

    if (!fn_80025470()) {
        return;
    }
    g = &lbl_80301320;
    if (g->state->cur == 0x12) {
        ret = fn_8024C9E8(g->state->unk8, &stat);
        if (ret < 0 && fn_8024BD64(stat.err) != 0x31D2B) {
            if (ret != -0xFA9) {
                if (ret == -0xFEE) {
                    g->cb(2, 0, g->cbArg);
                    fn_80025498();
                } else if (ret == -0xFF5) {
                    fn_800254AC(0x17, 0);
                    g->unk29 = 5;
                    g->cb(3, 0, g->cbArg);
                    fn_80025498();
                } else if (ret == -0xFF6) {
                    fn_800254AC(0x18, 0);
                    g->unk29 = 5;
                    g->cb(3, 0, g->cbArg);
                    fn_80025498();
                } else {
                    g->unk29 = 5;
                    g->unk2C = fn_8024BD64(stat.err);
                    fn_80025860();
                    g->cb(3, 0, g->cbArg);
                    fn_80025498();
                }
                return;
            }
            if ((lbl_80301320.unk4 & 0x40) && stat.total != 0) {
                lbl_80301320.state->progress = stat.done * 100 / stat.total;
                st = lbl_80301320.state;
                if (st->progress >= 100) {
                    lbl_80301320.unk4 &= ~0x40;
                    st->progress = 100;
                }
            }
        } else {
            if (lbl_80301320.unk4 & 0x40) {
                lbl_80301320.state->progress = 100;
                lbl_80301320.unk4 &= ~0x40;
            }
            lbl_80301320.state->tmp = lbl_80301320.state->cur;
            lbl_80301320.state->cur = lbl_80301320.state->prev;
            lbl_80301320.state->prev = lbl_80301320.state->tmp;
            if (lbl_80301320.state->cur == 0xE) {
                fn_8002533C();
            }
            if (lbl_80301320.state->cur != 0x14) {
                lbl_80301320.state->prev = lbl_80301320.state->cur;
                lbl_80301320.state->cur = 0x10;
            }
        }
    }
    fn_80025498();
}
