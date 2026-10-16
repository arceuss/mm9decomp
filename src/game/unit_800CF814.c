#include "game/stateobj.h"

extern StateObjFunc lbl_80280024[];

void fn_800CF814(StateObj* obj) {
    lbl_80280024[obj->state](obj);
}
