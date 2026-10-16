#include "types.h"

typedef void (*UnkFn316F0)(u8* obj);
extern UnkFn316F0 lbl_80264328[];

void fn_800316F0(u8* obj) {
    lbl_80264328[obj[5]](obj);
}
