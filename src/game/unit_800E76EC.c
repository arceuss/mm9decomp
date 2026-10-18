#include "types.h"

typedef struct Unk800E76ECMode {
    /* 0x00 */ u32 data[0x3C / 4];
} Unk800E76ECMode;

extern Unk800E76ECMode lbl_80295B90;
extern Unk800E76ECMode lbl_80295BCC;
extern Unk800E76ECMode lbl_80295C08;
extern Unk800E76ECMode lbl_80295C44;
extern u8 lbl_804EE898[8];

u32 fn_80107348(void);
u32 VIGetTvFormat(void);

s32 fn_800E76EC(Unk800E76ECMode* mode) {
    s32 r = 0;

    if (fn_80107348() == 2) {
        r = 100;
    }
    switch (VIGetTvFormat()) {
    case 1:
        if (lbl_804EE898[1] != 1) {
            *mode = lbl_80295C08;
            break;
        }
    case 5:
        *mode = lbl_80295C44;
        break;
    case 2:
        *mode = lbl_80295BCC;
        break;
    default:
        *mode = lbl_80295B90;
        break;
    }
    return r;
}
