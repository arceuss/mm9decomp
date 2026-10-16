#include "types.h"

typedef void (*UnkFn362F8)(u8* obj);
extern UnkFn362F8 lbl_802644A8[];

void fn_800362F8(u8* obj) {
    lbl_802644A8[obj[5]](obj);
}
