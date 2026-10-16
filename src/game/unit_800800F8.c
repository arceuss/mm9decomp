#include "types.h"

typedef struct Unk800800F8 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u8 padE[0x14 - 0xE];
    /* 0x14 */ void* unk14;
    /* 0x18 */ u8 pad18[0x1C - 0x18];
    /* 0x1C */ s8 unk1C;
} Unk800800F8;

void fn_800E69A4(void* arg0, Unk800800F8* arg1);
void fn_800E69E8(void* arg0);

void fn_800800F8(Unk800800F8* work) {
    void* target = work->unk14;

    if (work->unk1C) {
        if (work->unkC < 0xC0) {
            work->unkC = 0xC0;
        }
        if (work->unkC > 0x180) {
            work->unkC = 0x180;
        }
        fn_800E69A4(target, work);
        fn_800E69E8(target);
    }
}
