#include "types.h"

typedef struct Unk80301320Sub {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 prevState;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ void* unk4;
    /* 0x08 */ void* unk8;
    /* 0x0C */ u8 padC[0x18 - 0xC];
    /* 0x18 */ void (*unk18)(void);
    /* 0x1C */ u8 pad1C[0x22 - 0x1C];
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u8 unk24[0x28 - 0x24];
    /* 0x28 */ s32 unk28;
} Unk80301320Sub;

typedef struct Unk80301320 {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 prevState;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ u32 flags;
    /* 0x08 */ u8 pad8[0x29 - 0x8];
    /* 0x29 */ u8 errorKind;
    /* 0x2A */ u8 pad2A[0x2C - 0x2A];
    /* 0x2C */ s32 errorCode;
    /* 0x30 */ u8 pad30[0x5C - 0x30];
    /* 0x5C */ Unk80301320Sub* sub;
    /* 0x60 */ void (*callback)(s32 event, s32 arg, void* user);
    /* 0x64 */ void* user;
} Unk80301320;

extern Unk80301320 lbl_80301320;

void fn_80025860(void);

void fn_80025484(void);
void fn_801E3258(void);
void fn_80025498(void);
s32 fn_8022FF74(void);
s32 fn_8022FA44(void);
void fn_80025358(void);

void fn_8002ABC4(void) {
    s32 result;

    fn_80025484();
    fn_801E3258();
    fn_80025498();
    result = fn_8022FF74();
    if (result < 0) {
        lbl_80301320.errorKind = 3;
        lbl_80301320.errorCode = -result;
        fn_80025860();
        lbl_80301320.callback(3, 0, lbl_80301320.user);
        return;
    }
    result = fn_8022FA44();
    if (result < 0) {
        lbl_80301320.errorKind = 3;
        lbl_80301320.errorCode = -result;
        fn_80025860();
        lbl_80301320.callback(3, 0, lbl_80301320.user);
        return;
    }
    fn_80025358();
}
