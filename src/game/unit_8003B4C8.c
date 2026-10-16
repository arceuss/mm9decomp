#include "types.h"

typedef void (*UnkFn3B4C8)(u8* obj);
extern UnkFn3B4C8 lbl_80264AA0[];

void fn_8003B4C8(u8* obj) {
    lbl_80264AA0[obj[5]](obj);
}
