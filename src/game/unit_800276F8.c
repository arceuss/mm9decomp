#include "types.h"

typedef struct Unk80301388 {
    /* 0x00 */ u8 mutex[0x18];
    /* 0x18 */ void* heap;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ void* unk20;
    /* 0x24 */ void* unk24;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u16 flags;
    /* 0x2C */ void* unk2C;
    /* 0x30 */ void* unk30;
    /* 0x34 */ u32 pad34;
} Unk80301388;

extern Unk80301388 lbl_80301388;

void* memcpy(void* dst, const void* src, u32 n);
void OSLockMutex(void* mutex);
void fn_80116038(void* heap, void* block);
void OSUnlockMutex(void* mutex);
void fn_8002541C(void* block);
void* fn_80115F88(void* heap, u32 size, u32 align);
void* fn_800253B0(u32 size, u32 align);
s32 fn_8024CC30(void* dst, s32* count);

int fn_800276F8(u8* src, s32 count) {
    s32 n;
    s32 size;
    void* block;
    u32 i;
    s32 j;
    u8* table;
    u8* out;

    block = lbl_80301388.unk20;
    if (block != 0) {
        if (!(lbl_80301388.flags & 1)) {
            OSLockMutex(&lbl_80301388);
            fn_80116038(lbl_80301388.heap, block);
            OSUnlockMutex(&lbl_80301388);
        } else {
            fn_8002541C(block);
        }
        lbl_80301388.unk20 = 0;
    }
    lbl_80301388.unk1C = 0;
    if (fn_8024CC30(0, &n) < 0) {
        return 0;
    }
    if (!(lbl_80301388.flags & 1)) {
        OSLockMutex(&lbl_80301388);
        out = fn_80115F88(lbl_80301388.heap, count * 0x18, 0x20);
        OSUnlockMutex(&lbl_80301388);
    } else {
        out = fn_800253B0(count * 0x18, 0x20);
    }
    lbl_80301388.unk20 = out;
    lbl_80301388.unk28 = count;
    if (out == 0) {
        return 0;
    }
    size = n * 0x18;
    if (!(lbl_80301388.flags & 1)) {
        OSLockMutex(&lbl_80301388);
        table = fn_80115F88(lbl_80301388.heap, size, 0x20);
        OSUnlockMutex(&lbl_80301388);
    } else {
        table = fn_800253B0(size, 0x20);
    }
    if (table == 0) {
        block = lbl_80301388.unk20;
        if (!(lbl_80301388.flags & 1)) {
            OSLockMutex(&lbl_80301388);
            fn_80116038(lbl_80301388.heap, block);
            OSUnlockMutex(&lbl_80301388);
        } else {
            fn_8002541C(block);
        }
        lbl_80301388.unk20 = 0;
        lbl_80301388.unk28 = 0;
        return 0;
    }
    if (fn_8024CC30(table, &n) < 0) {
        if (!(lbl_80301388.flags & 1)) {
            OSLockMutex(&lbl_80301388);
            fn_80116038(lbl_80301388.heap, table);
            OSUnlockMutex(&lbl_80301388);
        } else {
            fn_8002541C(table);
        }
        block = lbl_80301388.unk20;
        if (!(lbl_80301388.flags & 1)) {
            OSLockMutex(&lbl_80301388);
            fn_80116038(lbl_80301388.heap, block);
            OSUnlockMutex(&lbl_80301388);
        } else {
            fn_8002541C(block);
        }
        lbl_80301388.unk20 = 0;
        lbl_80301388.unk28 = 0;
        return 0;
    }
    for (i = 0; i < (u32)n; i++) {
        for (j = 0; j < count; j++) {
            if (*(u64*)(table + i * 0x18) == *(u64*)(src + j * 8)) {
                memcpy(out + j * 0x18, table + i * 0x18, 0x18);
                lbl_80301388.unk1C |= 1 << j;
            }
        }
    }
    if (!(lbl_80301388.flags & 1)) {
        OSLockMutex(&lbl_80301388);
        fn_80116038(lbl_80301388.heap, table);
        OSUnlockMutex(&lbl_80301388);
    } else {
        fn_8002541C(table);
    }
    return 1;
}
