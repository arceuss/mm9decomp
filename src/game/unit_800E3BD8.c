#include "game/stateobj.h"

extern StateObjFunc lbl_804ED3C8[2];

void fn_800E3BD8(StateObj* obj) {
    lbl_804ED3C8[obj->state](obj);
}
