#include "types.h"

typedef struct Unk80301320State {
    /* 0x00 */ u8 cur;
    /* 0x01 */ u8 pad1[0x22 - 0x1];
    /* 0x22 */ u16 unk22;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
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

s32 fn_801F6C00(void* dst, u32 id);
void fn_80025860(void);

s32 fn_8002A3C4(u32 id, s32 field) {
    if (lbl_80301320.state->cur == 7 && (lbl_80301320.unk4 & 0x20)) {
        if (id != lbl_80301320.state->unk22) {
            if (fn_801F6C00(&lbl_80301320.state->unk24, id) != 0) {
                lbl_80301320.unk29 = 4;
                lbl_80301320.unk2C = 0;
                fn_80025860();
                lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
                return -1;
            }
            lbl_80301320.state->unk22 = id;
        }
        switch (field) {
        case 0:
            return lbl_80301320.state->unk24;
        case 1:
            return lbl_80301320.state->unk2C;
        case 2:
            return lbl_80301320.state->unk30;
        case 3:
            return lbl_80301320.state->unk34;
        case 4:
            return lbl_80301320.state->unk38;
        case 5:
            return lbl_80301320.state->unk3C;
        }
    }
    return -1;
}
