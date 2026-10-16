#include "types.h"

typedef struct Unk800E946C {
    /* 0x00 */ u8 pad0[0x78];
    /* 0x78 */ u8 anim[0x7D - 0x78];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 unk7E;
} Unk800E946C;

void fn_800C9EEC(void* anim, s32 id);

void fn_800E947C(Unk800E946C* obj, s32 id, u8 arg2, u8 arg3) {
    fn_800C9EEC(obj->anim, id);
    obj->unk7D = arg2;
    obj->unk7E = arg3;
}
