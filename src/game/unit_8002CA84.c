#include "types.h"

extern u8 lbl_803013C0[];

static inline void inc281(u8* obj, u8* count) {
    u8 t;
    u8 t2;

    t = obj[0x281];
    *count += 1;
    obj[0x281] = t + 1;
    if ((u8)(t + 1) >= 5) {
        t2 = obj[0x282];
        obj[0x281] = 0;
        obj[0x282] = t2 + 1;
    }
}

void fn_8002CA84(u8* obj) {
    u32 i;
    u8 count;

    count = 0;
    for (i = 0; i < 25; i++) {
        if (*(u8*)(lbl_803013C0 + i) == 1) {
            inc281(obj, &count);
        }
        if (*(u8*)(lbl_803013C0 + i + 1) == 1) {
            inc281(obj, &count);
        }
        i++;
    }
    *(u8*)(obj + 0x281) = (*(u8*)(obj + 0x281) * 2) & 0x7F;
    if ((count & 0xFF) == 50) {
        *(u8*)(obj + 0x282) = count;
    }
}
