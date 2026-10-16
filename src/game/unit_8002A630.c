#include "types.h"

typedef struct Unk80301320Sub {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 prevState;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ void* unk4;
    /* 0x08 */ void* unk8;
    /* 0x0C */ u8 padC[0x18 - 0xC];
    /* 0x18 */ void (*unk18)(void);
    /* 0x1C */ u8 pad1C[0x22 - 0x1C];
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u8 unk24[0x28 - 0x24];
    /* 0x28 */ s32 unk28;
} Unk80301320Sub;

typedef struct Unk80301320 {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 prevState;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ u32 flags;
    /* 0x08 */ u8 pad8[0x29 - 0x8];
    /* 0x29 */ u8 errorKind;
    /* 0x2A */ u8 pad2A[0x2C - 0x2A];
    /* 0x2C */ s32 errorCode;
    /* 0x30 */ u8 pad30[0x5C - 0x30];
    /* 0x5C */ Unk80301320Sub* sub;
    /* 0x60 */ void (*callback)(s32 event, s32 arg, void* user);
    /* 0x64 */ void* user;
} Unk80301320;

extern Unk80301320 lbl_80301320;

void fn_80025860(void);

typedef struct Unk8002A630Stat {
    /* 0x00 */ s32 v[5];
} Unk8002A630Stat;

typedef struct Unk8002A630Pair {
    /* 0x00 */ Unk8002A630Stat a;
    /* 0x14 */ Unk8002A630Stat b;
} Unk8002A630Pair;

void fn_801FB4A0(Unk8002A630Stat* a, Unk8002A630Stat* b);

s32 fn_8002A630(Unk8002A630Pair* base, s32 which) {
    Unk8002A630Stat b;
    Unk8002A630Stat a;
    s32 diff = 0;

    if (lbl_80301320.flags & 0x10) {
        fn_801FB4A0(&a, &b);
    }
    switch (which) {
    case 0:
        diff = b.v[0] - base->b.v[0];
        break;
    case 1:
        diff = b.v[1] - base->b.v[1];
        break;
    case 2:
        diff = b.v[2] - base->b.v[2];
        break;
    case 3:
        diff = b.v[3] - base->b.v[3];
        break;
    case 4:
        diff = b.v[3] - base->b.v[4];
        break;
    }
    return diff;
}
