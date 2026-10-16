#include "game/stateobj.h"

extern StateObjFunc lbl_804EC7B8[1];

void fn_8001C7A0(StateObj* obj) {
    lbl_804EC7B8[obj->state](obj);
}
