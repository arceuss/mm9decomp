#include "types.h"

typedef struct Unk800DC044 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
} Unk800DC044;

extern void (*lbl_802810C8[])(Unk800DC044* obj);

void fn_800DC044(Unk800DC044* obj) {
    lbl_802810C8[obj->unk14](obj);
}
