#include "game/stateobj.h"

extern StateObjFunc lbl_804ED050[2];

void fn_800CEE00(StateObj* obj) {
    lbl_804ED050[obj->state](obj);
}
