#include "game/stateobj.h"

extern StateObjFunc lbl_804ECCE8[2];

void fn_8007C908(StateObj* obj) {
    lbl_804ECCE8[obj->state](obj);
}
