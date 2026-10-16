#include "game/work_802BDCC0.h"

extern u8 lbl_804EE958;
extern u8 lbl_8038E280[0x124];

void fn_8000D664(s32 arg0, void* data, s32 size);

void fn_800E5204(void) {
    s16 value;

    if (lbl_804EE958 != 0) {
        if (lbl_802BDCC0.unkF0AA == 2) {
            value = 0;
        } else {
            value = lbl_802BDCC0.unkF0BC;
        }
        if (value != 0) {
            fn_8000D664(8, lbl_8038E280, sizeof(lbl_8038E280));
            lbl_804EE958 = 0;
        }
    }
}
