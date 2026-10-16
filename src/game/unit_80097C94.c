#include "types.h"

typedef struct Unk80097C94 {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 state;
} Unk80097C94;

extern void (*lbl_804ECDC8[2])(Unk80097C94* self);

void fn_80097C94(Unk80097C94* self) {
    lbl_804ECDC8[self->state](self);
}
