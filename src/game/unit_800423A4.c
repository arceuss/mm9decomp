#include "game/stateobj.h"

extern StateObjFunc lbl_804ECA38[2];

void fn_800423A4(StateObj* obj) {
    lbl_804ECA38[obj->state](obj);
}
