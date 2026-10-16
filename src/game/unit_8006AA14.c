#include "game/stateobj.h"

extern StateObjFunc lbl_804ECC68[2];

void fn_8006AA14(StateObj* obj) {
    lbl_804ECC68[obj->state](obj);
}
