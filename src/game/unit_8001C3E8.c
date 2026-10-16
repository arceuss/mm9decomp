#include "types.h"
#include "game/stateobj.h"

void fn_800C7608(StateObj* obj);

void fn_8001C3E8(u8* obj) {
    u8* b;
    u8* a;
    u8* c;
    u8 v;

    b = *(u8**)(obj + 0x0C);
    a = *(u8**)(b + 0x28);
    c = *(u8**)(obj + 0x28);
    if ((*(u32*)(obj + 0x14) & 1) != 0) {
        if (*(u8*)(b + 0x14) == 0) {
            fn_800C7608((StateObj*)b);
        }
    }
    if (*(u8*)(b + 0x14) == 0) {
        return;
    }
    if ((*(u32*)(obj + 0x14) & 0x8) == 0) {
        return;
    }
    if (*(u8*)(c + 8) != 5) {
        return;
    }
    if (*(u8*)(c + 9) != 10) {
        return;
    }
    v = *(u8*)(c + 0x11);
    if (v == 2 && *(u8*)(c + 0x12) >= 2) {
        v = 0;
    }
    if (v == 3 && *(u8*)(c + 0x12) >= 4) {
        v = 0;
    }
    if (v == 0) {
        if (*(u8*)(b + 0xD9) == 0) {
            *(u8*)(b + 0xD9) = *(u8*)(b + 0xD9) + 1;
        }
    }
}
