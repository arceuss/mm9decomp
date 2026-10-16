#include "types.h"

typedef struct Unk80301320Status {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[0x18 - 0x2];
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

typedef struct Unk8002A898Callbacks {
    /* 0x0 */ void* unk0;
    /* 0x4 */ void* unk4;
} Unk8002A898Callbacks;

void* memset(void* dst, int c, u32 n);
s32 fn_8022F87C(Unk8002A898Callbacks* cbs);
s32 fn_8022FB40(void);
s32 fn_8022622C(void);
void fn_80025860(void);
void fn_8002A7E8(void);
void fn_8002A7F4(void);
void fn_8002AA5C(void);
void fn_8002A9AC(void);
void fn_8002AAC8(void* arg);

void fn_8002A898(void* arg) {
    Unk8002A898Callbacks cbs;
    s32 result;

    memset(&cbs, 0, sizeof(cbs));
    cbs.unk0 = fn_8002A7E8;
    cbs.unk4 = fn_8002A7F4;
    result = fn_8022F87C(&cbs);
    if (result < 0) {
        lbl_80301320.unk29 = 3;
        lbl_80301320.unk2C = -result;
        fn_80025860();
        lbl_80301320.callback(3, 0, lbl_80301320.unk64);
        return;
    }
    lbl_80301320.unk5C->unk18 = fn_8002AA5C;
    result = fn_8022FB40();
    if (result < 0) {
        lbl_80301320.unk29 = 4;
        lbl_80301320.unk2C = fn_8022622C() * -1;
        fn_80025860();
        lbl_80301320.callback(3, 0, lbl_80301320.unk64);
        return;
    }
    lbl_80301320.unk5C->unk18 = fn_8002A9AC;
    fn_8002AAC8(arg);
}
