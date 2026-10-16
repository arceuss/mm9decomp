#include "types.h"

typedef struct UnkB5684 {
    /* 0x00 */ u8 pad0[0x10C];
    /* 0x10C */ u8 unk10C;
    /* 0x10D */ u8 unk10D;
    /* 0x10E */ u8 unk10E;
    /* 0x10F */ u8 unk10F;
    /* 0x110 */ u8 unk110;
} UnkB5684;

void fn_800B5684(UnkB5684* rec) {
    rec->unk10F = 0;
    rec->unk110 = 0;
    rec->unk10C = 0xFF;
    rec->unk10D = 0xFF;
    rec->unk10E = 0;
}
