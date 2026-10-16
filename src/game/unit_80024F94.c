#include "types.h"

typedef struct Unk80301320Slot {
    /* 0x0 */ u8 pad0[0x10];
} Unk80301320Slot;

typedef struct Unk80301320 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ u32 unk4;
    /* 0x08 */ Unk80301320Slot slots[2];
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u8 pad2A[0x2C - 0x2A];
    /* 0x2C */ u32 unk2C;
    /* 0x30 */ u8* unk30;
    /* 0x34 */ u8* unk34;
    /* 0x38 */ u8 pad38[0x58 - 0x38];
    /* 0x58 */ u8* unk58;
    /* 0x5C */ u8 pad5C[0x60 - 0x5C];
    /* 0x60 */ void (*cb)(s32 result, s32 arg1, void* arg2);
    /* 0x64 */ void* cbArg;
} Unk80301320;

extern Unk80301320 lbl_80301320;
extern u8 lbl_802639D0[];

void fn_80025860(void);
void fn_80029E64(void* arg0, u8* buf, u32 size);
void fn_80029B14(void* slot, u8* buf, u32 size);

void fn_80024F94(u8* buf, u32 size, void (*cb)(s32, s32, void*), void* cbArg) {
    if ((u32)buf < 0x90000000 || (u32)buf > 0x93FFFFFF) {
        lbl_80301320.unk29 = 1;
        lbl_80301320.unk2C = 0;
        fn_80025860();
        lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
        return;
    }
    lbl_80301320.cb = cb;
    lbl_80301320.unk58 = buf;
    lbl_80301320.unk4 = 0;
    lbl_80301320.unk28 = 0;
    lbl_80301320.unk29 = 0;
    lbl_80301320.unk2C = 0;
    lbl_80301320.cbArg = cbArg;
    lbl_80301320.unk1 = 0;
    lbl_80301320.unk0 = 1;
    fn_80029E64(lbl_802639D0, buf, 0x10000);
    buf += 0x10000;
    lbl_80301320.unk30 = buf;
    lbl_80301320.unk34 = lbl_80301320.unk30 + 0x800;
    fn_80029B14(&lbl_80301320.slots[lbl_80301320.unk28], lbl_80301320.unk34 + 0x40, size - 0x10000 - 0x840);
}
