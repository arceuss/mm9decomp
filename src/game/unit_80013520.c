#include "game/stateobj.h"

extern StateObjFunc lbl_804EC724[1];

void fn_80013520(StateObj* obj) {
    lbl_804EC724[obj->state](obj);
}
