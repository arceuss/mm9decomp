#include "types.h"

typedef struct Unk80091A70 {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 state;
} Unk80091A70;

extern void (*lbl_80273F30[])(Unk80091A70* self);

void fn_80091A70(Unk80091A70* self) {
    lbl_80273F30[self->state](self);
}
