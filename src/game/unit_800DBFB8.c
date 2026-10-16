#include "types.h"

typedef struct Unk800DBFB8 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
} Unk800DBFB8;

extern void (*lbl_80281064[])(Unk800DBFB8* obj);

void fn_800DBFB8(Unk800DBFB8* obj) {
    lbl_80281064[obj->unk14](obj);
}
