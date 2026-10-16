#include "types.h"

typedef struct Unk800B19A4 {
    /* 0x000 */ u8 pad000[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} Unk800B19A4;

void fn_800B19A4(Unk800B19A4* obj) {
    obj->unk1F8 = 0;
}
