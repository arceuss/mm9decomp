#include "types.h"

typedef struct Unk8008C1CC {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 state;
} Unk8008C1CC;

extern void (*lbl_80273648[])(Unk8008C1CC* self);

void fn_8008C1CC(Unk8008C1CC* self) {
    lbl_80273648[self->state](self);
}
