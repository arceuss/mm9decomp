#include "types.h"

typedef struct Unk800C3F60 {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ void* owner;
    /* 0x38 */ u8 pad38[0xC8 - 0x38];
    /* 0xC8 */ u8 unkC8;
} Unk800C3F60;

extern void* lbl_804EE8F8;

Unk800C3F60* fn_800E8C44(void* pool);
void fn_800C2F8C(Unk800C3F60* obj, s32 arg1, s32 arg2);

Unk800C3F60* fn_800C3F60(void* owner, u8 arg1) {
    Unk800C3F60* obj = fn_800E8C44(lbl_804EE8F8);

    if (obj != NULL) {
        obj->owner = owner;
        fn_800C2F8C(obj, 1, 0);
        obj->unkC8 = arg1;
    }
    return obj;
}
