#include "types.h"

typedef struct Unk800DBF48 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
} Unk800DBF48;

extern void (*lbl_80281014[])(Unk800DBF48* obj);

void fn_800DBF48(Unk800DBF48* obj) {
    lbl_80281014[obj->unk14](obj);
}
