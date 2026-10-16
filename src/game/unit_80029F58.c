#include "types.h"

typedef struct Unk80301320State {
    /* 0x00 */ u8 cur;
    /* 0x01 */ u8 prev;
    /* 0x02 */ u8 tmp;
    /* 0x03 */ u8 pad3[0x10 - 0x3];
    /* 0x10 */ void* conn;
    /* 0x14 */ u8 cfg[0x22 - 0x14];
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u8 pad24[0x40 - 0x24];
    /* 0x40 */ s32 unk40;
} Unk80301320State;

typedef struct Unk80301320 {
    /* 0x00 */ u8 mode;
    /* 0x01 */ u8 pad1[0x4 - 0x1];
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

BOOL fn_80025470(void);
void fn_80025498(void);
void fn_80025860(void);
s32 fn_801FB3E8(void);
void fn_801E71A0(void);
s32 fn_801F6AAC(void);
s32 fn_801F6BF8(void);
s32 fn_801F6DE4(s32* out);
void* fn_801E2DD0(s32* err, void* cfg);

static inline void Swap(void) {
    lbl_80301320.state->tmp = lbl_80301320.state->cur;
    lbl_80301320.state->cur = lbl_80301320.state->prev;
    lbl_80301320.state->prev = lbl_80301320.state->tmp;
}

void fn_80029F58(void) {
    s32 err;
    s32 out;

    if (lbl_80301320.mode == 3 && fn_80025470()) {
        if (lbl_80301320.state->cur == 9) {
            err = fn_801FB3E8();
            if (err == 3) {
                Swap();
            } else if (err != 2) {
                Swap();
                lbl_80301320.unk29 = 4;
                lbl_80301320.unk2C = -err;
                fn_80025860();
                lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
                fn_80025498();
                return;
            }
        }
        if (lbl_80301320.state->cur == 0xA || (lbl_80301320.unk4 & 0x10)) {
            fn_801E71A0();
        }
        if ((u8)(lbl_80301320.state->cur + 0xF4) <= 1 && (err = fn_801F6AAC()) != 0) {
            if (err == 0xF) {
                lbl_80301320.cb(0, 0, lbl_80301320.cbArg);
            }
            if (err != 1 && fn_801F6BF8() != 6) {
                lbl_80301320.state->unk22 = 0xFFFF;
                if (lbl_80301320.state->cur == 0xC) {
                    err = fn_801F6DE4(&out);
                    if (err != 0) {
                        lbl_80301320.unk29 = 4;
                        lbl_80301320.unk2C = err;
                        fn_80025860();
                        lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
                        fn_80025498();
                        return;
                    }
                    lbl_80301320.state->unk40 = out;
                } else {
                    lbl_80301320.state->unk40 = 0;
                }
                lbl_80301320.state->prev = lbl_80301320.state->cur;
                lbl_80301320.state->cur = 7;
            }
        }
        lbl_80301320.state->conn = fn_801E2DD0(&err, lbl_80301320.state->cfg);
        if (lbl_80301320.state->conn != NULL) {
            lbl_80301320.unk29 = 4;
            lbl_80301320.unk2C = -err;
            fn_80025860();
            lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
            fn_80025498();
            return;
        }
        fn_80025498();
    }
}
