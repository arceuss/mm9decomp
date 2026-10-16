#include "types.h"

typedef struct Unk8000C864 {
    /* 0x00 */ u32 magic;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 padF;
    /* 0x10 */ u32 unk10;
} Unk8000C864;

extern u32 lbl_804EC670;
extern u32 lbl_804EC678;

BOOL fn_8000C864(u32 arg0, u32 arg1, Unk8000C864* src) {
    Unk8000C864 hdr __attribute__((aligned(64)));

    hdr.magic = lbl_804EC670;
    if (arg0 >= 9) {
        return FALSE;
    }
    hdr = *src;
    if (hdr.magic == lbl_804EC678 && hdr.unk8 == arg1 && hdr.unk10 == 0 && hdr.unkE == arg0) {
        return TRUE;
    }
    return FALSE;
}
