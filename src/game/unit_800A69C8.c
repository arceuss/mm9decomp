#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
    /* 0x3008 */ u8 pad3008[0x3028 - 0x3008];
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;

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

extern char lbl_8027E1F4[];

void fn_800AA554(char* name, u16 arg1, void* dst);
void fn_800AA9A4(void);

void fn_800A69C8(void) {
    fn_800AA554(lbl_8027E1F4, 0xFFFF, lbl_80316D78.unk3004 + 0xC28000);
    fn_800AA9A4();
    lbl_8037C3D8.unk0 = 0;
    lbl_8037C3D8.unk5 = 0;
}
