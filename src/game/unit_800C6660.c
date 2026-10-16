#include "types.h"

typedef struct Unk800C6660 {
    /* 0x00 */ u8 unk0[0x8];
    /* 0x08 */ u8 unk8[0x4];
    /* 0x0C */ u8 unkC[0x10];
    /* 0x1C */ u8 unk1C[0x18];
    /* 0x34 */ u8 unk34[0x30];
} Unk800C6660;

void fn_8009BF14(s32 value, void* dst, s32 size);
void fn_8009BF98(s32 value, void* dst, s32 size);
void fn_8009C04C(s32 value, void* dst, s32 size);

void fn_800C6660(Unk800C6660* work) {
    fn_8009BF14(0, work->unk0, sizeof(work->unk0));
    fn_8009BF14(0, work->unk8, sizeof(work->unk8));
    fn_8009BF14(0, work->unkC, sizeof(work->unkC));
    fn_8009BF98(0, work->unk1C, sizeof(work->unk1C));
    fn_8009C04C(0, work->unk34, sizeof(work->unk34));
}
