#include "game/stateobj.h"

extern StateObjFunc lbl_8028169C[];

void fn_800E2210(StateObj* obj) {
    lbl_8028169C[obj->state](obj);
}
