#include "game/stateobj.h"

extern StateObjFunc lbl_804ECBE8[2];

void fn_800642FC(StateObj* obj) {
    lbl_804ECBE8[obj->state](obj);
}
