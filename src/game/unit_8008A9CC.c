#include "types.h"

typedef struct Unk8008A9CC {
    /* 0x0000 */ u8 pad0[0x2];
    /* 0x0002 */ u8 unk2;
    /* 0x0003 */ u8 pad3[0x21E0 - 0x3];
    /* 0x21E0 */ u8 unk21E0;
    /* 0x21E1 */ u8 pad21E1[0x2244 - 0x21E1];
    /* 0x2244 */ u8 unk2244[0x227C - 0x2244];
    /* 0x227C */ u8 unk227C;
    /* 0x227D */ u8 pad227D[0x2290 - 0x227D];
    /* 0x2290 */ void* unk2290;
    /* 0x2294 */ u8 pad2294[0x2298 - 0x2294];
} Unk8008A9CC;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x38 - 0x4];
} Unk803051D8;

typedef struct Unk8038DC58 {
    /* 0x0 */ u8 pad0[0xC];
    /* 0xC */ u8 unkC;
} Unk8038DC58;

extern Unk8008A9CC lbl_803140C0;
extern Unk803051D8 lbl_803051D8;
extern Unk8038DC58 lbl_8038DC58;

void fn_800BB244(void);
void fn_8009E75C(void);
void fn_800D432C(void);
s32 fn_800B5B6C(void* player);
void fn_800B5B74(void* player);
void fn_800B5B50(void* player, s32 arg1);
void fn_800B730C(void* player, u8* arg1);
void fn_800833D8(void* arg0);
void fn_8008C07C(Unk8008A9CC* p, s32 arg1);

void fn_8008A9CC(Unk8008A9CC* p) {
    void* player = lbl_803140C0.unk2290;

    if (p->unk2 == 0) {
        fn_800BB244();
        fn_8009E75C();
        fn_800D432C();
        p->unk2++;
    }
    switch (p->unk227C) {
    case 0:
    case 1:
    case 2:
        lbl_803051D8.unk3 &= ~0x20;
        if (fn_800B5B6C(player) == 0) {
            lbl_8038DC58.unkC |= 0x10;
            fn_800B5B74(player);
            fn_8008C07C(p, 0xE00);
        } else {
            fn_800B5B50(player, 1);
            fn_800B730C(player, &p->unk21E0);
            fn_800833D8(p->unk2244);
            fn_8008C07C(p, 0x800);
        }
        break;
    case 3:
        fn_8008C07C(p, 0xE00);
        break;
    case 4:
        fn_8008C07C(p, 0xE00);
        break;
    }
}
