#include "game/stateobj.h"

extern StateObjFunc lbl_804ECA20[2];

void fn_800411B4(StateObj* obj) {
    lbl_804ECA20[obj->state](obj);
}
