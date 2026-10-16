#include "types.h"

typedef struct Unk265C8Frame {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
} Unk265C8Frame;

u32 fn_8011DA80(u32* a, u32* b);

u32 fn_800265C8(void) {
    Unk265C8Frame w;
    u32 v = fn_8011DA80(&w.unk4, &w.unk0);
    return w.unk4;
}
