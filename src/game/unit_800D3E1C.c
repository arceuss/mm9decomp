#include "game/stateobj.h"

extern StateObjFunc lbl_804ED300[2];

void fn_800D3E1C(StateObj* obj) {
    lbl_804ED300[obj->state](obj);
}
