#include "types.h"

typedef struct Unk800DBFF0 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
} Unk800DBFF0;

extern void (*lbl_8028108C[])(Unk800DBFF0* obj);

void fn_800DBFF0(Unk800DBFF0* obj) {
    lbl_8028108C[obj->unk14](obj);
}
