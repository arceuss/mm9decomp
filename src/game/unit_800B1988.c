#include "types.h"

typedef struct Unk800B1988 {
    /* 0x000 */ u8 pad000[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} Unk800B1988;

void fn_800B1988(Unk800B1988* obj) {
    obj->unk1F8 = 0;
}
