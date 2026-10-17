#include "types.h"

typedef struct Unk800A5678Work {
    /* 0x0000 */ u32 unk0;
    /* 0x0004 */ u32 unk4;
    /* 0x0008 */ u8 pad08[0x3C08 - 0x8];
    /* 0x3C08 */ u8 unk3C08[0xC];
    /* 0x3C14 */ u32 unk3C14;
    /* 0x3C18 */ u8 pad3C18[0x3C28 - 0x3C18];
    /* 0x3C28 */ u8 unk3C28[0x20];
    /* 0x3C48 */ u8 pad3C48[0x83A8 - 0x3C48];
    /* 0x83A8 */ u8 unk83A8[1];
    /* 0x83A9 */ u8 pad83A9[0xEFA8 - 0x83A9];
    /* 0xEFA8 */ u32 unkEFA8;
    /* 0xEFAC */ u32 unkEFAC[2];
    /* 0xEFB4 */ u32 unkEFB4[2];
    /* 0xEFBC */ u8 unkEFBC;
    /* 0xEFBD */ u8 padEFBD[0xEFDC - 0xEFBD];
    /* 0xEFDC */ u32 unkEFDC;
} Unk800A5678Work;

typedef struct Unk800A5678Header {
    /* 0x0 */ u16 size;
    /* 0x2 */ u16 offset;
} Unk800A5678Header;

extern Unk800A5678Work lbl_8036CF50;
extern u32 lbl_8027E178[];
extern u8 lbl_8027E19C[];

void fn_800A60C0(u32 arg);
void fn_800AA9AC(u32 id, void* dst, u32 size, u32 offset);

void fn_800A5678(void) {
    Unk800A5678Header header;
    u32 name;

    lbl_8036CF50.unk4 = 8;
    fn_800A60C0(8);
    name = (u32)lbl_8027E19C;
    fn_800AA9AC(name, lbl_8036CF50.unk3C08, 0x20, 0);
    fn_800AA9AC(name, lbl_8036CF50.unk3C28, lbl_8036CF50.unk3C14, 0x20);
    fn_800AA9AC(lbl_8027E178[lbl_8036CF50.unk0], &header, 4, 0);
    fn_800AA9AC(lbl_8027E178[lbl_8036CF50.unk0], lbl_8036CF50.unk83A8, header.size, 4);
    lbl_8036CF50.unkEFA8 = 0xFFFFFFFF;
    lbl_8036CF50.unkEFAC[0] = (u32)lbl_8036CF50.unk83A8;
    lbl_8036CF50.unkEFB4[0] = (u32)lbl_8036CF50.unk83A8 + header.offset;
    lbl_8036CF50.unkEFBC = 0xFF;
    lbl_8036CF50.unkEFDC = (u32)&lbl_8036CF50.unkEFDC;
}
