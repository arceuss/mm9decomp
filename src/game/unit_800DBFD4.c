#include "types.h"

typedef struct Unk800DBFD4 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
} Unk800DBFD4;

extern void (*lbl_80281078[])(Unk800DBFD4* obj);

void fn_800DBFD4(Unk800DBFD4* obj) {
    lbl_80281078[obj->unk14](obj);
}
