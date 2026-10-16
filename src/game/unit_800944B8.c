#include "types.h"

typedef struct Unk800944B8 {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 state;
} Unk800944B8;

extern void (*lbl_804ECDB8[2])(Unk800944B8* self);

void fn_800944B8(Unk800944B8* self) {
    lbl_804ECDB8[self->state](self);
}
