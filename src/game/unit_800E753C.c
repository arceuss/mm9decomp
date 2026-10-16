#include "types.h"

typedef struct Unk803B92C0 {
    /* 0x00 */ u32 viTVmode;
    /* 0x04 */ u16 fbWidth;
    /* 0x06 */ u16 efbHeight;
    /* 0x08 */ u16 xfbHeight;
    /* 0x0A */ u8 pad0A[0x3C - 0xA];
    /* 0x3C */ void* fb[2];
    /* 0x44 */ u8 cur;
    /* 0x45 */ u8 black;
    /* 0x46 */ u8 unk46;
    /* 0x47 */ u8 unk47;
} Unk803B92C0;

extern Unk803B92C0 lbl_803B92C0;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;

#define ROUND32(x) (((u32)(x) + 31) & ~31)

void fn_80105AB4(void);
u8 fn_800E76EC(Unk803B92C0* mode, u8 arg1);

void fn_800E753C(void) {
    u32 size;

    lbl_803B92C0.cur = 0;
    lbl_803B92C0.black = 1;
    lbl_803B92C0.unk47 = 0;
    lbl_803B92C0.unk46 = 1;
    fn_80105AB4();
    lbl_803B92C0.unk47 = fn_800E76EC(&lbl_803B92C0, lbl_803B92C0.unk46);
    size = (u16)((lbl_803B92C0.fbWidth + 15) & 0xFFF0) * lbl_803B92C0.xfbHeight;
    lbl_803B92C0.fb[0] = (void*)ROUND32(lbl_80316D78.unk3004 + 0x800000);
    lbl_803B92C0.fb[1] = (void*)ROUND32((u8*)lbl_803B92C0.fb[0] + size * 2);
}
