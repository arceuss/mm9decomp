#include "game/stateobj.h"

extern StateObjFunc lbl_8026790C[];

void fn_800620A4(StateObj* obj) {
    lbl_8026790C[obj->state](obj);
}
