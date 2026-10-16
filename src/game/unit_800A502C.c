#include "game/work_8031BF70.h"

u16 fn_800A502C(u16 id) {
    u16 i;

    for (i = 0; i < lbl_8031BF70.unk28E; i++) {
        if (id == lbl_8031BF70.unk290[i].id) {
            return i;
        }
    }
    return 0xFFFF;
}
