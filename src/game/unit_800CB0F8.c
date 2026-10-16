#include "game/stateobj.h"

extern StateObjFunc lbl_804ECFB8[2];

void fn_800CB0F8(StateObj* obj) {
    lbl_804ECFB8[obj->state](obj);
}
