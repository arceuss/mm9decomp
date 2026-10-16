#include "game/stateobj.h"

extern StateObjFunc lbl_804ED058[2];

void fn_800CF494(StateObj* obj) {
    lbl_804ED058[obj->state](obj);
}
