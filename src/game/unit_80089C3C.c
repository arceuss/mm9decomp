#include "types.h"

typedef struct Unk80089C3C {
    /* 0x0000 */ u8 pad0[0xBC4];
    /* 0x0BC4 */ u8 unkBC4[0x21E0 - 0xBC4];
    /* 0x21E0 */ u8 unk21E0;
    /* 0x21E1 */ u8 unk21E1;
    /* 0x21E2 */ u8 pad21E2[0x221C - 0x21E2];
    /* 0x221C */ u8 unk221C[0x2244 - 0x221C];
    /* 0x2244 */ u8 unk2244[1];
} Unk80089C3C;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x38 - 0x4];
} Unk803051D8;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x2290];
    /* 0x2290 */ void* unk2290;
} Unk803140C0;

typedef struct Unk8043CD28 {
    /* 0x000 */ u8 pad0[0x2E4];
    /* 0x2E4 */ u8 unk2E4;
    /* 0x2E5 */ u8 pad2E5[0x2E8 - 0x2E5];
} Unk8043CD28;

extern u8 lbl_80313E98[];
extern void* lbl_804EE984;
extern void* lbl_804EE8AC;
extern void* lbl_804EE8C0;
extern void* lbl_804EE8A0;
extern void* lbl_804EE8F8;
extern Unk803051D8 lbl_803051D8;
extern Unk803140C0 lbl_803140C0;
extern Unk8043CD28 lbl_8043CD28;

void fn_8008334C(void* arg0);
void fn_800A7860(void);
void fn_800A78CC(void);
void fn_800E8BB8(void* list);
void fn_800E695C(void* arg0);
void fn_800AB904(s32 mode);
void* fn_800B709C(s32 arg0, u8* arg1, s32 arg2, s32 arg3, s32 arg4);
void fn_8007D99C(void* dst, void* arg1, void* arg2);
void fn_800A6888(void);
void fn_800EA0F0(u8 arg0);
void fn_8008C07C(Unk80089C3C* p, s32 arg1);

void fn_80089C3C(Unk80089C3C* p) {
    void* r;
    s32 mode;

    lbl_804EE984 = lbl_80313E98;
    fn_8008334C(p->unk2244);
    fn_800A7860();
    fn_800A78CC();
    fn_800E8BB8(lbl_804EE8AC);
    fn_800E8BB8(lbl_804EE8C0);
    fn_800E8BB8(lbl_804EE8A0);
    fn_800E8BB8(lbl_804EE8F8);
    fn_800E695C(p->unkBC4);
    mode = p->unk21E1;
    if (mode != 2) {
        mode = (lbl_803051D8.unk3 >> 5) & 1;
        p->unk21E1 = mode;
    }
    fn_800AB904(mode);
    r = fn_800B709C(0, &p->unk21E0, 0, 1, 0);
    lbl_804EE984 = r;
    lbl_803140C0.unk2290 = r;
    fn_8007D99C(p->unk221C, p->unkBC4, r);
    fn_800A6888();
    fn_800EA0F0(0);
    lbl_8043CD28.unk2E4 = 0;
    fn_8008C07C(p, 0x900);
}
