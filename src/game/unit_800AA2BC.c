#include "types.h"

typedef struct Unk80383E70 {
    /* 0x0000 */ u32 unk0;
    /* 0x0004 */ u8 unk4[0x800];
    /* 0x0804 */ u8 unk804[0x800];
    /* 0x1004 */ u8 pad1004[0x2014 - 0x1004];
    /* 0x2014 */ void* unk2014;
    /* 0x2018 */ u8 unk2018[0x2028 - 0x2018];
    /* 0x2028 */ s32 unk2028;
    /* 0x202C */ u32 unk202C;
    /* 0x2030 */ u8 pad2030[0x7480 - 0x2030];
    /* 0x7480 */ s32 unk7480;
    /* 0x7484 */ u8 pad7484[0x7488 - 0x7484];
} Unk80383E70;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u32 unk3004;
    /* 0x3008 */ u32 unk3008;
    /* 0x300C */ u8 pad300C[0x3028 - 0x300C];
} Unk80316D78;

extern Unk80383E70 lbl_80383E70;
extern Unk80316D78 lbl_80316D78;

void fn_8009C04C(u32 fill, void* dst, u32 size);
void* fn_80115EA8(u32 start, u32 size, s32 arg2);
void fn_801165C4(void* arg0, void* heap, s32 arg2);
void fn_801E263C(s32 arg0, void* arg1, void* arg2);
void fn_800AB27C(void);
void fn_800AAFB0(void* arg0, s32 arg1);
void fn_801E2648(void* arg0);
void fn_800AAD68(void);

void fn_800AA2BC(void) {
    u8 buf[0x30];
    void* heap;

    fn_8009C04C(0, lbl_80383E70.unk4, 0x800);
    fn_8009C04C(0, lbl_80383E70.unk804, 0x800);
    heap = fn_80115EA8(lbl_80316D78.unk3004 + 0xA10000, 0x10000, 0);
    lbl_80383E70.unk2014 = heap;
    fn_801165C4(lbl_80383E70.unk2018, heap, 0x20);
    lbl_80383E70.unk2028 = 0;
    lbl_80383E70.unk202C = lbl_80316D78.unk3008 + 0x19000;
    fn_801E263C(2, buf, lbl_80383E70.unk2018);
    fn_800AB27C();
    fn_800AAFB0(buf, 0);
    fn_801E2648(buf);
    fn_800AB27C();
    lbl_80383E70.unk7480 = 0;
    fn_800AAD68();
}
