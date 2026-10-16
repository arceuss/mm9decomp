#include "types.h"

typedef struct Unk80301280Sub {
    /* 0x0 */ u32 unk0_0 : 20;
    /* 0x0 */ u32 unk0_20 : 4;
    /* 0x0 */ u32 unk0_24 : 8;
} Unk80301280Sub;

typedef struct Unk80301280 {
    /* 0x00 */ u32 unk0_0 : 1;
    /* 0x00 */ u32 unk0_1 : 1;
    /* 0x00 */ u32 unk0_2 : 1;
    /* 0x00 */ u32 unk0_3 : 1;
    /* 0x00 */ u32 unk0_4 : 1;
    /* 0x00 */ u32 unk0_5 : 1;
    /* 0x00 */ u32 unk0_6 : 1;
    /* 0x00 */ u32 unk0_7 : 1;
    /* 0x00 */ u32 unk0_8 : 24;
    /* 0x04 */ u8 pad4[0x40 - 0x4];
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
    /* 0x26BC */ u16 unk26BC;
    /* 0x26BE */ u8 pad26BE[0x26C0 - 0x26BE];
} Unk8038B2F8;

typedef struct Unk800897D8 {
    /* 0x0000 */ u8 pad0[0x2];
    /* 0x0002 */ u8 unk2;
    /* 0x0003 */ u8 pad3[0x2144 - 0x3];
    /* 0x2144 */ s32 unk2144;
    /* 0x2148 */ u8 pad2148[0x2154 - 0x2148];
    /* 0x2154 */ s32 unk2154;
    /* 0x2158 */ u8 pad2158[0x215A - 0x2158];
    /* 0x215A */ u8 unk215A;
    /* 0x215B */ u8 pad215B;
    /* 0x215C */ u8 unk215C[0x21E0 - 0x215C];
    /* 0x21E0 */ u8 unk21E0;
    /* 0x21E1 */ u8 pad21E1[0x221C - 0x21E1];
    /* 0x221C */ u8 unk221C[0x2244 - 0x221C];
    /* 0x2244 */ u8 unk2244[0x2278 - 0x2244];
    /* 0x2278 */ s32 unk2278;
    /* 0x227C */ u8 unk227C;
    /* 0x227D */ u8 unk227D;
    /* 0x227E */ u8 pad227E[0x2298 - 0x227E];
} Unk800897D8;

extern s32 lbl_80261E08[];
extern Unk80301280 lbl_80301280;
extern Unk8038B2F8 lbl_8038B2F8;
extern Unk800897D8 lbl_803140C0;

void fn_800E6878(void);
void fn_80083398(void* arg0);
void fn_8007D914(void* arg0);
void fn_800C66DC(void* arg0);
void fn_800E9D0C(u8 index);
void fn_800B72B0(u8* arg0, s32 arg1, s32 arg2);
void fn_8008C07C(Unk800897D8* p, s32 arg1);

void fn_800897D8(Unk800897D8* p) {
    p->unk227C = 3;
    if (lbl_80261E08[p->unk2] == 14) {
        p->unk227D = 4;
    } else {
        p->unk227D = 0;
    }
    p->unk215A = 0;
    lbl_80301280.unk0_1 = 1;
    lbl_80301280.unk0_2 = 0;
    lbl_80301280.unk0_3 = 1;
    lbl_80301280.unk0_4 = 1;
    lbl_80301280.unk0_5 = 0;
    lbl_80301280.unk0_6 = 0;
    lbl_80301280.unk0_7 = 0;
    fn_800E6878();
    lbl_8038B2F8.unk26BC = 0;
    lbl_8038B2F8.unk184->unk2500 = 0;
    lbl_80301280.unk40->unk0_20 = 0;
    p->unk2278 = 0;
    lbl_803140C0.unk2144 = 0;
    fn_80083398(p->unk2244);
    fn_8007D914(p->unk221C);
    fn_800C66DC(p->unk215C);
    fn_800E9D0C(p->unk227D);
    fn_800B72B0(&p->unk21E0, 0, 1);
    p->unk21E0 = 0;
    p->unk2154 = lbl_80261E08[p->unk2];
    fn_8008C07C(&lbl_803140C0, 0x700);
}
