#include "game/stateobj.h"

extern StateObjFunc lbl_804EC818[1];

void fn_80024804(StateObj* obj) {
    lbl_804EC818[obj->state](obj);
}
