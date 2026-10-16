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

void fn_800A7200(void);

void fn_800A70D0(void) {
    if (lbl_8037C3D8.unk0 != 0 || lbl_8037C3D8.unk5 != 0) {
        fn_800A7200();
    }
}
