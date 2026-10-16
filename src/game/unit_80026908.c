#include "types.h"

typedef struct Unk80026908File {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
} Unk80026908File;

typedef struct Unk80026908List {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ Unk80026908File* files;
} Unk80026908List;

typedef struct Unk80301320State {
    /* 0x00 */ u8 cur;
    /* 0x01 */ u8 prev;
    /* 0x02 */ u8 tmp;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ Unk80026908List* list;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[0x14 - 0xC];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 progress;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8* blocks;
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
char* fn_80027394(s32 key);
s32 fn_80177360(const char* str, char** end, s32 base);
u32 fn_800265F4(s32 arg0);
void fn_8024D950(s32 arg0, u32* out0, u32* out1);
BOOL fn_800275B4(u32 a, u32 b);
s32 fn_8024CB74(u32* out);
void fn_800254AC(s32 msg, s32 arg1);
void fn_800292BC(void);
void fn_80025C34(void (*fn)(void), s32 arg1, s32 arg2);

typedef struct Unk80301388Entry {
    /* 0x0 */ u32 flags;
    /* 0x4 */ u16 id;
    /* 0x6 */ u8 pad6[0x10 - 0x6];
} Unk80301388Entry;

typedef struct Unk80301388 {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ Unk80301388Entry* entries;
    /* 0x28 */ u8 pad28;
    /* 0x29 */ u8 count;
} Unk80301388;

extern Unk80301388 lbl_80301388;

static inline s32 ParseKey(s32 key) {
    char* str = fn_80027394(key);

    if (str != NULL) {
        return fn_80177360(str, NULL, 10);
    }
    return 0;
}

static inline u32 FreeBlocks(void) {
    u32 n;
    s32 ret;

    if (lbl_80301320.state->cur == 0x10) {
        ret = fn_8024CB74(&n);
        if (ret < 0 && fn_8024BD64(ret) != 0x31D2B) {
            lbl_80301320.unk29 = 5;
            lbl_80301320.unk2C = fn_8024BD64(ret);
            fn_80025860();
            lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
            return 0;
        }
        return n;
    }
    return 0;
}

static inline BOOL Exists(u8 id) {
    s32 i;
    s32 cnt = lbl_80301388.count;
    Unk80301388Entry* e = lbl_80301388.entries;

    for (i = 0; i < cnt; i++, e++) {
        if (id == e->id && (e->flags & 2) == 2) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL fn_80026908(void) {
    BOOL found = FALSE;
    u32 need;
    s32 extra;
    u32 b;
    u32 a;
    Unk80301320State* st;
    u8* blk;
    u32 n;
    u32 i;

    if (lbl_80301320.state->cur == 0x10) {
        if (lbl_80301320.state->unk17 != 1) {
            return FALSE;
        }
        need = fn_800265F4(0);
        extra = ParseKey(0xD);
        fn_8024D950(1, &a, &b);
        if (!fn_800275B4(need, extra + b)) {
            return FALSE;
        }
        extra = ParseKey(7);
        if (extra > FreeBlocks()) {
            fn_800254AC(0x10, 0);
            lbl_80301320.unk29 = 5;
            lbl_80301320.cb(3, 0, lbl_80301320.cbArg);
            return FALSE;
        }
        i = 0;
        st = lbl_80301320.state;
        blk = st->blocks + st->unk15 * 0x30;
        n = *(u32*)(blk + 0x28);
        if (n != 0) {
            for (; i < n; i++) {
                if (Exists((*(u16**)(blk + 0x24))[i])) {
                    found = TRUE;
                }
            }
        }
        if (found) {
            return FALSE;
        }
        st->progress = 0;
        lbl_80301320.state->prev = lbl_80301320.state->cur;
        lbl_80301320.state->cur = 0x11;
        fn_80025C34(fn_800292BC, 0, 0);
        return TRUE;
    }
    return FALSE;
}
