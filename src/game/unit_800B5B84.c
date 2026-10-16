#include "types.h"
#include "game/sound.h"

extern u8 lbl_803051D8[];

void fn_800D5234(s32 arg);

s32 fn_800B5B84(u8* obj, s32 d) {
    s32 cur = *(s32*)(lbl_803051D8 + 0x18);
    s32 v = cur + d;

    if (v > 0x3E7) {
        v = 0x3E7;
    }
    if (cur != v) {
        fn_800D5234(SE_GET_SCREW);
    }
    *(s32*)(lbl_803051D8 + 0x18) = v;
    return v;
}
