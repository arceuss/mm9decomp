#include "types.h"

typedef struct Unk800DBF9C {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
} Unk800DBF9C;

extern void (*lbl_80281050[])(Unk800DBF9C* obj);

void fn_800DBF9C(Unk800DBF9C* obj) {
    lbl_80281050[obj->unk14](obj);
}
