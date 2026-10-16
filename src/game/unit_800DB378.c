#include "game/stateobj.h"

extern StateObjFunc lbl_80280F18[];

void fn_800DB378(StateObj* obj) {
    lbl_80280F18[obj->state](obj);
}
