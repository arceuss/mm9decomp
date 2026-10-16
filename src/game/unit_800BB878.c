#include "types.h"

typedef struct Unk8038D9B8Anim {
    /* 0x00 */ u8* pal;
    /* 0x04 */ u16* seq;
    /* 0x08 */ u8 index;
    /* 0x09 */ u8 frame;
    /* 0x0A */ u8 padA[0xB - 0xA];
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ void* dst;
    /* 0x14 */ u16 stopped;
    /* 0x16 */ u8 pad16[0x18 - 0x16];
} Unk8038D9B8Anim;

typedef struct Unk8038D9B8 {
    /* 0x000 */ u32 active[24];
    /* 0x060 */ Unk8038D9B8Anim anims[24];
} Unk8038D9B8;

extern Unk8038D9B8 lbl_8038D9B8;

void fn_800BB878(s32 key, void* dst) {
    s32 i;

    for (i = 0; i < 24; i++) {
        if (key + 1 == lbl_8038D9B8.active[i]) {
            break;
        }
    }
    if (i != 24) {
        lbl_8038D9B8.anims[i].dst = dst;
    }
}
