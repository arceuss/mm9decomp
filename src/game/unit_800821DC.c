#include "types.h"

extern u32 lbl_802638E0[];

void fn_800A7C30(u8*);
void fn_800A7E88(u32);

s32 fn_800821DC(u8* p) {
    if (*(s8*)(*(u8**)(p + 0x28) + 1) == 1) {
        fn_800A7C30(p);
        fn_800A7E88(lbl_802638E0[*(s16*)(*(u8**)(p + 0x28) + 2)]);
    }
    return 0;
}
