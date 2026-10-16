#include "types.h"

typedef struct Unk80316D28 {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 pad2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 pad4[0x10 - 0x4];
} Unk80316D28;

extern Unk80316D28 lbl_80316D28;

void fn_80099650(void);
void fn_801B9B58(void);
void fn_8009BC4C(u8 alpha);

void fn_8009B6FC(void) {
    s32 t;

    if (lbl_80316D28.unk3 != 0) {
        fn_80099650();
        fn_801B9B58();
        return;
    }
    t = lbl_80316D28.unk1;
    if (t == 0) {
        return;
    }
    if (t < 15) {
        t *= 255;
        t /= 15;
    } else if (t < 75) {
        t = 255;
    } else {
        t = 90 - t;
        t *= 255;
        t /= 15;
    }
    fn_8009BC4C(t);
}
