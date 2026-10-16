#include "types.h"
#include "game/obj.h"

void fn_8006790C(Obj* obj) {
    fn_800E9244(obj);
    obj->flagsA &= ~1;
    fn_80042CF8(obj, 4);
}
