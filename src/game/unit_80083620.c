#include "types.h"

char* strcpy(char*, const char*);
void fn_80179BA0(u8*, u8*);

void fn_80083620(u8* o, u32 a, s32 b, u8* c, u16 d, u16 e, u16 f, u16 g) {
    *(u32*)(o + 8) = a;
    if (b != 1) {
        strcpy((char*)(o + 0x10), (char*)c);
    } else {
        fn_80179BA0(o + 0x10, c);
    }
    *(u32*)(o + 0xC) = b;
    *(u16*)(o + 0x410) = d;
    *(u16*)(o + 0x412) = e;
    *(u16*)(o + 0x414) = f;
    *(u16*)(o + 0x416) = g;
    *(u8*)(o + 0x418) = 0xFF;
    *(u8*)(o + 0x419) = 0;
    *(u8*)(o + 0x41A) = 2;
}
