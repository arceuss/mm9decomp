#include "types.h"

typedef struct Unk800841DC {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 state;
} Unk800841DC;

extern void (*lbl_80272FC0[])(Unk800841DC* self);

void fn_800841DC(Unk800841DC* self) {
    lbl_80272FC0[self->state](self);
}
