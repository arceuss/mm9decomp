#include "types.h"

typedef struct Unk80316D28 {
    /* 0x0 */ u8 pad0[0x3];
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 pad5[0x10 - 0x5];
} Unk80316D28;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 state;
    /* 0x0001 */ u8 pad1[0x2298 - 0x1];
} Unk803140C0;

extern void (*lbl_80273618[])(Unk803140C0* work);
extern Unk80316D28 lbl_80316D28;
extern Unk803140C0 lbl_803140C0;

void fn_800E65B0(void);
void fn_800E65E8(void);
void fn_800D58B0(void);
void fn_800E65FC(void);
void fn_800E6610(s32 arg0);

void fn_8008C004(void) {
    fn_800E65B0();
    while (TRUE) {
        fn_800E65E8();
        if (lbl_80316D28.unk3 == 0 && lbl_80316D28.unk4 < 2) {
            fn_800D58B0();
            lbl_80273618[lbl_803140C0.state](&lbl_803140C0);
        }
        fn_800E65FC();
        fn_800E6610(1);
    }
}
