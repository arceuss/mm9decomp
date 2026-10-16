#include "types.h"

typedef struct Unk800DB238 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
} Unk800DB238;

void fn_800E946C(Unk800DB238* obj, u8 arg1);

void fn_800DB238(Unk800DB238* obj) {
    if (obj->state == 0) {
        fn_800E946C(obj, 0x11);
        obj->state++;
    }
}
