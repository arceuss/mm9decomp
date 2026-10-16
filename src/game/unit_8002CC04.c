#include "types.h"

typedef struct Unk8002CC04 {
    /* 0x000 */ u8 pad0[0x7];
    /* 0x007 */ u8 unk7;
    /* 0x008 */ u8 pad8[0x36C - 0x8];
    /* 0x36C */ u8* bits;
} Unk8002CC04;

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 pad0[0x90];
    /* 0x90 */ u8 bits[0x128 - 0x90];
} Unk8038DC58;

typedef struct Unk803013C0 {
    /* 0x00 */ u8 flags[0x34];
} Unk803013C0;

extern Unk803013C0 lbl_803013C0;
extern u8 lbl_80263EB0[0x32];
extern Unk8038DC58 lbl_8038DC58;

void fn_8002CC04(Unk8002CC04* obj) {
    u8 i;

    for (i = 0; i < 0x32; i++) {
        lbl_803013C0.flags[i] = 0;
    }
    for (i = 0; i < 0x32; i++) {
        if (obj->unk7 == 0) {
            if (lbl_8038DC58.bits[lbl_80263EB0[i] >> 3] & (1 << (lbl_80263EB0[i] & 7))) {
                lbl_803013C0.flags[i] = 1;
            }
        } else if (obj->bits[lbl_80263EB0[i] >> 3] & (1 << (lbl_80263EB0[i] & 7))) {
            lbl_803013C0.flags[i] = 1;
        }
    }
}
