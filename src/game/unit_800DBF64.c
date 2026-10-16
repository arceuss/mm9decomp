#include "types.h"

typedef struct Unk800DBF64 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
} Unk800DBF64;

extern void (*lbl_80281028[])(Unk800DBF64* obj);

void fn_800DBF64(Unk800DBF64* obj) {
    lbl_80281028[obj->unk14](obj);
}
