#include "types.h"

typedef struct Unk803BB320 {
    /* 0x00 */ u32 base;
    /* 0x04 */ u32 cur;
    /* 0x08 */ u32 size;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10[4];
    /* 0x20 */ u32 unk20[4];
    /* 0x30 */ u32 unk30[4];
    /* 0x40 */ u32 unk40;
    /* 0x44 */ u32 unk44;
    /* 0x48 */ u32 unk48[4];
} Unk803BB320;

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x269C];
    /* 0x269C */ u32 unk269C[4];
    /* 0x26AC */ u32 unk26AC[4];
} Unk8038B2F8;

extern Unk803BB320 lbl_803BB320;
extern Unk8038B2F8 lbl_8038B2F8;
extern u32 lbl_80281E58[];

void fn_800E7E24(s32 id, u32 count, s32 fmt) {
    u32 size;
    u32 cur;

    if (count == 0) {
        lbl_803BB320.unk10[id] = 0;
        lbl_803BB320.unk20[id] = 0;
        lbl_803BB320.unk30[id] = 0;
        return;
    }
    size = lbl_80281E58[fmt] * count;
    cur = lbl_803BB320.cur;
    lbl_803BB320.unk10[id] = cur;
    lbl_8038B2F8.unk269C[id] = cur;
    cur += size;
    lbl_803BB320.cur = cur;
    lbl_803BB320.unk20[id] = count;
    lbl_8038B2F8.unk26AC[id] = size;
    lbl_803BB320.unk30[id] = fmt;
}
