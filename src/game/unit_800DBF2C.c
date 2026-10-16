#include "types.h"

typedef struct Unk800DBF2C {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
} Unk800DBF2C;

extern void (*lbl_80281000[])(Unk800DBF2C* obj);

void fn_800DBF2C(Unk800DBF2C* obj) {
    lbl_80281000[obj->unk14](obj);
}
