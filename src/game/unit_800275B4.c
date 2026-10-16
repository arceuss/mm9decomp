#include "types.h"

typedef struct Unk80301320 {
    /* 0x00 */ u8 pad0[0x29];
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u8 pad2A[0x2C - 0x2A];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x60 - 0x30];
    /* 0x60 */ void (*cb)(s32 result, s32 arg1, void* arg2);
    /* 0x64 */ void* cbArg;
} Unk80301320;

extern Unk80301320 lbl_80301320;

s32 fn_8011D698(u32 size, s32 arg1, u32* flags);
void fn_80025860(void);
void fn_800255D8(s32 msg, s32 arg1, s32 arg2);
void fn_800254AC(s32 msg, s32 arg1);

BOOL fn_800275B4(u32 size, s32 arg1) {
    u32 flags[2];
    s32 blocks;

    if (fn_8011D698(size, arg1, flags) != 0) {
        lbl_80301320.unk29 = 2;
        lbl_80301320.unk2C = 0;
        fn_80025860();
        lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
        return FALSE;
    }
    if (flags[0] & 4) {
        blocks = (size * 0x4000 + 0x1FFFF) >> 17;
        if (blocks > 1) {
            fn_800255D8(0x11, blocks, 0);
            lbl_80301320.unk29 = 5;
        } else {
            fn_800255D8(0x19, blocks, 0);
            lbl_80301320.unk29 = 5;
        }
        lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
        return FALSE;
    }
    if (flags[0] & 8) {
        fn_800254AC(0x12, 0);
        lbl_80301320.unk29 = 5;
        lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
        return FALSE;
    }
    return TRUE;
}
