#include "types.h"

typedef struct Unk80097CAC {
    /* 0x0000 */ u8 pad0;
    /* 0x0001 */ u8 mode;
    /* 0x0002 */ u8 step;
    /* 0x0003 */ u8 unk3;
    /* 0x0004 */ s16 fade;
    /* 0x0006 */ s16 unk6;
    /* 0x0008 */ s16 timer;
    /* 0x000A */ u8 padA[0xDD0 - 0xA];
    /* 0x0DD0 */ u8 unkDD0[0xFDC - 0xDD0];
    /* 0x0FDC */ u8 unkFDC[0xFEC - 0xFDC];
    /* 0x0FEC */ s32 unkFEC;
    /* 0x0FF0 */ s32 unkFF0;
    /* 0x0FF4 */ s16 unkFF4[0x22];
    /* 0x1038 */ u8 pad1038[0x10F4 - 0x1038];
    /* 0x10F4 */ u8 unk10F4[0x2154 - 0x10F4];
    /* 0x2154 */ u32 unk2154;
} Unk80097CAC;

typedef struct Unk80301280Sub {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u8 pad4[0xE - 0x4];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[0x1C - 0x10];
    /* 0x1C */ s32 unk1C;
} Unk80301280Sub;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ Unk80301280Sub* unk40;
    /* 0x44 */ u8 pad44[0x48 - 0x44];
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
    /* 0x26BE */ u8 pad26BE[0x26C0 - 0x26BE];
} Unk8038B2F8;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

typedef struct Unk8036CF50 {
    /* 0x0 */ s32 stage;
    /* 0x4 */ u8 pad4[0xEFE0 - 0x4];
} Unk8036CF50;

extern Unk80316D78 lbl_80316D78;
extern Unk8036CF50 lbl_8036CF50;
extern Unk8038B2F8 lbl_8038B2F8;
extern Unk80301280 lbl_80301280;
typedef struct Unk80383E70 {
    /* 0x0 */ u8* buf;
    /* 0x4 */ u8 pad4[0x7488 - 0x4];
} Unk80383E70;

extern Unk80383E70 lbl_80383E70;
extern s32 lbl_80274470[];
typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x2290];
    /* 0x2290 */ void* player;
    /* 0x2294 */ u8 pad2294[0x2298 - 0x2294];
} Unk803140C0;

extern Unk803140C0 lbl_803140C0;

void fn_80023EF0(void* arg0, void* arg1, s32 arg2, s32 arg3, s32 arg4);
void fn_800E695C(void* arg0);
void fn_800E69A4(void* arg0, void* arg1);
s32 fn_800AA554(s32 arg0, u16 arg1, u8* arg2);
void fn_800AA9A4(void);
void fn_800A7860(void);
void fn_8000EE80(s32 arg0, s32 arg1, s32 arg2);
s32 fn_8000EF20(s32 arg0);
void fn_800E83A4(void* arg0, s32 arg1);
void fn_800BAF48(void* arg0, s32 arg1);
void fn_8000ECB8(s32 arg0, void* gfx, s32 tile, s32 x, s32 y);
void fn_8000ED10(s32 arg0, void* dst, void* gfx, u8 tile, s32 arg4, s32 arg5);
void fn_800E2044(Unk80097CAC* obj, u8 arg1, s32 arg2);
void fn_800BB244(void);
BOOL fn_800B58F8(void* player, s32 arg1);
void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void fn_800D5564(s32 music);

#define ARC (lbl_80316D78.unk3004 + 0xCD5000)

void fn_80097CAC(Unk80097CAC* obj) {
    u8* arc;
    u8* p;
    u32 n;
    u32 R;
    u32 a;
    u32 b;
    s32 i;

    fn_80023EF0(obj->unkFDC, &obj->unkFEC, 0, 0, 0x100);
    obj->unkFEC = 0x8000;
    obj->unkFF0 = 0x7000;
    fn_800E695C(obj->unkDD0);
    fn_800E69A4(obj->unkDD0, obj->unkFDC);
    arc = ARC;
    p = arc + fn_800AA554(lbl_80274470[lbl_8036CF50.stage], 0xFFFF, arc);
    fn_800AA9A4();
    fn_800A7860();
    lbl_80383E70.buf = p;
    n = obj->unk2154 & 0xFFF;
    if (n < 0xE) {
        n--;
    }
    fn_800E2044(obj, n, 0);
    lbl_8038B2F8.unk26BC = 0;
    lbl_8038B2F8.unk184->unk2500 = 0;
    lbl_80301280.unk40->flags &= ~7;
    lbl_80301280.unk40->flags &= ~0xF00;
    lbl_80301280.unk40->unkE = 2;
    fn_8000EE80(0x38, 0, 4);
    lbl_80301280.unk40->unk1C = 0;
    arc = ARC;
    fn_800E83A4((void*)((*(u32*)(arc + 8) >> 1) + (u32)arc), fn_8000EF20(0x38));
    arc = ARC;
    fn_800BAF48((u8*)((*(u32*)(arc + 8) >> 1) + (u32)arc) + 0xC, 0);
    arc = ARC;
    fn_8000ECB8(0x38, (void*)((*(u32*)(arc + 4) >> 1) + (u32)arc), 0, 0, 0);
    arc = ARC;
    fn_8000ED10(0x38, obj->unk10F4, (void*)((*(u32*)(arc + 4) >> 1) + (u32)arc), 9, 0, 0);
    lbl_80301280.unk40->flags |= 0x800;
    for (i = 0; i < 0x22; i++) {
        obj->unkFF4[i] = 0;
    }
    fn_800D5564(4);
    obj->fade = 0;
    obj->timer = 0;
    obj->unk6 = 0;
    fn_800BB244();
    R = (u32)ARC;
    a = *(u32*)(R + 0x14) >> 1;
    b = *(u32*)(R + 0x18) >> 1;
    fn_800BB4E8(0, fn_800B58F8(lbl_803140C0.player, 2) != 1 ? 0 : 10, R + a + *(u32*)(R + a), R + b + *(u32*)(R + b), 0x20, 0, R + b, R + a);
    obj->mode = 1;
    obj->step = 0;
    obj->unk3 = 0;
}
