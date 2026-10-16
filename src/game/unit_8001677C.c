#include "game/stateobj.h"

extern StateObjFunc lbl_804EC750[1];

void fn_8001677C(StateObj* obj) {
    lbl_804EC750[obj->state](obj);
}
