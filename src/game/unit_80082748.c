#include "types.h"
typedef struct Unk80082748 {
    /* 0x00 */ u8 pad00[0x28];
    /* 0x28 */ u8* unk28;
    /* 0x2C */ u8 pad2C[0x160];
    /* 0x18C */ u32 unk18C;
} Unk80082748;
extern u8 lbl_8038B2F8[];
s32 fn_80082748(Unk80082748* p) {
    u8* cmd = p->unk28;
    u8 value = cmd[1];
    if (value == 0) {
        if (*(s16*)(cmd + 2) == 0) {
            if (p->unk18C != 0) { p->unk28 -= 8; return 1; }
        } else if (*(s16*)(cmd + 2) == 1) {
            p->unk18C = 0;
            (*(u8**)(lbl_8038B2F8 + 0x184))[0x2500] = 32;
        } else {
            p->unk18C = 0;
            (*(u8**)(lbl_8038B2F8 + 0x184))[0x2500] = *(u32*)(cmd + 4);
        }
    } else {
        p->unk18C = value;
        if (value & 8) *(u16*)(lbl_8038B2F8 + 0x26BC) = 0;
    }
    return 0;
}
