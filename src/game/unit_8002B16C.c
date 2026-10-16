#include "types.h"

typedef struct Unk80301320Sub {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 prevState;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ void* unk4;
    /* 0x08 */ void* unk8;
    /* 0x0C */ u8 padC[0x18 - 0xC];
    /* 0x18 */ void (*unk18)(void);
    /* 0x1C */ void* unk1C;
    /* 0x20 */ u16 unk20;
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

typedef struct Unk8002B16CArgs {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk8002B16CArgs;

void fn_80025484(void);
void fn_80025498(void);
s32 fn_801F6750(u16 arg0, void* arg1, s32 arg2, s32 arg3, s32 arg4);

void fn_8002B16C(Unk8002B16CArgs* args) {
    s32 result;

    fn_80025484();
    result = fn_801F6750(lbl_80301320.sub->unk20, lbl_80301320.sub->unk1C, args->unk0, args->unk4, args->unk8);
    if (result != 0) {
        lbl_80301320.errorKind = 4;
        lbl_80301320.errorCode = result;
        fn_80025860();
        lbl_80301320.callback(3, 0, lbl_80301320.user);
        fn_80025498();
        return;
    }
    lbl_80301320.sub->prevState = lbl_80301320.sub->state;
    lbl_80301320.sub->state = 13;
    fn_80025498();
}
