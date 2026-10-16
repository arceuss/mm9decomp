#include "types.h"

typedef struct Unk800C0F7C {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x60 - 0x13];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0xCB - 0x70];
    /* 0xCB */ u8 unkCB;
    /* 0xCC */ u8 unkCC;
} Unk800C0F7C;

void fn_800D5234(s32 arg);
void fn_800E9244(Unk800C0F7C* work);
void fn_800E9750(Unk800C0F7C* work, u16 arg);

void fn_800C0F7C(Unk800C0F7C* work) {
    if (work->unk12 == 0) {
        s32 v;
        s32 scale = 0x480;
        fn_800D5234(0x3E);
        if (work->unkCB & 2) {
            v = scale * (((work->unkCC & 1) << 1) - 1);
        } else {
            v = scale * (((work->unkCB & 1) << 1) - 1);
        }
        work->unk68 = -v;
        work->unk6C = -0x360;
        fn_800E9244(work);
        work->unk12++;
    }
    work->unk60 += work->unk68;
    work->unk64 += work->unk6C;
    fn_800E9750(work, 0xFFFF);
}
