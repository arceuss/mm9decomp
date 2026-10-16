#include "game/obj.h"

typedef struct Vec2s32 {
    s32 x;
    s32 y;
} Vec2s32;

void fn_80040AD0(s32 arg0, Vec2s32* pos, s32 arg2, s32 arg3);

void fn_80046114(Obj* obj) {
    Vec2s32 pos;

    fn_800E9244(obj);
    obj->flagsA &= ~1;
    pos.x = obj->unk60;
    pos.y = obj->unk64;
    fn_80040AD0(2, &pos, 0, 0);
    fn_80042CF8(obj, 4);
}
