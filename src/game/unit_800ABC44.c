#include "game/stateobj.h"

extern StateObjFunc lbl_804ECE28[2];

void fn_800ABC44(StateObj* obj) {
    lbl_804ECE28[obj->state](obj);
}
