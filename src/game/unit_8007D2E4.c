#include "game/stateobj.h"

extern StateObjFunc lbl_804ECCF0[2];

void fn_8007D2E4(StateObj* obj) {
    lbl_804ECCF0[obj->state](obj);
}
