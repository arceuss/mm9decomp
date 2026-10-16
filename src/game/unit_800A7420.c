#include "types.h"

typedef struct Unk8037C3D8 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 line;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ u8 blink;
    /* 0x05 */ u8 pad5[0xC - 0x5];
    /* 0x0C */ u8 arrowOn[4];
    /* 0x10 */ u8 arrowOff[4];
    /* 0x14 */ u8 pad14[0x20 - 0x14];
    /* 0x20 */ u8 unk20[0x50 - 0x20];
} Unk8037C3D8;

typedef struct Unk80301280Sub {
    /* 0x0 */ u32 flags;
} Unk80301280Sub;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ Unk80301280Sub* unk40;
} Unk80301280;

typedef struct Unk8043CA80 {
    /* 0x000 */ u8 pad0[0x258];
    /* 0x258 */ u8* unk258;
} Unk8043CA80;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 unk860;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;
extern Unk8037C3D8 lbl_8037C3D8;
extern Unk80301280 lbl_80301280;
extern Unk8043CA80 lbl_8043CA80;
extern u16 lbl_804ECDF0[4];

void fn_800A5B2C(void* arg0);
s32 fn_8000EECC(s32 arg0);
void fn_8009C110(void* src, void* dst, s32 size);

static inline u8* ArrowDst(void) {
    s32 y = lbl_804ECDF0[lbl_8037C3D8.line] - 0x10;

    return lbl_8043CA80.unk258 + fn_8000EECC(0x24) + ((y >> 3) << 6);
}

BOOL fn_800A7420(void) {
    BOOL ret = FALSE;
    u8 show;
    u8* dst;

    if (lbl_80319DA0.unk860 & 0xF0) {
        fn_800A5B2C(lbl_8037C3D8.unk20);
        lbl_80301280.unk40->flags &= ~0x200;
        fn_8009C110(lbl_8037C3D8.arrowOff, ArrowDst() + 0x1E, 4);
        ret = TRUE;
    } else {
        show = !(++lbl_8037C3D8.blink & 0x10);
        dst = ArrowDst();
        if (show) {
            fn_8009C110(lbl_8037C3D8.arrowOn, dst + 0x1E, 4);
        } else {
            fn_8009C110(lbl_8037C3D8.arrowOff, dst + 0x1E, 4);
        }
    }
    return ret;
}
