#include "types.h"
#include "game/sound.h"

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[0x18 - 0xB];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x38 - 0x1C];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;

void fn_800D5234(s32 id);

s32 fn_800B5C54(void* p, s32 n) {
    s32 v = lbl_803051D8.unkA + n;

    if (v > 1) {
        v = 1;
    }
    if (lbl_803051D8.unkA != v) {
        fn_800D5234(SE_GET_ITEM);
    }
    lbl_803051D8.unkA = v;
    return v;
}
