#include "game/obj.h"
#include "game/sound.h"
typedef struct Unk80065414 { /* 0x00 */ s32 unk0; /* 0x04 */ s32 unk4; } Unk80065414;
extern void fn_80040AD0(s32, Unk80065414*, s32, s32);
extern void fn_800D5234(s32);
void fn_80065414(Obj* p) {
    Unk80065414 v;
    fn_800E9244(p);
    p->flagsA &= ~1;
    v.unk0 = p->unk60;
    v.unk4 = p->unk64 - 0xB00;
    fn_80040AD0(3, &v, 0, 0);
    fn_800D5234(SE_EXPLOSION);
    fn_80042CF8(p, 4);
}
