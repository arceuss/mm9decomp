#include "types.h"

typedef struct Unk800800AC {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s32 (*unk18)(struct Unk800800AC* self);
} Unk800800AC;

s32 fn_800800AC(Unk800800AC* self) {
    return self->unk18(self);
}
