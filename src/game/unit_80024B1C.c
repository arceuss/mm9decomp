#include "game/stateobj.h"

extern StateObjFunc lbl_80263964[];

void fn_80024B1C(StateObj* obj) {
    lbl_80263964[obj->state](obj);
}
