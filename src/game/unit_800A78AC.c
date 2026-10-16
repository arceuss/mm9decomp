#include "types.h"

typedef struct Unk8037CC40 {
    /* 0x0000 */ u8 pad0[0x1008];
    /* 0x1008 */ u8 unk1008[0x7230 - 0x1008];
} Unk8037CC40;

extern Unk8037CC40 lbl_8037CC40;

void fn_800A8784(void* p);

void fn_800A78AC(void) {
    fn_800A8784(lbl_8037CC40.unk1008);
}
