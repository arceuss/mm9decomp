#include "game/stateobj.h"

extern StateObjFunc lbl_804EC6D8[2];

void fn_800120D4(StateObj* obj) {
    lbl_804EC6D8[obj->state](obj);
}
