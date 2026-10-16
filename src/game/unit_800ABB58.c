#include "game/stateobj.h"

extern StateObjFunc lbl_804ECE20[2];

void fn_800ABB58(StateObj* obj) {
    lbl_804ECE20[obj->state](obj);
}
