#include "game/stateobj.h"

extern StateObjFunc lbl_804EC810[2];

void fn_80022D1C(StateObj* obj) {
    lbl_804EC810[obj->state](obj);
}
