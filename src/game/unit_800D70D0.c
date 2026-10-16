#include "types.h"

typedef struct Unk800D70D0 {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 step;
} Unk800D70D0;

void fn_800E946C(Unk800D70D0* obj, u8 arg1);
void fn_800E9750(Unk800D70D0* obj, u16 arg1);

void fn_800D70D0(Unk800D70D0* obj) {
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0xC);
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
