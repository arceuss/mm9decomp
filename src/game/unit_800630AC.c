#include "game/stateobj.h"

extern StateObjFunc lbl_804ECBD0[2];

void fn_800630AC(StateObj* obj) {
    lbl_804ECBD0[obj->state](obj);
}
