#include "types.h"

typedef struct Unk80081CC0Data {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ s32 unk4;
} Unk80081CC0Data;

typedef struct Unk80081CC0 {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Unk80081CC0Data* unk28;
    /* 0x2C */ u8 pad2C[0xEC - 0x2C];
    /* 0xEC */ s32 unkEC;
} Unk80081CC0;

s32 fn_80081CC0(Unk80081CC0* self) {
    self->unkEC = self->unk28->unk4;
    return 0;
}
