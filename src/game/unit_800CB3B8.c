#include "game/stateobj.h"

extern StateObjFunc lbl_804ECFC0[2];

void fn_800CB3B8(StateObj* obj) {
    lbl_804ECFC0[obj->state](obj);
}
