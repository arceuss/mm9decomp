#include "game/stateobj.h"

extern StateObjFunc lbl_804EC6B8[2];

void fn_80010D64(StateObj* obj) {
    lbl_804EC6B8[obj->state](obj);
}
