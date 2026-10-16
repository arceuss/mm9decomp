#include "types.h"

typedef struct Unk800B19BC {
    /* 0x000 */ u8 pad000[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
    /* 0x1F9 */ u8 unk1F9;
} Unk800B19BC;

void fn_800B19BC(Unk800B19BC* obj) {
    obj->unk1F8 = 0;
    obj->unk1F9 = 0;
}
