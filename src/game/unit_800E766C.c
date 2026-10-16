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

void fn_801070C8(void* fb);
void fn_8010713C(s32 black);
void fn_80106FB4(void);
void fn_80105FFC(void);

void fn_800E766C(void) {
    u8 cur = lbl_803B92C0.cur;

    fn_801070C8(lbl_803B92C0.fb[cur]);
    if (lbl_803B92C0.black) {
        fn_8010713C(0);
        lbl_803B92C0.black = 0;
    }
    fn_80106FB4();
    fn_80105FFC();
    lbl_803B92C0.cur = (cur + 1) & 1;
}
