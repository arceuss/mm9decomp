#include "types.h"

typedef struct Unk800E40F8Parent {
    /* 0x000 */ u8 pad0[0x2AE];
    /* 0x2AE */ u8 unk2AE;
} Unk800E40F8Parent;

typedef struct Unk800E40F8 {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ Unk800E40F8Parent* parent;
} Unk800E40F8;

void fn_800D6184(Unk800E40F8* obj);

void fn_800E40F8(Unk800E40F8* obj) {
    if (obj->parent->unk2AE & 2) {
        fn_800D6184(obj);
    }
}
