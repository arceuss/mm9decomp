#include "types.h"

typedef struct Unk800C283C {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 pad12[0x34 - 0x12];
    /* 0x34 */ struct Unk800C283CParent* unk34;
} Unk800C283C;

typedef struct Unk800C283CParent {
    /* 0x000 */ u8 pad0[0x148];
    /* 0x148 */ Unk800C283C* unk148;
} Unk800C283CParent;

typedef void (*Unk800C283CFunc)(Unk800C283C*);

extern Unk800C283CFunc lbl_8027F20C[];
extern Unk800C283CFunc lbl_8027F218[];

void fn_800C283C(Unk800C283C* work) {
    lbl_8027F20C[work->unk11](work);
    lbl_8027F218[work->unk11](work);
    work->unk34->unk148 = work;
}
