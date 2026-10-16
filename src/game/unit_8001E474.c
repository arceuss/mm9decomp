#include "game/stateobj.h"

extern StateObjFunc lbl_804EC7C8[2];

void fn_8001E474(StateObj* obj) {
    lbl_804EC7C8[obj->state](obj);
}
