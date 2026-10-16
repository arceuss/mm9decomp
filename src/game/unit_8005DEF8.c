#include "game/obj.h"
typedef struct Unk8005DEF8 { /* 0x00 */ s32 unk0; /* 0x04 */ s32 unk4; } Unk8005DEF8;
extern void fn_80040AD0(s32, Unk8005DEF8*, s32, s32);
extern void fn_800D5234(s32);
void fn_8005DEF8(Obj* p) {
    Unk8005DEF8 v;
    fn_800E9244(p);
    p->flagsA &= ~1;
    v.unk0 = p->unk60;
    v.unk4 = p->unk64 - 0x1600;
    fn_80040AD0(3, &v, 0, 0);
    fn_800D5234(0x13);
    fn_80042CF8(p, 4);
}
