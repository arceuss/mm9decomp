#include "types.h"

extern u8 lbl_804EE6C0[8];
extern u8 lbl_804EC838[];
void* fn_800E8C44(u8* pool);

void fn_80024974(u32 kind, u32 z, u32 a, u32 b) {
    s32 v;
    u8* obj;
    s32 count;
    u32 i;
    u8* pool;

    if (kind == 0) {
        count = 8;
    } else if (kind == 1) {
        count = 6;
    } else {
        count = 8;
    }
    v = *(s16*)(*(u8**)lbl_804EE6C0 + 0xA);
    if (v < count) {
        return;
    }
    pool = lbl_804EC838;
    i = 0;
    while (i < count) {
        pool = *(u8**)lbl_804EE6C0;
        obj = fn_800E8C44(pool);
        if (obj != 0) {
            obj[0x2E] = 0x10;
            obj[9] = 1;
            *(u32*)(obj + 0x18) = *(u32*)(*(u32*)(lbl_804EC838 + 4));
            *(s16*)(obj + 0x2A) = 0;
            obj[0x2C] = 0;
            obj[0x2F] = 0;
            obj[0xB] |= 0x20;
            obj[0x21] = obj[0x20];
            obj[0x14] = kind;
            obj[0x15] = i;
            *(u32*)(obj + 0x34) = a;
            *(u32*)(obj + 0x38) = b;
        }
        i++;
    }
}
