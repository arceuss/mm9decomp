#include "types.h"

typedef struct Unk80091208 {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 state;
} Unk80091208;

extern void (*lbl_80273E78[])(Unk80091208* self);

void fn_80091208(Unk80091208* self) {
    lbl_80273E78[self->state](self);
}
