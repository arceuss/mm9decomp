#include "game/stateobj.h"
extern u8 fn_8006FBEC(StateObj*);
extern StateObjFunc lbl_802687C4[], lbl_802687D8[];
void fn_8006EFD0(StateObj* p) {
    if (fn_8006FBEC(p)) return;
    lbl_802687C4[p->state](p);
    lbl_802687D8[p->state](p);
}
