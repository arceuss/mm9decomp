#include "game/stateobj.h"
extern u8 fn_8007D6CC(StateObj*);
extern StateObjFunc lbl_8027011C[], lbl_80270128[];
void fn_8007D270(StateObj* p) {
    if (fn_8007D6CC(p)) return;
    lbl_8027011C[p->state](p);
    lbl_80270128[p->state](p);
}
