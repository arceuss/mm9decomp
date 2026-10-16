#include "types.h"

typedef struct Unk803BB320 {
    /* 0x00 */ u32 base;
    /* 0x04 */ u32 cur;
    /* 0x08 */ u32 size;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u16* src[4];
    /* 0x20 */ u32 counts[4];
    /* 0x30 */ u32 fmts[4];
    /* 0x40 */ u32 used;
    /* 0x44 */ u32 addr;
    /* 0x48 */ u32 first[4];
} Unk803BB320;

typedef struct Unk800E8024Tlut {
    /* 0x0 */ u8 pad0[0xC];
} Unk800E8024Tlut;

extern Unk803BB320 lbl_803BB320;
extern u16 lbl_803BCA80[4][0x100][0x100];

void DCFlushRange(void* addr, u32 size);
void fn_80113018(Unk800E8024Tlut* tlut, void* data, s32 fmt, u16 count);
void fn_80113040(Unk800E8024Tlut* tlut, u32 id);

void fn_800E8024(s32 id) {
    Unk800E8024Tlut tlut;
    u32 n = lbl_803BB320.counts[id];
    u16* src = lbl_803BB320.src[id];
    u32 first = lbl_803BB320.first[id];
    u32 len = 1 << (lbl_803BB320.fmts[id] + 4);
    u32 i;
    u32 j;

    if (n != 0) {
        for (i = 0; i < n; i++) {
            lbl_803BCA80[id][i][0] = 0;
            src++;
            for (j = 1; j < len; j++) {
                lbl_803BCA80[id][i][j] = (*src++ >> 1) | 0x8000;
            }
        }
        DCFlushRange(lbl_803BCA80[id], 0x20000);
        for (i = 0; i < n; i++) {
            fn_80113018(&tlut, lbl_803BCA80[id][i], 2, len);
            fn_80113040(&tlut, first + i);
        }
    }
}
