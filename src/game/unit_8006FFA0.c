#include "game/stateobj.h"
extern u8 fn_80070AD0(StateObj*);
extern StateObjFunc lbl_80268848[], lbl_80268860[];
void fn_8006FFA0(StateObj* p) {
    if (fn_80070AD0(p)) return;
    lbl_80268848[p->state](p);
    lbl_80268860[p->state](p);
}
