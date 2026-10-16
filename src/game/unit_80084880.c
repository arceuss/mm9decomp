#include "types.h"

typedef struct Unk80084880 {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 state;
} Unk80084880;

extern void (*lbl_802730A0[])(Unk80084880* self);

void fn_80084880(Unk80084880* self) {
    lbl_802730A0[self->state](self);
}
