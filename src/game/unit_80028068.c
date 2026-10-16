#include "types.h"

typedef struct Unk80301320Status {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
} Unk80301320Status;

typedef struct Unk80301320 {
    /* 0x00 */ u8 pad0[0x29];
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u8 pad2A[0x2C - 0x2A];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x5C - 0x30];
    /* 0x5C */ Unk80301320Status* unk5C;
    /* 0x60 */ void (*callback)(s32 result, s32 arg1, s32 arg2);
    /* 0x64 */ s32 unk64;
} Unk80301320;

extern Unk80301320 lbl_80301320;

void fn_8022D2B0(void* callback);
void fn_800299C0(void);
void fn_800F8E30(s64 ticks);
s32 fn_8022FF74(void);
s32 fn_8022FA44(void);
void fn_80025860(void);
void fn_80025358(void);

static inline void Fail(s32 result) {
    lbl_80301320.unk29 = 3;
    lbl_80301320.unk2C = -result;
    fn_80025860();
    lbl_80301320.callback(3, 0, lbl_80301320.unk64);
}

void fn_80028068(void) {
    u8 status;
    s32 result;

    fn_8022D2B0(fn_800299C0);
    status = lbl_80301320.unk5C->unk0;
    lbl_80301320.unk5C->unk1 = status;
    lbl_80301320.unk5C->unk0 = 0x13;
    while (status == lbl_80301320.unk5C->unk0) {
        fn_800F8E30((*(u32*)0x800000F8 / 4) / 1000000);
    }
    result = fn_8022FF74();
    if (result < 0) {
        Fail(result);
        return;
    }
    result = fn_8022FA44();
    if (result < 0) {
        Fail(result);
        return;
    }
    fn_80025358();
}
