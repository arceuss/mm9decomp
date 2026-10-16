#include "types.h"

typedef struct Unk8003EAEC {
    /* 0x000 */ u8 pad0[0x288];
    /* 0x288 */ u8* font;
} Unk8003EAEC;

void fn_8000ECB8(s32 arg0, void* gfx, u8 tile, s8 x, s8 y);

static inline void* Font(Unk8003EAEC* obj) {
    return (*(u32*)(obj->font + 8) >> 1) + obj->font;
}

void fn_8003EAEC(Unk8003EAEC* obj, u8 row, u8 base, u32 frames) {
    u32 secs = frames / 60;
    u8 min = secs / 60;
    u8 sec;
    u32 cs;

    fn_8000ECB8(0x38, Font(obj), base + min / 10, 0x14, row * 2 + 4);
    fn_8000ECB8(0x38, Font(obj), base + min % 10, 0x15, row * 2 + 4);
    fn_8000ECB8(0x38, Font(obj), base + 0xB, 0x16, row * 2 + 4);
    sec = secs % 60;
    fn_8000ECB8(0x38, Font(obj), base + sec / 10, 0x17, row * 2 + 4);
    fn_8000ECB8(0x38, Font(obj), base + sec % 10, 0x18, row * 2 + 4);
    fn_8000ECB8(0x38, Font(obj), base + 0xB, 0x19, row * 2 + 4);
    cs = frames * 100;
    fn_8000ECB8(0x38, Font(obj), base + (u8)(cs / 600 % 10), 0x1A, row * 2 + 4);
    fn_8000ECB8(0x38, Font(obj), base + (u8)(cs / 60 % 10), 0x1B, row * 2 + 4);
}
