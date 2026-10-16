#include "game/stateobj.h"

extern StateObjFunc lbl_80267DF8[];

void fn_800671D0(StateObj* obj) {
    lbl_80267DF8[obj->state](obj);
}
