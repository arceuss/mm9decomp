#include "types.h"

typedef struct Unk800AC8E4 {
    /* 0x0 */ u8 pad0[0xA];
    /* 0xA */ u8 flagsA;
} Unk800AC8E4;

u32 fn_800B417C(Unk800AC8E4* obj);

u32 fn_800AC8E4(Unk800AC8E4* obj) {
    u32 result = fn_800B417C(obj);

    if (result != 5) {
        obj->flagsA |= 1;
        return result;
    }
    return 5;
}
