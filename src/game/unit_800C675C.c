#include "game/work_8038DC58.h"

extern u8 lbl_8027F518[];
extern u8 (*lbl_8027F450[])(void);
extern u8 lbl_803140C0[];
extern u8 lbl_80304B90[];

void fn_800E5598(void* p);

s32 fn_800C675C(u32 mask) {
    s32 found = 0;
    s32 i;

    if (lbl_803140C0[0x227C] != 0) {
        return 0;
    }
    if (mask == 0x20 && (*(u32*)(lbl_80304B90 + 0x2D8) & 1)) {
        return 0;
    }
    for (i = 0; i < 0x32; i++) {
        if (lbl_8027F518[i] & mask) {
            if (!(lbl_8038DC58.unk90[i >> 3] & (1 << (i & 7)))) {
                if (lbl_8027F450[i]()) {
                    found = 1;
                    lbl_8038DC58.unk90[i >> 3] |= 1 << (i & 7);
                    if (i == 0x24 && mask == 8) {
                        lbl_8038DC58.unk2 = 1;
                    }
                }
            }
        }
    }
    if (found) {
        fn_800E5598(&lbl_8038DC58.unk90);
        if (lbl_8038DC58.unk0 == 0xFF) {
            lbl_8038DC58.unk0 = 0;
        }
    }
    return found;
}
