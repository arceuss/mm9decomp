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

typedef struct Unk8002B32CInfo {
    /* 0x0 */ void* unk0;
    /* 0x4 */ void* unk4;
} Unk8002B32CInfo;

BOOL fn_801F7870(void* arg);
void fn_801F787C(void* arg);
s32 fn_801FB3E4(void);
void fn_80025728(s32 arg0, void* arg1, s32 arg2);

void fn_8002B32C(s32 result) {
    if (result != 0) {
        return;
    }
    if (fn_801F7870(((Unk8002B32CInfo*)lbl_80301320.sub->unk8)->unk4)) {
        fn_801F787C(((Unk8002B32CInfo*)lbl_80301320.sub->unk8)->unk4);
        lbl_80301320.callback(1, 0, lbl_80301320.user);
    }
    if (fn_801FB3E4() == 2) {
        fn_80025728(1, ((Unk8002B32CInfo*)lbl_80301320.sub->unk8)->unk0, 0);
        lbl_80301320.errorKind = 4;
        lbl_80301320.callback(3, 0, lbl_80301320.user);
    } else {
        lbl_80301320.sub->prevState = lbl_80301320.sub->state;
        lbl_80301320.sub->state = 7;
        lbl_80301320.flags |= 0x10;
    }
}
