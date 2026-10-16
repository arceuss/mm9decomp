#include "types.h"

extern u8 lbl_8038DC58[];

void fn_8009C100(void* dst, void* src, s32 size);

void fn_800C6744(void* src) {
    fn_8009C100(lbl_8038DC58 + 0xC, src, 0x84);
}
