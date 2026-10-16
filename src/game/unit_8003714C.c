#include "types.h"

typedef struct Unk8003714C {
    /* 0x000 */ u8 pad0[0x272];
    /* 0x272 */ s8 unk272;
    /* 0x273 */ s8 unk273;
    /* 0x274 */ u8 unk274;
} Unk8003714C;

void fn_8003714C(Unk8003714C* obj) {
    if ((obj->unk272 == 0xB && obj->unk273 == 0) || (obj->unk272 == 0xB && obj->unk273 == 1)) {
        obj->unk274 = 1;
    } else if ((obj->unk272 == 0xB && obj->unk273 == 2) || (obj->unk272 == 0xB && obj->unk273 == 3) ||
               (obj->unk272 == 0xB && obj->unk273 == 4)) {
        obj->unk274 = 2;
    } else if ((obj->unk272 == 0xB && obj->unk273 == 6) || (obj->unk272 == 0xB && obj->unk273 == 7) ||
               (obj->unk272 == 0xB && obj->unk273 == 5)) {
        obj->unk274 = 3;
    } else if ((obj->unk272 == 7 && obj->unk273 == 7) || (obj->unk272 == 8 && obj->unk273 == 7)) {
        obj->unk274 = 5;
    } else if ((obj->unk272 == 9 && obj->unk273 == 7) || (obj->unk272 == 10 && obj->unk273 == 7)) {
        obj->unk274 = 6;
    } else {
        obj->unk274 = 0;
    }
}
