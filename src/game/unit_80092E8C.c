#include "types.h"

typedef struct Unk80092E8C {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 state;
} Unk80092E8C;

extern void (*lbl_804ECD58[2])(Unk80092E8C* self);

void fn_80092E8C(Unk80092E8C* self) {
    lbl_804ECD58[self->state](self);
}
