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
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u8 pad8[0x29 - 0x8];
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
void fn_80025358(void);
void fn_801E7030(void);
void fn_801E3258(void);
s32 fn_801F7870(void* arg0);
void fn_801F787C(void* arg0);
s32 fn_8022FF74(void);
s32 fn_8022FA44(void);
void fn_8002ABC4(void);

static inline void Fail(s32 result) {
    lbl_80301320.unk29 = 3;
    lbl_80301320.unk2C = -result;
    fn_80025860();
    lbl_80301320.callback(3, 0, lbl_80301320.unk64);
}

static inline void Finish(void) {
    s32 result;

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

void fn_8002ADBC(void) {
    fn_80025484();
    fn_801E7030();
    lbl_80301320.unk4 &= ~0x10;
    fn_80025498();
    if (fn_801F7870(lbl_80301320.unk5C->unk8->unk4)) {
        fn_801F787C(lbl_80301320.unk5C->unk8->unk4);
        lbl_80301320.callback(1, 0, lbl_80301320.unk64);
    }
    if (lbl_80301320.unk4 & 0x01000000) {
        fn_80025484();
        fn_801E3258();
        fn_80025498();
        Finish();
    } else {
        lbl_80301320.unk5C->unk18 = fn_8002ABC4;
    }
}
