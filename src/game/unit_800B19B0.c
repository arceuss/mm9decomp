#include "types.h"

typedef struct Unk800B19B0 {
    /* 0x000 */ u8 pad000[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} Unk800B19B0;

void fn_800B19B0(Unk800B19B0* obj) {
    obj->unk1F8 = 0;
}
