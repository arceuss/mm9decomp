#include "types.h"

void fn_80029A0C(u32* list, u32 start, s16 width, u16 count);
void OSInitMutex(u8* p);
void OSInitCond(u8* p);
void fn_800F8130(u8* obj, void (*fn)(u8*), u8* arg, u32 a, u32 b, u32 c, u32 d);
void fn_800F8798(u8* obj);
void fn_80029D5C(u8* obj);

void fn_80029BCC(u8* obj, u32 b, u32 c) {
    u8* p;
    s32 i;

    p = obj + 0x350;
    for (i = 0; i < 2; i++) {
        fn_80029A0C((u32*)p, c, 0x24, 4);
        c += 0xB0;
        p += 0x18;
    }
    *(u16*)(obj + 0x380) = 0;
    OSInitMutex(obj + 0x318);
    OSInitMutex(obj + 0x330);
    OSInitCond(obj + 0x348);
    fn_800F8130(obj, (void (*)(u8*))fn_80029D5C, obj, b + 0x2000, 0x2000, 0x18, 1);
    fn_800F8798(obj);
}
