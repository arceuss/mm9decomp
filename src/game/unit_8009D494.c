#include "types.h"

typedef struct Unk80319DA0 {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ void* unk4;
    /* 0x0008 */ u8 pad8[0x21C0 - 0x8];
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

void fn_801165A4(void* heap, void* p);

void fn_8009D494(void* p) {
    fn_801165A4(lbl_80319DA0.unk4, p);
}
