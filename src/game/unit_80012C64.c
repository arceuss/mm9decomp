#include "game/stateobj.h"

extern StateObjFunc lbl_804EC700[2];

void fn_80012C64(StateObj* obj) {
    lbl_804EC700[obj->state](obj);
}
