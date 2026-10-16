#include "types.h"

extern u8 lbl_803140C0[];
extern u8 lbl_80304B90[];

void fn_8008C07C(u8*, u32);

s32 fn_80083124(u8* p) {
    u8* q = *(u8**)(p + 0x28);

    switch (*(u8*)(q + 1)) {
    case 0:
        fn_8008C07C(lbl_803140C0, *(u32*)(q + 4));
        break;
    case 1:
        *(u32*)(lbl_80304B90 + 0x2DC) |= 1 << (*(u32*)(q + 4) & 0xFFF);
        break;
    }
    return 0;
}
