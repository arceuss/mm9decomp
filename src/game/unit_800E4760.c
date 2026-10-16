#include "game/stateobj.h"

extern StateObjFunc lbl_802817D4[];

void fn_800E4760(StateObj* obj) {
    lbl_802817D4[obj->state](obj);
}
