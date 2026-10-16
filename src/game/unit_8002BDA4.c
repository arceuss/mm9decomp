#include "types.h"

typedef void (*UnkFn2BDA4)(u8* obj);
extern UnkFn2BDA4 lbl_80263F18[];

void fn_8002BDA4(u8* obj) {
    lbl_80263F18[obj[5]](obj);
}
