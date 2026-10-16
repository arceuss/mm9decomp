#include "types.h"

extern u8 lbl_8031BF70[];

void fn_8009C100(u8*, u8*, s32);
void fn_8009E06C(u8*);
void fn_800EA2E4(u8*, s32);

void fn_80081470(u8* p) {
    fn_8009C100(lbl_8031BF70 + 0x290, lbl_8031BF70 + 0x590,
                *(u8*)(lbl_8031BF70 + 0x28E) * 0x18);
    *(u8*)(lbl_8031BF70 + 0x28F) = *(u8*)(lbl_8031BF70 + 0x28E);
    *(u8*)(lbl_8031BF70 + 0x28E) = 0;
    if (*(s8*)(p + 0x114) != 0) {
        fn_8009E06C(p + 0x138);
        fn_800EA2E4(p + 0x138, 1);
    }
}
