#include "types.h"

typedef struct Unk8003B33C {
    /* 0x000 */ u8 pad0[0x1C];
    /* 0x01C */ u8 unk1C[0x48 - 0x1C];
    /* 0x048 */ u8 unk48[0x254 - 0x48];
    /* 0x254 */ u8 unk254[0x264 - 0x254];
    /* 0x264 */ s32 unk264;
    /* 0x268 */ s32 unk268;
    /* 0x26C */ u8 unk26C;
    /* 0x26D */ u8 unk26D;
    /* 0x26E */ u8 pad26E;
    /* 0x26F */ u8 unk26F;
    /* 0x270 */ u8* unk270;
} Unk8003B33C;

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

typedef struct Unk80301280Gfx {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u8 pad4[0xE - 0x4];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[0x1C - 0x10];
    /* 0x1C */ s32 unk1C;
} Unk80301280Gfx;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ Unk80301280Gfx* unk40;
} Unk80301280;

typedef struct Unk80383E70 {
    /* 0x0000 */ u8* unk0;
    /* 0x0004 */ u8 pad4[0x7488 - 0x4];
} Unk80383E70;

extern Unk8038B2F8 lbl_8038B2F8;
extern Unk80316D78 lbl_80316D78;
extern Unk80301280 lbl_80301280;
extern Unk80383E70 lbl_80383E70;
extern char lbl_80264A90[];
extern char* lbl_80264928[];
extern u32 lbl_8036CF50[];
extern u8 lbl_803017A0[];

u32 fn_800AA554(const char* name, u16 idx, void* arc);
void fn_800AA9A4(void);
void fn_80023EF0(void* a, void* b, s32 c, s32 d, s32 e);
void fn_800E695C(void* a);
void fn_800E69A4(void* a, void* b);
void fn_800D606C(void* a, void* b, s32 c);
void fn_800A7860(void);
void fn_800A7C78(s32 a);
void fn_8000EE80(s32 a, s32 b, s32 c);
u32 fn_8000EF20(s32 a);
void fn_800E83A4(void* a, u32 b);
void fn_800BAF48(void* a, s32 b);
void fn_8000ECB8(s32 a, void* font, s32 b, s32 c, s32 d);
void fn_800BB938(s32 a, void* b, s32 c);

void fn_8003B33C(Unk8003B33C* obj) {
    u8* p;

    fn_80023EF0(obj->unk254, &obj->unk264, 0, 0, 0x100);
    obj->unk264 = 0x8000;
    obj->unk268 = 0x7000;
    fn_800E695C(obj->unk48);
    fn_800E69A4(obj->unk48, obj->unk254);
    p = lbl_80316D78.unk3004 + 0xC29000;
    p += fn_800AA554(lbl_80264A90, 0xFFFF, p);
    fn_800AA9A4();
    obj->unk270 = p;
    p += fn_800AA554(lbl_80264928[lbl_8036CF50[0]], 0xFFFF, p);
    fn_800AA9A4();
    fn_800A7860();
    lbl_80383E70.unk0 = p;
    fn_800A7C78(0x60);
    fn_800D606C(obj->unk1C, lbl_803017A0, 0x40);
    lbl_8038B2F8.unk184->unk2500 = 0;
    lbl_8038B2F8.unk26BC = 0;
    lbl_80301280.unk40->unk0 &= ~7;
    lbl_80301280.unk40->unk0 &= ~0xF00;
    lbl_80301280.unk40->unkE = 2;
    fn_8000EE80(0x38, 0, 4);
    lbl_80301280.unk40->unk1C = 0;
    lbl_80301280.unk40->unk0 |= 0x800;
    obj->unk26F = 0;
    obj->unk26C = 0;
    obj->unk26D = 1;
}
