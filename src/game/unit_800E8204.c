#include "types.h"

typedef struct Unk8043CA80 {
    /* 0x000 */ u32 unk0;
    /* 0x004 */ u8 pad4[0x244 - 0x4];
    /* 0x244 */ void* unk244;
    /* 0x248 */ u32 unk248;
    /* 0x24C */ u32 unk24C;
    /* 0x250 */ u8 pad250[0x258 - 0x250];
    /* 0x258 */ void* unk258;
    /* 0x25C */ void* unk25C;
    /* 0x260 */ u32 unk260;
    /* 0x264 */ u32 unk264;
} Unk8043CA80;

extern Unk8043CA80 lbl_8043CA80;

void fn_8009C04C(u32 fill, void* dst, u32 size);

void fn_800E8204(void) {
    lbl_8043CA80.unk244 = &lbl_8043CA80.unk248;
    fn_8009C04C(0x11111111, lbl_8043CA80.unk258, lbl_8043CA80.unk260);
    fn_8009C04C(0x11111111, lbl_8043CA80.unk25C, lbl_8043CA80.unk264);
    lbl_8043CA80.unk0 = 0;
    lbl_8043CA80.unk24C = 0;
}
