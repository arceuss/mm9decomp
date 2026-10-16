#include "types.h"

typedef struct Unk80085904 {
    /* 0x0 */ u8 pad0[0x2];
    /* 0x2 */ u8 state;
} Unk80085904;

extern void (*lbl_80273128[3])(Unk80085904* self);

void fn_80085904(Unk80085904* self) {
    lbl_80273128[self->state](self);
}
