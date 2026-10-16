#include "game/stateobj.h"

extern StateObjFunc lbl_802806F0[];

void fn_800D630C(StateObj* obj) {
    lbl_802806F0[obj->state](obj);
}
