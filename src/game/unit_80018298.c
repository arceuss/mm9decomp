#include "types.h"

typedef void (*UnkFn18298)(u8*);
extern UnkFn18298 lbl_804EC768[2];

void fn_80018298(u8* obj) {
    lbl_804EC768[obj[0x11]](obj);
}
