#include "types.h"

typedef struct Unk80301388 {
    /* 0x00 */ u8 mutex[0x18];
    /* 0x18 */ void* heap;
    /* 0x1C */ u8 pad1C[0x24 - 0x1C];
    /* 0x24 */ void* buf;
    /* 0x28 */ u8 pad28;
    /* 0x29 */ u8 count;
    /* 0x2A */ u16 flags;
} Unk80301388;

extern Unk80301388 lbl_80301388;

void OSLockMutex(void* mutex);
void OSUnlockMutex(void* mutex);
void fn_80116038(void* heap, void* p);
void* fn_80115F88(void* heap, u32 size, s32 align);
void fn_8002541C(void* p);
void* fn_800253B0(u32 size, s32 align);
s32 fn_8024D424(void* arg0, void* arg1, void* buf, u32* count);

static inline void Free(void* p) {
    if (!(lbl_80301388.flags & 1)) {
        OSLockMutex(&lbl_80301388);
        fn_80116038(lbl_80301388.heap, p);
        OSUnlockMutex(&lbl_80301388);
    } else {
        fn_8002541C(p);
    }
}

static inline void* Alloc(u32 size) {
    void* p;

    if (!(lbl_80301388.flags & 1)) {
        OSLockMutex(&lbl_80301388);
        p = fn_80115F88(lbl_80301388.heap, size, 0x20);
        OSUnlockMutex(&lbl_80301388);
    } else {
        p = fn_800253B0(size, 0x20);
    }
    return p;
}

BOOL fn_80027A38(void* arg0, void* arg1) {
    u32 count;
    void* p;

    p = lbl_80301388.buf;
    if (p != NULL) {
        Free(p);
        lbl_80301388.buf = NULL;
    }
    if (fn_8024D424(arg0, arg1, NULL, &count) < 0) {
        return FALSE;
    }
    lbl_80301388.buf = Alloc(count * 16);
    if (lbl_80301388.buf == NULL) {
        return FALSE;
    }
    lbl_80301388.count = count;
    if (fn_8024D424(arg0, arg1, lbl_80301388.buf, &count) < 0) {
        Free(lbl_80301388.buf);
        lbl_80301388.buf = NULL;
        lbl_80301388.count = 0;
        return FALSE;
    }
    return TRUE;
}
