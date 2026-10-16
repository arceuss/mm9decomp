#include "game/stateobj.h"

extern StateObjFunc lbl_804EC740[2];

void fn_80014D54(StateObj* obj) {
    lbl_804EC740[obj->state](obj);
}
