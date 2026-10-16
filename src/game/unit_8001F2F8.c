#include "game/stateobj.h"

extern StateObjFunc lbl_804EC7D8[2];

void fn_8001F2F8(StateObj* obj) {
    lbl_804EC7D8[obj->state](obj);
}
