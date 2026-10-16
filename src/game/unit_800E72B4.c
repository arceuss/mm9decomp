#include "types.h"

typedef struct Unk80301280_40 {
    /* 0x0 */ u32 unk0;
} Unk80301280_40;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ Unk80301280_40* unk40;
    /* 0x44 */ u8 pad44[0x48 - 0x44];
} Unk80301280;

extern Unk80301280 lbl_80301280;
extern u16 lbl_804EE960;

void fn_800A7860(void);

void fn_800E72B4(void) {
    lbl_804EE960 = 0x8000;
    fn_800A7860();
    lbl_80301280.unk40->unk0 &= ~7;
    lbl_80301280.unk40->unk0 &= ~0xF00;
}
