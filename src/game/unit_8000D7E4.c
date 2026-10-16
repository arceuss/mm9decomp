#include "types.h"

extern u8 lbl_804EF4A0;
extern u8 lbl_804EF4A1;
extern u8 lbl_804EF4A2;
extern u8 lbl_804EF4A3;
extern u32 lbl_8036CF50[];
extern u8 lbl_8026F9B8[];

void OSFatal(void*, void*, void*);

void fn_8000D7E4(s32 a) {
    u8 color[4];
    u32 zero = 0;
    color[0] = lbl_804EF4A0;
    color[1] = lbl_804EF4A1;
    color[2] = lbl_804EF4A2;
    color[3] = lbl_804EF4A3;
    OSFatal(color, &zero, *(void**)(lbl_8026F9B8 + lbl_8036CF50[0] * 0x24 + a * 4));
}
