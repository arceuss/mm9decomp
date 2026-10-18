#include "types.h"

typedef struct Unk8003ED48 {
    /* 0x000 */ u8 pad0[0x288];
    /* 0x288 */ u8* font;
} Unk8003ED48;

void fn_8000ECB8(s32 arg0, void* gfx, u8 tile, s8 x, s8 y);

static inline void* Font(Unk8003ED48* obj) {
    return (void*)((*(u32*)(obj->font + 8) >> 1) + (u32)obj->font);
}

void fn_8003ED48(Unk8003ED48* obj, u8 row, u8 base, u32 arg) {
    u32 frames;
    u8 sec;
    u8 min;
    u8 hour;
    frames = arg;
    hour = frames / 60 / 60 / 60;

    fn_8000ECB8(0x38, Font(obj), base + hour / 10, 0x14, row * 2 + 4);
    fn_8000ECB8(0x38, Font(obj), base + hour % 10, 0x15, row * 2 + 4);
    fn_8000ECB8(0x38, Font(obj), base + 0xB, 0x16, row * 2 + 4);
    frames -= hour * 216000;
    frames /= 60;
    min = frames / 60;
    fn_8000ECB8(0x38, Font(obj), base + min / 10, 0x17, row * 2 + 4);
    fn_8000ECB8(0x38, Font(obj), base + min % 10, 0x18, row * 2 + 4);
    fn_8000ECB8(0x38, Font(obj), base + 0xB, 0x19, row * 2 + 4);
    sec = frames % 60;
    fn_8000ECB8(0x38, Font(obj), base + sec / 10, 0x1A, row * 2 + 4);
    fn_8000ECB8(0x38, Font(obj), base + sec % 10, 0x1B, row * 2 + 4);
}
