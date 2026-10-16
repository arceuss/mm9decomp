#include "types.h"

typedef struct Unk8036CF50 {
    /* 0x0000 */ u8 pad0[0xEFBC];
    /* 0xEFBC */ u8 name[0xEFE0 - 0xEFBC];
} Unk8036CF50;

extern Unk8036CF50 lbl_8036CF50;

s32 fn_800A5E0C(u8* text) {
    s32 count = 0;
    u32 c;

    for (;;) {
        c = *text;
        switch (c) {
        case 0xF0:
            while (*++text == 0xFF) {
            }
            count++;
            break;
        case 0xF1:
        case 0xF2:
        case 0xF3:
        case 0xF4:
        case 0xF5:
        case 0xF6:
        case 0xF7:
        case 0xF8:
            text++;
            break;
        case 0xF9:
            text += 2;
            break;
        case 0xFA:
            count += fn_800A5E0C(lbl_8036CF50.name);
            break;
        case 0xFB:
        case 0xFC:
            break;
        case 0xFD:
        case 0xFE:
        case 0xFF:
            return count;
        default:
            count++;
            break;
        }
        text++;
    }
}
