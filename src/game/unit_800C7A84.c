#include "game/work_8038DC58.h"

typedef struct Unk800C7A84 {
    /* 0x0000 */ u8 pad0[0x215C];
    /* 0x215C */ u8 unk215C[0x84];
} Unk800C7A84;

void fn_8009C100(void* src, void* dst, u32 size);

void fn_800C7A84(Unk800C7A84* work) {
    fn_8009C100((u8*)&lbl_8038DC58 + 0xC, work->unk215C, 0x84);
}
