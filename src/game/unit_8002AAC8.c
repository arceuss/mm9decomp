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

typedef struct Unk8002AAC8Info {
    /* 0x0 */ void* unk0;
    /* 0x4 */ void** unk4;
} Unk8002AAC8Info;

void fn_80025484(void);
void fn_80025498(void);
void fn_8002533C(void);
s32 fn_801E2EEC(s32 arg0, void* arg1, void* arg2, void (*a)(void), void (*b)(void));
void fn_801E3560(s32 arg0);
void fn_801E2E88(void);
void fn_8002A7FC(void);
void fn_8002A808(void);
void fn_8002ABC4(void);

void fn_8002AAC8(void) {
    Unk8002AAC8Info* info = lbl_80301320.sub->unk4;
    void* arg = NULL;
    s32 result;

    if (info->unk4 != NULL) {
        arg = *info->unk4;
    }
    fn_80025484();
    result = fn_801E2EEC(1, arg, info->unk0, fn_8002A7FC, fn_8002A808);
    if (result != 0) {
        lbl_80301320.errorKind = 4;
        lbl_80301320.errorCode = -result;
        fn_80025860();
        lbl_80301320.callback(3, 0, lbl_80301320.user);
        fn_80025498();
        return;
    }
    lbl_80301320.sub->unk18 = fn_8002ABC4;
    fn_8002533C();
    lbl_80301320.sub->prevState = lbl_80301320.sub->state;
    lbl_80301320.sub->state = 7;
    fn_801E3560(0);
    fn_801E2E88();
    fn_80025498();
}
