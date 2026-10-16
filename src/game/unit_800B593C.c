#include "types.h"
#include "game/sound.h"

void fn_800D5234(s32 arg);

s32 fn_800B593C(u8* obj, s32 d) {
    s32 cur = *(s16*)(obj + 0xB6);
    s32 v = cur + d;

    if (v > 0x1C) {
        v = 0x1C;
    }
    *(s16*)(obj + 0xB8) = v;
    *(s16*)(obj + 0xB6) = v;
    if (cur != v) {
        fn_800D5234(SE_GAGE);
    }
    return 0x1C - v;
}
