#include "types.h"

typedef struct Unk800B1994 {
    /* 0x000 */ u8 pad000[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
    /* 0x1F9 */ u8 pad1F9[0x1FB - 0x1F9];
    /* 0x1FB */ u8 unk1FB;
} Unk800B1994;

void fn_800B1994(Unk800B1994* obj) {
    obj->unk1F8 = 0;
    obj->unk1FB = 0;
}
