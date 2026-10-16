#include "game/work_8038DC58.h"

u32 fn_800B5BE4(void* work);
u32 fn_800B5B6C(void* work);
void fn_800C675C(s32 arg);

void fn_800C7994(void* work, u8 kind) {
    if (kind <= 1) {
        lbl_8038DC58.unkC[0] |= 0x80;
    }
    if (kind == 7 || kind == 8) {
        if (fn_800B5BE4(work) >= 999) {
            lbl_8038DC58.unkC[0x13 - 0xC] |= 0x20;
        }
    }
    if (kind == 4) {
        if (fn_800B5B6C(work) >= 9) {
            lbl_8038DC58.unkC[0x15 - 0xC] |= 2;
        }
    }
    fn_800C675C(4);
}
