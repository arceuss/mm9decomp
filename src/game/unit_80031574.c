#include "types.h"

typedef struct Unk80031574 {
    /* 0x0 */ u8 pad0[0x5];
    /* 0x5 */ u8 step;
} Unk80031574;

typedef struct Unk803140C0 {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 pad4[0x2298 - 0x4];
} Unk803140C0;

extern Unk803140C0 lbl_803140C0;
extern u8 lbl_80301420[];

void fn_800E6534(s32 arg0, void (*func)(void));
BOOL fn_800E6654(s32 arg0);
void fn_800E6578(s32 arg0, void (*func)(void));
void fn_800316C8(void* work, s32 arg1);
void fn_8008C004(void);
void fn_8009DC28(void);

void fn_80031574(Unk80031574* task) {
    switch (task->step) {
    case 0:
        fn_800E6534(1, fn_8008C004);
        task->step++;
    case 1:
        if (fn_800E6654(1)) {
            lbl_803140C0.unk2 = 0;
            lbl_803140C0.unk3 = 0;
            if (lbl_803140C0.unk0 == 8 && lbl_803140C0.unk1 == 2 && lbl_803140C0.unk2 == 0 && lbl_803140C0.unk3 == 0) {
                fn_800316C8(lbl_80301420, 0xB0007);
            } else {
                fn_800316C8(lbl_80301420, 1);
                fn_800E6578(0, fn_8009DC28);
            }
        }
        break;
    }
}
