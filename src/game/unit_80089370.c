#include "types.h"

typedef struct Unk80089370 {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 state;
} Unk80089370;

extern void (*lbl_802734C0[])(Unk80089370* self);

void fn_80089370(Unk80089370* self) {
    lbl_802734C0[self->state](self);
}
