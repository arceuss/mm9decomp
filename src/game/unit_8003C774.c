#include "types.h"

typedef struct Unk8038E140 {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ u8 unk4[0xC0 - 0x4];
    /* 0xC0 */ u8 unkC0[0x10];
} Unk8038E140;

typedef struct Unk8003C774 {
    /* 0x000 */ u8 pad0[0x5];
    /* 0x005 */ u8 unk5;
    /* 0x006 */ u8 unk6;
    /* 0x007 */ u8 unk7;
    /* 0x008 */ u8 pad8[0x1C - 0x8];
    /* 0x01C */ u8 unk1C[0x48 - 0x1C];
    /* 0x048 */ u8 unk48[0x254 - 0x48];
    /* 0x254 */ u8 unk254[0x264 - 0x254];
    /* 0x264 */ s32 unk264;
    /* 0x268 */ s32 unk268;
    /* 0x26C */ u8 unk26C;
    /* 0x26D */ u8 unk26D;
    /* 0x26E */ u8 unk26E;
    /* 0x26F */ u8 pad26F[0x278 - 0x26F];
    /* 0x278 */ s32 unk278;
    /* 0x27C */ u8 unk27C;
    /* 0x27D */ u8 pad27D[0x284 - 0x27D];
    /* 0x284 */ u8* unk284;
    /* 0x288 */ u8 pad288[0x2AC - 0x288];
    /* 0x2AC */ u8 unk2AC;
    /* 0x2AD */ u8 unk2AD;
    /* 0x2AE */ u16 unk2AE;
    /* 0x2B0 */ u8 unk2B0;
    /* 0x2B1 */ u8 unk2B1;
    /* 0x2B2 */ u8 pad2B2[0x36C - 0x2B2];
    /* 0x36C */ void* unk36C;
    /* 0x370 */ void* unk370;
} Unk8003C774;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern Unk8038E140 lbl_8038E140;
extern Unk80316D78 lbl_80316D78;
extern char lbl_80264EF0[];
extern u8 lbl_803017A0[];
extern u32 lbl_8036CF50[];

s32 fn_800D57BC(s32 a);
void fn_800D5564(s32 a);
void fn_80023EF0(void* a, void* b, s32 c, s32 d, s32 e);
void fn_800E695C(void* a);
void fn_800E69A4(void* a, void* b);
void fn_800D606C(void* a, void* b, s32 c);
u32 fn_800AA554(const char* name, u16 idx, void* arc);
void fn_800AA9A4(void);
void fn_800A67CC(u8 stage, void* arc);

#define ARC (lbl_80316D78.unk3004 + 0xC29000)

void fn_8003C774(Unk8003C774* obj) {
    u8 mode;
    u8 v;
    u32 r;

    mode = obj->unk6 & 0xF;
    obj->unk36C = lbl_8038E140.unkC0;
    obj->unk370 = lbl_8038E140.unk4;
    obj->unk2AE = 0;
    obj->unk26E = (obj->unk6 >> 4) & 0xF;
    if (mode == 2 || mode == 3) {
        v = obj->unk7 - 2;
        obj->unk2AD = 0;
        obj->unk2AC = v;
        obj->unk2B0 = 0;
        if (v >= 9) {
            obj->unk2B0 = v - 8;
            obj->unk2AC = 8;
        }
        obj->unk26D = 0;
    } else {
        obj->unk26D = obj->unk7;
        if (obj->unk26D == 0 || obj->unk26D == 1) {
            obj->unk2AE |= 8;
        }
    }
    if (fn_800D57BC(7) == 0) {
        fn_800D5564(7);
    }
    obj->unk264 = 0x8000;
    obj->unk268 = 0x7000;
    fn_80023EF0(obj->unk254, &obj->unk264, 0, 0, 0x100);
    fn_800E695C(obj->unk48);
    fn_800E69A4(obj->unk48, obj->unk254);
    fn_800D606C(obj->unk1C, lbl_803017A0, 0x40);
    obj->unk2B1 = 0xD;
    obj->unk26C = 0;
    r = fn_800AA554(lbl_80264EF0, 0xFFFF, ARC);
    fn_800AA9A4();
    if (r & 3) {
        r = (r + 4) & ~3;
    }
    fn_800A67CC(lbl_8036CF50[0], ARC);
    obj->unk27C = 0;
    obj->unk284 = &lbl_80316D78.unk3004[r + 0xC29000];
    obj->unk278 = 0;
    obj->unk5 = mode;
    obj->unk6 = 0;
    obj->unk7 = 0;
}
