#include "game/stateobj.h"

extern StateObjFunc lbl_804EC788[1];

void fn_80019A3C(StateObj* obj) {
    lbl_804EC788[obj->state](obj);
}
