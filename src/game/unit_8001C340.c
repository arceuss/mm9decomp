#include "types.h"

typedef struct Unk8001C340 {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0xD8 - 0x13];
    /* 0xD8 */ u8 unkD8;
    /* 0xD9 */ u8 unkD9;
} Unk8001C340;

extern u32 lbl_804EE988;
extern u8 lbl_804EC7A4[4];

void fn_8001C340(Unk8001C340* obj) {
    u32 rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
    u8 v;
    lbl_804EE988 = rnd & 0x7FFFFFFF;
    v = lbl_804EC7A4[(rnd >> 16) & 1];
    if (v == obj->unkD8) {
        if (++obj->unkD9 == 3) {
            while (v == obj->unkD8) {
                rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
                lbl_804EE988 = rnd & 0x7FFFFFFF;
                v = lbl_804EC7A4[(rnd >> 16) & 1];
            }
            obj->unkD9 = 0;
        }
    } else {
        obj->unkD9 = 0;
    }
    obj->unk11 = v;
    obj->unk12 = 0;
    obj->unkD8 = v;
}
