#include "types.h"

typedef struct Unk800E946C {
    /* 0x00 */ u8 pad0[0x78];
    /* 0x78 */ u8 anim[0x7D - 0x78];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 unk7E;
} Unk800E946C;

void fn_800CA12C(void* anim, s32 id);

void fn_800E9474(Unk800E946C* obj, s32 id) {
    fn_800CA12C(obj->anim, id);
}
