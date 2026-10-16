#include "types.h"

typedef struct Unk800CAF6C {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} Unk800CAF6C;

extern u16 lbl_804EF7A0;
extern u16 lbl_804EF7A2;
extern u16 lbl_804EF7A4;
extern u16 lbl_804EF7A6;

s32 fn_8009E850(s32 x, s32 y);
void fn_8009EF24(s32 x, s32 y, u16* buf);

void fn_800CAF6C(Unk800CAF6C* obj, u8 a, s32 flag) {
    u16 buf[4];
    s32 x;
    s32 y;
    u16 t;

    buf[0] = lbl_804EF7A0;
    buf[1] = lbl_804EF7A2;
    buf[2] = lbl_804EF7A4;
    buf[3] = lbl_804EF7A6;
    x = obj->unk60;
    x -= 1;
    x += a << 12;
    y = obj->unk64;
    t = fn_8009E850(x, y - 0x1000);
    buf[2] = flag ? (u16)(t - 0x10) : (u16)(t + 0x10);
    t = fn_8009E850(x, y);
    buf[3] = flag ? (u16)(t - 0x10) : (u16)(t + 0x10);
    fn_8009EF24(x >> 12, (y - 0x1000) >> 12, buf);
}
