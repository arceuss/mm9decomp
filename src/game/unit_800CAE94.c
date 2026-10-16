#include "types.h"

typedef struct Unk800CAE94 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} Unk800CAE94;

extern u16 lbl_804EF798;
extern u16 lbl_804EF79A;
extern u16 lbl_804EF79C;
extern u16 lbl_804EF79E;

s32 fn_8009E850(s32 x, s32 y);
void fn_8009EF24(s32 x, s32 y, u16* buf);

void fn_800CAE94(Unk800CAE94* obj, u8 a, s32 flag) {
    u16 buf[4];
    s32 x;
    s32 y;
    u16 t;

    buf[0] = lbl_804EF798;
    buf[1] = lbl_804EF79A;
    buf[2] = lbl_804EF79C;
    buf[3] = lbl_804EF79E;
    y = obj->unk64;
    y -= 1;
    x = obj->unk60;
    y -= a << 12;
    t = fn_8009E850(x - 0x1000, y);
    buf[2] = flag ? (u16)(t - 0x10) : (u16)(t + 0x10);
    t = fn_8009E850(x, y);
    buf[3] = flag ? (u16)(t - 0x10) : (u16)(t + 0x10);
    fn_8009EF24((x - 0x1000) >> 12, y >> 12, buf);
}
