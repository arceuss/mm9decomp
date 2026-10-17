#include "types.h"

typedef struct Unk80086CDC {
    /* 0x0000 */ u8 pad0[2];
    /* 0x0002 */ u8 unk2;
    /* 0x0003 */ u8 unk3;
    /* 0x0004 */ u8 pad4[0xFF4 - 0x4];
    /* 0x0FF4 */ u8 unkFF4;
    /* 0x0FF5 */ u8 padFF5[0xFF7 - 0xFF5];
    /* 0x0FF7 */ u8 unkFF7;
    /* 0x0FF8 */ u8* unkFF8;
} Unk80086CDC;

typedef struct Unk80301280Sub {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u8 pad4[0xE - 0x4];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[0x1C - 0x10];
    /* 0x1C */ s32 unk1C;
} Unk80301280Sub;

typedef struct Unk80301280 {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u8 pad4[0x40 - 0x4];
    /* 0x40 */ Unk80301280Sub* unk40;
    /* 0x44 */ u8 pad44[4];
} Unk80301280;

typedef struct Unk8038B2F8Sub {
    /* 0x0000 */ u8 pad0[0x2500];
    /* 0x2500 */ u8 unk2500;
} Unk8038B2F8Sub;

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x184];
    /* 0x0184 */ Unk8038B2F8Sub* unk184;
    /* 0x0188 */ u8 pad188[0x26BC - 0x188];
    /* 0x26BC */ s16 unk26BC;
} Unk8038B2F8;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

typedef struct Unk80383E70 {
    /* 0x0 */ u8* buf;
    /* 0x4 */ u8 pad4[0x7488 - 0x4];
} Unk80383E70;

extern Unk80316D78 lbl_80316D78;
extern Unk8038B2F8 lbl_8038B2F8;
extern Unk80301280 lbl_80301280;
extern Unk80383E70 lbl_80383E70;
extern u8 lbl_80273128[];

s32 fn_800AA554(s32 arg0, u16 arg1, u8* arg2);
void fn_800AA9A4(void);
void fn_800A7860(void);
void fn_800A7E88(void* arg0);
void fn_8000EE80(s32 arg0, s32 arg1, s32 arg2);
s32 fn_8000EF20(s32 arg0);
void fn_800E83A4(void* arg0, s32 arg1);
void fn_800BAF48(void* arg0, s32 arg1);
void fn_8000ECB8(s32 arg0, void* gfx, s32 tile, s32 x, s32 y);
void fn_800BB244(void);
void fn_800E5694(s32 arg0, s32 arg1, s32 arg2);

#define ARC (lbl_80316D78.unk3004 + 0xCD5000)

void fn_80086CDC(Unk80086CDC* obj) {
    u8* p;
    u8* arc;

    p = ARC;
    p = p + fn_800AA554((s32)(lbl_80273128 + 0x1B0), 0xFFFF, p);
    fn_800AA9A4();
    obj->unkFF8 = p;
    p += fn_800AA554((s32)(lbl_80273128 + 0x1BC), 0xFFFF, p);
    fn_800AA9A4();
    fn_800A7860();
    lbl_80383E70.buf = p;
    fn_800A7E88(lbl_80273128 + 0x48);
    lbl_8038B2F8.unk26BC = 0;
    lbl_8038B2F8.unk184->unk2500 = 0;
    lbl_80301280.unk0 = (lbl_80301280.unk0 & ~0x3F000000) | 0x18000000;
    lbl_80301280.unk40->flags &= ~7;
    lbl_80301280.unk40->flags &= ~0xF00;
    lbl_80301280.unk40->flags |= 0x800;
    lbl_80301280.unk40->unkE = 0x4002;
    fn_8000EE80(0x38, 0, 0);
    lbl_80301280.unk40->unk1C = 0;
    arc = ARC;
    fn_800E83A4((void*)((*(u32*)(arc + 8) >> 1) + (u32)arc), fn_8000EF20(0x38));
    arc = ARC;
    fn_800BAF48((u8*)((*(u32*)(arc + 8) >> 1) + (u32)arc) + 0xC, 0);
    arc = ARC;
    fn_8000ECB8(0x38, (void*)((*(u32*)(arc + 4) >> 1) + (u32)arc), 0, 0, 0);
    fn_800BB244();
    obj->unk2 = 1;
    obj->unk3 = 0;
    obj->unkFF4 = 0;
    obj->unkFF7 = 0;
    fn_800E5694(0x38, 0, 0xE);
}
