#include "types.h"

typedef struct Unk800292BCFile {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
} Unk800292BCFile;

typedef struct Unk800292BCList {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ Unk800292BCFile* files;
} Unk800292BCList;

typedef struct Unk80301320State {
    /* 0x00 */ u8 cur;
    /* 0x01 */ u8 prev;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ Unk800292BCList* list;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[0x14 - 0xC];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x18 - 0x16];
    /* 0x18 */ u8* unk18;
} Unk80301320State;

typedef struct Unk80301320 {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u8 pad8[0x29 - 0x8];
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u8 pad2A[0x2C - 0x2A];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x5C - 0x30];
    /* 0x5C */ Unk80301320State* state;
    /* 0x60 */ void (*cb)(s32 result, s32 arg1, void* arg2);
    /* 0x64 */ void* cbArg;
} Unk80301320;

extern Unk80301320 lbl_80301320;

void fn_80025484(void);
void fn_80025498(void);
void fn_80025860(void);
s32 fn_8024BD64(s32 err);
s32 fn_8023FCAC(u32 arg0, u32 arg1, u32 arg2, s32 arg3);
char* fn_80027394(s32 key);
s32 fn_80177360(const char* str, char** end, s32 base);
void fn_80029460(s32 arg0);
void fn_800F8E30(u64 ticks);

void fn_800292BC(void) {
    u8* buf;
    char* str;
    s32 n;
    s32 ret;
    Unk800292BCFile* file;

    fn_80025484();
    buf = lbl_80301320.state->unk18;
    str = fn_80027394(7);
    n = str != NULL ? fn_80177360(str, NULL, 10) : 0;
    file = &lbl_80301320.state->list->files[lbl_80301320.state->unk14];
    ret = fn_8023FCAC(file->unk0, file->unk4, **(u32**)(buf + lbl_80301320.state->unk15 * 0x30 + 0x10), n);
    if (ret < 0 && fn_8024BD64(ret) != 0x31D2B) {
        lbl_80301320.unk29 = 5;
        lbl_80301320.unk2C = fn_8024BD64(ret);
        fn_80025860();
        lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
        fn_80025498();
        return;
    }
    lbl_80301320.state->unk8 = ret;
    lbl_80301320.state->prev = lbl_80301320.state->cur;
    lbl_80301320.state->cur = 0x14;
    lbl_80301320.state->prev = lbl_80301320.state->cur;
    lbl_80301320.state->cur = 0x12;
    fn_80025498();
    while (lbl_80301320.state->cur != 0x14 && !(lbl_80301320.unk4 & 0x1000000)) {
        fn_800F8E30((*(u32*)0x800000F8 / 4) / 1000000);
    }
    if (!(lbl_80301320.unk4 & 0x1000000)) {
        fn_80029460(0);
    }
}
