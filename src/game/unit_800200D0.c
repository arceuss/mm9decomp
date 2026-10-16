#include "types.h"

typedef struct Unk800200D0 {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
} Unk800200D0;

typedef void (*StateObjFunc)(Unk800200D0* obj);

extern StateObjFunc lbl_802631E0[];

void fn_800C75D0(Unk800200D0* obj);
u8 fn_80021FAC(Unk800200D0* obj);

void fn_800200D0(Unk800200D0* obj) {
    StateObjFunc* tbl = lbl_802631E0;
    if (obj->unk11 != 0 && obj->unk11 != 2 && obj->unk11 != 5) {
        fn_800C75D0(obj);
        if (fn_80021FAC(obj) != 0) {
            tbl[obj->unk11 + 32](obj);
            return;
        }
    }
    tbl[obj->unk11 + 14](obj);
    tbl[obj->unk11 + 23](obj);
}
