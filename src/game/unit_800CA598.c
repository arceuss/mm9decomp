#include "game/stateobj.h"

extern StateObjFunc lbl_8027F764[];

void fn_800CA598(StateObj* obj) {
    lbl_8027F764[obj->state](obj);
}
