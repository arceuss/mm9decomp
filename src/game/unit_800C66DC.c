#include "types.h"

typedef struct Unk800C66DC {
    /* 0x00 */ u8 unk0[0x10];
    /* 0x10 */ u8 unk10[0x2C];
    /* 0x3C */ u8 unk3C[0x1C];
    /* 0x58 */ u8 unk58[0x2C];
} Unk800C66DC;

void fn_8009BF14(s32 value, void* dst, s32 size);
void fn_8009BF98(s32 value, void* dst, s32 size);
void fn_8009C04C(s32 value, void* dst, s32 size);

void fn_800C66DC(Unk800C66DC* work) {
    fn_8009BF14(0, work->unk0, sizeof(work->unk0));
    fn_8009BF14(0, work->unk10, sizeof(work->unk10));
    fn_8009BF98(0, work->unk3C, sizeof(work->unk3C));
    fn_8009C04C(0, work->unk58, sizeof(work->unk58));
}
