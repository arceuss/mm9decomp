#include "types.h"

typedef struct Unk8002968CFile {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
} Unk8002968CFile;

typedef struct Unk8002968CList {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ Unk8002968CFile* files;
} Unk8002968CList;

typedef struct Unk80301320State {
    /* 0x00 */ u8 cur;
    /* 0x01 */ u8 prev;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ Unk8002968CList* list;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[0x14 - 0xC];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
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
s32 fn_8024EA50(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
void fn_80028F44(s32 arg0);
char* fn_80027394(s32 key);
s32 fn_80177360(const char* str, char** end, s32 base);
void fn_80029460(s32 arg0);
void fn_800F8E30(u64 ticks);

void fn_8002968C(void) {
    u8* entry;
    s32 ret;

    fn_80025484();
    entry = lbl_80301320.state->unk18 + lbl_80301320.state->unk15 * 0x30;
    ret = fn_8024EA50(lbl_80301320.state->list->files[lbl_80301320.state->unk14].unk0,
                      lbl_80301320.state->list->files[lbl_80301320.state->unk14].unk4,
                      *(u32*)(entry + 0x24), *(u32*)(entry + 0x28));
    if (ret < 0 && fn_8024BD64(ret) != 0x31D2B) {
        lbl_80301320.unk29 = 5;
        lbl_80301320.unk2C = fn_8024BD64(ret);
        fn_80025860();
        lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
        fn_80025498();
        return;
    }
    lbl_80301320.state->unk8 = ret;
    lbl_80301320.state->unk16 = 0;
    lbl_80301320.unk4 |= 0x40;
    lbl_80301320.state->prev = lbl_80301320.state->cur;
    lbl_80301320.state->cur = 0x14;
    lbl_80301320.state->prev = lbl_80301320.state->cur;
    lbl_80301320.state->cur = 0x12;
    fn_80025498();
    while (lbl_80301320.state->cur != 0x14 && !(lbl_80301320.unk4 & 0x1000000)) {
        fn_800F8E30((*(u32*)0x800000F8 / 4) / 1000000);
    }
    if (!(lbl_80301320.unk4 & 0x1000000)) {
        fn_80028F44(0);
        lbl_80301320.state->prev = lbl_80301320.state->cur;
        lbl_80301320.state->cur = 0x10;
    }
}
