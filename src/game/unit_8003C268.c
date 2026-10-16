#include "types.h"

extern u8 lbl_80264B10[];
extern u8 lbl_8038E3A8[];

extern void fn_800A5B2C(void* p);
extern void fn_800E5910(u32 v);
extern void fn_800A5BE0(void* a, void* b, u32 c, u32 d);

void fn_8003C268(u8* o) {
    if (o[0x271] == 0) {
        u16 v = *(u16*)(lbl_80264B10 + (s8)o[0x26F] * 2);

        fn_800A5B2C(lbl_8038E3A8);
        fn_800E5910(v);
        fn_800A5BE0(lbl_8038E3A8, lbl_8038E3A8 + 0x2C, 0, 0);
        o[0x271] = o[0x271] + 1;
    }
}
