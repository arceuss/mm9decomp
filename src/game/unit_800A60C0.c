#include "types.h"
extern u8 lbl_8036CF50[];
extern void fn_8009C04C(u32, void*, u32);
extern void fn_800F0534(void*, u32);
void fn_800A60C0(u32 arg) {
    u8* dst = lbl_8036CF50 + 8;
    fn_8009C04C(0, dst, 0x2800);
    {
    u32 value, color;
    u8 mask;
    for (color = 1; color <= 5; color++) {
        for (value = 0; value < 256; value++) {
            for (mask = 1; mask != 0; mask <<= 1) {
                if (value & mask) *dst = color;
                dst++;
            }
        }
    }
    fn_800F0534(lbl_8036CF50 + 8, 0x2800);
    }
    dst = lbl_8036CF50 + 0x2808;
    fn_8009C04C(0, dst, 0x1400);
    {
    u32 color, value;
    u8 mask, high;
    for (color = 1, high = 0x10; color <= 5; color++, high += 0x10) {
        for (value = 0; value < 256; value++) {
            for (mask = 1; mask != 0; mask <<= 1) {
                if (value & mask) *dst = high;
                mask <<= 1;
                if (value & mask) *dst |= color;
                dst++;
            }
        }
    }
    }
    fn_800F0534(lbl_8036CF50 + 0x2808, 0x1400);
    *(u32*)(lbl_8036CF50 + 4) = arg;
}
