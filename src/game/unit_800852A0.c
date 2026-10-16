#include "types.h"

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x2298];
} Unk803140C0;

extern Unk803140C0 lbl_803140C0;

void fn_8008C07C(Unk803140C0* work, s32 arg1);

void fn_800852A0(void) {
    fn_8008C07C(&lbl_803140C0, 0x10C00);
}
