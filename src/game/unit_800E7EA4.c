#include "types.h"

typedef struct Unk800E7EA4Region {
    /* 0x0 */ u32 unk0[4];
} Unk800E7EA4Region;

typedef struct Unk803BB320 {
    /* 0x00 */ u32 base;
    /* 0x04 */ u32 cur;
    /* 0x08 */ u32 size;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10[4];
    /* 0x20 */ u32 counts[4];
    /* 0x30 */ u32 fmts[4];
    /* 0x40 */ u32 used;
    /* 0x44 */ u32 addr;
    /* 0x48 */ u32 first[4];
    /* 0x58 */ Unk800E7EA4Region regions[1];
} Unk803BB320;

extern Unk803BB320 lbl_803BB320;
extern u32 lbl_80281E58[];
extern u32 lbl_80281E84[];

void fn_800E800C(void);
void* fn_80113204(void (*fn)(void));
void GXInitTlutRegion(void* region, u32 addr, u32 size);

void fn_800E7EA4(void) {
    u32 j;
    u32 i;
    u32 idx;
    u32 size;
    u32 n;
    u32 fmt;
    Unk800E7EA4Region* region;

    fn_80113204(fn_800E800C);
    lbl_803BB320.used = 0;
    lbl_803BB320.addr = 0;
    for (i = 0; i < 4; i++) {
        n = lbl_803BB320.counts[i];
        if (n == 0) {
            lbl_803BB320.first[i] = 0;
            continue;
        }
        fmt = lbl_803BB320.fmts[i];
        idx = lbl_803BB320.used;
        size = (lbl_80281E58[fmt] + 0x1FF) & ~0x1FF;
        region = &lbl_803BB320.regions[idx];
        lbl_803BB320.addr = (size + lbl_803BB320.addr - 1) & ~(size - 1);
        lbl_803BB320.first[i] = idx;
        for (j = 0; j < n; j++) {
            GXInitTlutRegion(region, lbl_803BB320.addr + 0xC0000, lbl_80281E84[fmt]);
            region++;
            idx++;
            lbl_803BB320.addr += size;
        }
        lbl_803BB320.used = idx;
    }
}
