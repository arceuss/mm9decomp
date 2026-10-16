#include "types.h"

typedef struct Unk8037C3D8 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 pad1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x50 - 0xA];
} Unk8037C3D8;

extern Unk8037C3D8 lbl_8037C3D8;

BOOL fn_800A7084(u8 arg0, u16 arg1, u8 arg2, u8 arg3, u8 arg4) {
    if (lbl_8037C3D8.unk0 == 0 && lbl_8037C3D8.unk5 == 0) {
        lbl_8037C3D8.unk2 = arg0;
        lbl_8037C3D8.unk6 = arg1;
        lbl_8037C3D8.unk3 = arg2;
        lbl_8037C3D8.unk8 = arg3;
        lbl_8037C3D8.unk9 = arg4;
        lbl_8037C3D8.unk0 = 1;
        return TRUE;
    }
    return TRUE;
}
