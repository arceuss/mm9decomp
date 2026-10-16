#include "game/stateobj.h"

extern StateObjFunc lbl_804ECCC8[2];

void fn_80077664(StateObj* obj) {
    lbl_804ECCC8[obj->state](obj);
}
