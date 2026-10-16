#include "types.h"

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;

void fn_800999E8(u8* a, u8* p, u32 v);

void fn_800B67F8(u8* obj) {
    u8* p;
    u8 v;

    obj[0x114] = 0;
    if (!(*(u32*)(obj + 0xA0) & 0x400)) {
        obj[0x117] = 0;
        obj[0xFD] = 0xFF;
    }
    obj[0x118] = obj[0x118] & -10;
    if (*(u32*)(obj + 0x104) & 0x200) {
        p = 0;
        v = 0;
    } else {
        if (!(obj[0x116] & ~1)) {
            p = *(u8**)(obj + 0x13C) + 0x18;
        } else {
            p = *(u8**)(obj + 0x13C);
        }
        v = p[9];
        if (lbl_803051D8.unk2 & 8) {
            v |= 0x40;
        }
        if (obj[9] == 1) {
            v |= 0x80;
        }
        if (obj[9] == 2) {
            v |= 0x80;
        }
    }
    fn_800999E8(obj + 0x88, p, v);
}
