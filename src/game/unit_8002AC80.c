#include "types.h"

typedef struct Unk8002AC80Info {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk8002AC80Info;

typedef struct Unk8002AC80Ptr {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ void* unk4;
} Unk8002AC80Ptr;

typedef struct Unk8002AC80Pair {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
} Unk8002AC80Pair;

typedef struct Unk80301320Status {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ struct Unk8002AC80Ptr* unk4;
    /* 0x08 */ struct Unk8002AC80Ptr* unk8;
    /* 0x0C */ struct Unk8002AC80Pair* unkC;
    /* 0x10 */ u8 pad10[0x18 - 0x10];
    /* 0x18 */ void* unk18;
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

void fn_80025484(void);
void fn_80025498(void);
void fn_80025860(void);
void fn_801E6DA8(s32 arg0, void* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
s32 fn_801E743C(s32 arg0, s32 arg1, void* callback, s32 arg3);
void fn_8002ADBC(void);
void fn_8002B32C(void);

void fn_8002AC80(void) {
    Unk8002AC80Pair* pair;
    s32 a;
    s32 b;
    Unk8002AC80Info* info;

    if (lbl_80301320.unk5C->unk4 != NULL) {
        pair = lbl_80301320.unk5C->unkC;
        if (pair != NULL) {
            a = pair->unk4;
            b = pair->unk0;
        }
        fn_80025484();
        info = lbl_80301320.unk5C->unk4->unk4;
        fn_801E6DA8(0, lbl_80301320.unk5C->unk8->unk4, info->unk4, info->unk0, info->unk8, info->unkC, info->unk10, a, b);
        lbl_80301320.unk5C->unk18 = fn_8002ADBC;
        fn_80025498();
    }
    fn_80025484();
    if (fn_801E743C(lbl_80301320.unk5C->unk8->unk0, 0, fn_8002B32C, 0) == 0) {
        lbl_80301320.unk29 = 4;
        lbl_80301320.unk2C = 0;
        fn_80025860();
        lbl_80301320.callback(3, 0, lbl_80301320.unk64);
        fn_80025498();
    } else {
        lbl_80301320.unk5C->unk1 = lbl_80301320.unk5C->unk0;
        lbl_80301320.unk5C->unk0 = 10;
        fn_80025498();
    }
}
