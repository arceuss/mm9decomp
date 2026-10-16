#include "game/work_8038DC58.h"

typedef struct Unk800C7A4C {
    /* 0x0000 */ u8 pad0[0x215C];
    /* 0x215C */ u8 unk215C[0x84];
} Unk800C7A4C;

void fn_8009C100(void* src, void* dst, s32 size);
void fn_800A69C8(void);

void fn_800C7A4C(Unk800C7A4C* work) {
    fn_8009C100(work->unk215C, lbl_8038DC58.unkC, 0x84);
    fn_800A69C8();
}
