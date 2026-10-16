#include "types.h"

typedef struct Unk800E9424 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
} Unk800E9424;

void fn_800E9264(Unk800E9424* obj, s32 arg1, s32 arg2);

void fn_800E9424(Unk800E9424* obj, s32 arg1) {
    fn_800E9264(obj, arg1, 0);
    obj->flagsA |= 8;
    obj->flagsB &= 0xBF;
}
