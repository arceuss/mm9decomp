#include "game/stateobj.h"

extern StateObjFunc lbl_80261EA0[];

void fn_8000F3AC(StateObj* obj) {
    lbl_80261EA0[obj->state](obj);
}
