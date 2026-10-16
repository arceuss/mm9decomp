#include "types.h"

extern u8 lbl_804ECE50[4];
extern u32 lbl_8027EB60[];

void fn_800B9F74(u8* obj, u32 v);

int fn_800B2948(u8* obj) {
    if (((1 << obj[0x11]) & 0xF) && obj[0xF2] == 3) {
        u8 t1 = obj[0xF2];
        u8 t2 = obj[0xF3];
        u8 t3 = obj[0xF4];

        obj[0xF2] = obj[0xEF];
        obj[0xEF] = t1;
        obj[0xF3] = obj[0xF0];
        obj[0xF0] = t2;
        obj[0xF4] = obj[0xF1];
        obj[0xF1] = t3;
        obj[0xFC] = lbl_804ECE50[obj[0xF5]];
        fn_800B9F74(obj, *(u32*)(lbl_8027EB60[obj[9]] + lbl_804ECE50[obj[0xF5]] * 4));
        return 3;
    }
    obj[0xF2] = obj[0xEF];
    obj[0xEF] = 1;
    obj[0xF3] = obj[0xF0];
    obj[0xF0] = 0;
    obj[0xF4] = obj[0xF1];
    obj[0xF1] = 0;
    return 1;
}
