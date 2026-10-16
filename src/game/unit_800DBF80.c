#include "types.h"

typedef struct Unk800DBF80 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
} Unk800DBF80;

extern void (*lbl_8028103C[])(Unk800DBF80* obj);

void fn_800DBF80(Unk800DBF80* obj) {
    lbl_8028103C[obj->unk14](obj);
}
