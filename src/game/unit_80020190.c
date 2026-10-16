#include "game/stateobj.h"

extern StateObjFunc lbl_80263260[];

void fn_80020190(StateObj* obj) {
    lbl_80263260[obj->state](obj);
}
