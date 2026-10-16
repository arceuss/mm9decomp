#include "types.h"
#include "game/obj.h"

void fn_800564CC(Obj* obj) {
    fn_800E9244(obj);
    obj->flagsA &= ~1;
    fn_80042CF8(obj, 4);
}
