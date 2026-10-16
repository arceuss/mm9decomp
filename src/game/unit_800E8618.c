#include "types.h"

typedef struct Unk8043CA80Entry {
    /* 0x0 */ u32 kind : 2;
    /* 0x0 */ u32 size : 30;
    /* 0x4 */ void* dst;
    /* 0x8 */ void* src;
} Unk8043CA80Entry;

typedef struct Unk8043CA80 {
    /* 0x000 */ s32 count;
    /* 0x004 */ Unk8043CA80Entry entries[0x30];
    /* 0x244 */ u8 pad244[0x258 - 0x244];
    /* 0x258 */ u8* unk258[2];
    /* 0x260 */ u32 unk260[2];
} Unk8043CA80;

extern Unk8043CA80 lbl_8043CA80;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
    /* 0x3008 */ u8 pad3008[0x3028 - 0x3008];
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;

typedef struct Unk8043CCE8 {
    /* 0x00 */ u8* unk0[2];
    /* 0x08 */ u32 unk8[2];
    /* 0x10 */ u8* unk10[2];
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
} Unk8043CCE8;

extern Unk8043CCE8 lbl_8043CCE8;

void fn_800E8204(void);

void fn_800E8618(void) {
    u8* base = lbl_80316D78.unk3004 + 0x980000;
    u8* second = base + 0x40000;

    lbl_8043CCE8.unk10[0] = base;
    lbl_8043CCE8.unk18 = 0x80000;
    lbl_8043CCE8.unk0[0] = base;
    lbl_8043CCE8.unk8[0] = 0x40000;
    lbl_8043CA80.unk258[0] = base;
    lbl_8043CA80.unk260[0] = 0x40000;
    lbl_8043CCE8.unk0[1] = second;
    lbl_8043CCE8.unk8[1] = 0x40000;
    lbl_8043CCE8.unk10[1] = second + 0x40000;
    lbl_8043CA80.unk258[1] = second;
    lbl_8043CA80.unk260[1] = 0x40000;
    fn_800E8204();
}
