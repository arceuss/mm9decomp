#include "types.h"

extern u8 lbl_804ECE40[4];
extern u16 lbl_804ECE3C[1];
extern u32 lbl_804ECE78[2];
extern u32 lbl_8027E6B8[4];
extern u8* lbl_804EE8C0;

s32 fn_800B1E14(u8* obj);
s32 fn_800BC68C(u8* obj, u32 a, u32 b, u32 c, s32 d);

s32 fn_800B1FEC(u8* obj) {
    s32 v;
    u8 b;
    s32 diff;

    v = fn_800B1E14(obj);
    if (v == -1)
        goto fail;
    b = lbl_804ECE40[v];
    if ((u32)(b * 3) > (u32)(3 - obj[0x1F8]))
        goto fail;
    if ((u32)*(s16*)(lbl_804EE8C0 + 0xA) < 3)
        goto fail;
    diff = (s32)*(u16*)(obj + 0x150) - (s32)lbl_804ECE3C[v];
    if (diff < 0)
        goto fail;
    if (fn_800BC68C(obj, lbl_8027E6B8[obj[0xF5]], lbl_804ECE78[v], b, 1) == 0)
        goto fail;
    *(u16*)(obj + 0x150) = diff;
    return v + 3;
fail:
    return -1;

}
