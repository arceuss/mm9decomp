#include "types.h"

typedef struct Unk80316398 {
    /* 0x000 */ u8 pad0[0x3];
    /* 0x003 */ u8 unk3;
    /* 0x004 */ u8 pad4[0x904 - 0x4];
    /* 0x904 */ u8 unk904[0x24];
} Unk80316398;

extern Unk80316398 lbl_80316398;

void fn_8009C04C(s32 arg0, void* dst, s32 size);

void fn_800997E4(void) {
    lbl_80316398.unk3 = 0;
    fn_8009C04C(0, lbl_80316398.unk904, sizeof(lbl_80316398.unk904));
}
