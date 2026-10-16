#include "game/stateobj.h"

extern StateObjFunc lbl_804ED370[2];

void fn_800D8D70(StateObj* obj) {
    lbl_804ED370[obj->state](obj);
}
