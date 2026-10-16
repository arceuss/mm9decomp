#include "types.h"

typedef struct UnkB675x {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 unk11;
} UnkB675x;

s32 fn_800B6770(UnkB675x* rec) {
    return ((1 << rec->unk11) & 0x707F) != 0;
}
