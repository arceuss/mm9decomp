#include "types.h"

typedef struct Unk800DAE54Parent {
    /* 0x000 */ u8 pad0[0x2AE];
    /* 0x2AE */ u16 unk2AE;
} Unk800DAE54Parent;

typedef struct Unk800DAE54 {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ Unk800DAE54Parent* parent;
} Unk800DAE54;

void fn_800D6184(Unk800DAE54* obj);

void fn_800DAE54(Unk800DAE54* obj) {
    if (obj->parent->unk2AE & 2) {
        fn_800D6184(obj);
    }
}
