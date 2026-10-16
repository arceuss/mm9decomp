#include "game/stateobj.h"

extern StateObjFunc lbl_804ECC30[2];

void fn_80068D68(StateObj* obj) {
    lbl_804ECC30[obj->state](obj);
}
