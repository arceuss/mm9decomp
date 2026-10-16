#include "types.h"

typedef struct Unk800D9BE0 {
    /* 0x00 */ u8 pad0[0x8C];
    /* 0x8C */ u8 unk8C;
} Unk800D9BE0;

extern void (*lbl_80280E7C[])(Unk800D9BE0* obj);

void fn_800D9BE0(Unk800D9BE0* obj) {
    lbl_80280E7C[obj->unk8C](obj);
}
