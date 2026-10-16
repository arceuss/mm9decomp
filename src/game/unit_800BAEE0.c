#include "types.h"

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x2388];
    /* 0x2388 */ void* bankA[0x40];
    /* 0x2488 */ void* bankB[0x20];
    /* 0x2508 */ u16 addrA[0x40];
    /* 0x2588 */ u16 addrB[0x20];
    /* 0x25C8 */ u16 sizeA[0x40];
    /* 0x2648 */ u16 sizeB[0x20];
    /* 0x2688 */ u8 pad2688[0x26C0 - 0x2688];
} Unk8038B2F8;

extern Unk8038B2F8 lbl_8038B2F8;

void fn_800BAEE0(u32 addr) {
    u32 i;

    if (addr >= 0x20000000) {
        i = (addr >> 9) & 0x1F;
        lbl_8038B2F8.bankB[i] = NULL;
        lbl_8038B2F8.sizeB[i] = 0;
    } else if (addr >= 0x10000000) {
        i = (addr >> 9) & 0x3F;
        lbl_8038B2F8.bankA[i] = NULL;
        lbl_8038B2F8.sizeA[i] = 0;
    }
}
