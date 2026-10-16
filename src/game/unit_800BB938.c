#include "types.h"

void fn_800BAFDC(void* src, void* dst, u32 size);

void fn_800BB938(s32 frame, u8* pal, u32 dst) {
    s32 n = pal[2] - pal[1] + 1;

    if (!(dst & 0x1FF)) {
        fn_800BAFDC(pal + frame * n * 2 + 4, (void*)((pal[1] << 1) + dst), n * 2);
    } else {
        fn_800BAFDC(pal + frame * n * 2 + 4, (void*)(((pal[1] & 0xF) << 1) + dst), n * 2);
    }
}
