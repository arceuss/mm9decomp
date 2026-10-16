#include "types.h"

typedef struct Unk803B92C0 {
    /* 0x00 */ u8 pad0[0x45];
    /* 0x45 */ u8 unk45;
    /* 0x46 */ u8 pad46[0x48 - 0x46];
} Unk803B92C0;

extern Unk803B92C0 lbl_803B92C0;

void fn_8010713C(s32 arg0);
void fn_80106FB4(void);
void fn_80105FFC(void);

void fn_800E7500(void) {
    fn_8010713C(1);
    fn_80106FB4();
    fn_80105FFC();
    lbl_803B92C0.unk45 = 1;
}
