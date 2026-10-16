#include "types.h"

typedef struct Unk8008B12C {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 state;
} Unk8008B12C;

extern void (*lbl_804ECD20[2])(Unk8008B12C* self);

void fn_8008B12C(Unk8008B12C* self) {
    lbl_804ECD20[self->state](self);
}
