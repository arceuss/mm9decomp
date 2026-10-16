#include "game/stateobj.h"

extern StateObjFunc lbl_802675F0[];

void fn_80060020(StateObj* obj) {
    lbl_802675F0[obj->state](obj);
}
