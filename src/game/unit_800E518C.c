#include "game/work_802BDCC0.h"

typedef struct Unk8038E140 {
    /* 0x000 */ u8 data[0x124];
} Unk8038E140;

extern Unk8038E140 lbl_8038E140;
extern Unk8038E140 lbl_8038E280;

s32 fn_800E518C(void) {
    s32 v;

    if (lbl_802BDCC0.unkF0AA == 1) {
        v = 0;
    } else {
        v = lbl_802BDCC0.unkF0BE;
    }
    if (v == 0) {
        return 0;
    }
    if (v > 0) {
        lbl_8038E140 = lbl_8038E280;
    }
    return v;
}
