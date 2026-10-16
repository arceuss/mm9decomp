#include "game/stateobj.h"

extern StateObjFunc lbl_804EC800[1];

void fn_80022278(StateObj* obj) {
    lbl_804EC800[obj->state](obj);
}
