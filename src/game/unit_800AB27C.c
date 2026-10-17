#include "types.h"

extern u8 lbl_804ECE1C;
extern u8 lbl_804ECE1D;
extern u8 lbl_804ECE1E;
extern u8 lbl_804ECE1F;
extern u32 lbl_8036CF50[];
extern u8 lbl_8026F9B8[];

void OSFatal(void*, void*, void*);

static inline void Fatal(s32 i) {
    u8 fg[4];
    u32 bg = 0;

    fg[0] = lbl_804ECE1C;
    fg[1] = lbl_804ECE1D;
    fg[2] = lbl_804ECE1E;
    fg[3] = lbl_804ECE1F;
    OSFatal(fg, &bg, *(void**)(lbl_8026F9B8 + lbl_8036CF50[0] * 0x24 + i * 4));
}

s32 fn_800AB27C(s32 err) {
    switch (err) {
    case -0x1395:
        Fatal(2);
        break;
    case -0x1393:
        Fatal(0);
        break;
    case -0x1394:
        Fatal(2);
        break;
    case -0x1390:
        Fatal(1);
        break;
    case -0x13C7:
        Fatal(3);
        break;
    default:
        return err;
    case -0x1407:
    case -0x1396:
    case -0x138B:
    case -0x1392:
    case -0x1391:
    case -0x1389:
    case -0x1388:
        break;
    }
    return -1;
}
