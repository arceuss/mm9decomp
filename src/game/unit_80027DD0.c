#include "types.h"

typedef struct Unk80301320State {
    /* 0x00 */ u8 pad0[0xD4];
    /* 0xD4 */ void (*step)(void);
} Unk80301320State;

typedef struct Unk80301320 {
    /* 0x00 */ u8 pad0[0x29];
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u8 pad2A[0x2C - 0x2A];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x5C - 0x30];
    /* 0x5C */ Unk80301320State* state;
    /* 0x60 */ void (*cb)(s32 result, s32 arg1, void* arg2);
    /* 0x64 */ void* cbArg;
} Unk80301320;

typedef struct Unk80027DD0Alloc {
    /* 0x0 */ void* (*alloc)(u32 size);
    /* 0x4 */ void (*free)(void* ptr);
} Unk80027DD0Alloc;

extern Unk80301320 lbl_80301320;

void* memset(void* dst, int c, u32 n);
void* fn_80027130(u32 size);
void fn_8002713C(void* ptr);
s32 fn_8022F87C(Unk80027DD0Alloc* alloc);
void fn_80027FFC(void);
s32 fn_8022FB40(void);
s32 fn_8022622C(void);
void fn_80027F4C(void);
void* fn_80027144(u32 size);
void fn_80027148(void* ptr);
s32 fn_8022D224(void* (*alloc)(u32), void (*free)(void*), s32 arg2);
s32 fn_8022D2E4(void);
void fn_80028068(void);
void fn_80028184(void* arg0);
void fn_80025860(void);

void fn_80027DD0(void* arg0) {
    Unk80027DD0Alloc alloc;
    s32 ret;

    memset(&alloc, 0, sizeof(alloc));
    alloc.alloc = fn_80027130;
    alloc.free = fn_8002713C;
    ret = fn_8022F87C(&alloc);
    if (ret < 0) {
        lbl_80301320.unk29 = 3;
        lbl_80301320.unk2C = -ret;
        fn_80025860();
        lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
        return;
    }
    lbl_80301320.state->step = fn_80027FFC;
    if (fn_8022FB40() < 0) {
        lbl_80301320.unk29 = 5;
        ret = fn_8022622C();
        lbl_80301320.unk2C = ret - ret * 2;
        fn_80025860();
        lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
        return;
    }
    lbl_80301320.state->step = fn_80027F4C;
    if (fn_8022D224(fn_80027144, fn_80027148, 0x18) < 0) {
        lbl_80301320.unk29 = 3;
        lbl_80301320.unk2C = fn_8022D2E4() + 0x32C1C;
        fn_80025860();
        lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
        return;
    }
    lbl_80301320.state->step = fn_80028068;
    fn_80028184(arg0);
}
