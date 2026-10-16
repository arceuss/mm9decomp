#include "types.h"

typedef struct Unk800D7BF8 {
    /* 0x00 */ u8 pad0[0x15];
    /* 0x15 */ u8 unk15;
} Unk800D7BF8;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x21E0];
    /* 0x21E0 */ u8 unk21E0;
    /* 0x21E1 */ u8 pad21E1[0x2247 - 0x21E1];
    /* 0x2247 */ u8 unk2247;
    /* 0x2248 */ u8 pad2248[0x224D - 0x2248];
    /* 0x224D */ u8 unk224D;
    /* 0x224E */ u8 unk224E;
    /* 0x224F */ u8 unk224F;
    /* 0x2250 */ u8 unk2250;
    /* 0x2251 */ u8 unk2251;
    /* 0x2252 */ u8 unk2252;
    /* 0x2253 */ u8 pad2253[0x2298 - 0x2253];
} Unk803140C0;

extern Unk803140C0 lbl_803140C0;

BOOL fn_800D7BF8(Unk800D7BF8* obj) {
    Unk803140C0* work = &lbl_803140C0;
    BOOL result = FALSE;

    switch (obj->unk15) {
    case 0:
        if (work->unk21E0 == 9) {
            result = TRUE;
        }
        break;
    case 1:
        if (work->unk224D == 9) {
            result = TRUE;
        }
        break;
    case 2:
        if (work->unk224E == 1) {
            result = TRUE;
        }
        break;
    case 3:
        if (work->unk224F == 1) {
            result = TRUE;
        }
        break;
    case 4:
        if (work->unk2250 == 3) {
            result = TRUE;
        }
        break;
    case 5:
        if (work->unk2247 & 0x80) {
            result = TRUE;
        }
        break;
    case 6:
        if (work->unk2251 == 1) {
            result = TRUE;
        }
        break;
    case 7:
        if (work->unk2252 == 3) {
            result = TRUE;
        }
        break;
    }
    return result;
}
