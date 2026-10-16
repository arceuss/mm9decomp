#include "types.h"

extern u8 lbl_80264B10[];
extern u8 lbl_8038E3A8[];
void fn_800A5B2C(void* a, void* b);
void fn_800E5910(u32 v);
void fn_800A5BE0(void* a, void* b, u32 c, u32 d);

void fn_8003C540(u8* obj) {
    u16 id;

    if (obj[0x271] == 0) {
        id = *(u16*)(lbl_80264B10 + ((s8)obj[0x26F] + 6) * 2);
        fn_800A5B2C(lbl_8038E3A8, lbl_80264B10);
        fn_800E5910(id);
        fn_800A5BE0(lbl_8038E3A8, lbl_8038E3A8 + 0x2C, 0, 0);
        obj[0x271]++;
    }
}
