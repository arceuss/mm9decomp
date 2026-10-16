#include "game/stateobj.h"
extern u8 fn_8007CE30(StateObj*);
extern StateObjFunc lbl_802700BC[], lbl_802700C8[];
void fn_8007C894(StateObj* p) {
    if (fn_8007CE30(p)) return;
    lbl_802700BC[p->state](p);
    lbl_802700C8[p->state](p);
}
