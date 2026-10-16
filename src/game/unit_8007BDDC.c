#include "game/stateobj.h"

extern StateObjFunc lbl_804ECCE0[2];

void fn_8007BDDC(StateObj* obj) {
    lbl_804ECCE0[obj->state](obj);
}
