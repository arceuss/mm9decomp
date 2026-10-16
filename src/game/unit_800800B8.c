#include "types.h"

void fn_80080C54(void*, void*);
void fn_80080E34(void*, void*);

void fn_800800B8(u8* obj) {
    fn_80080C54(obj + 0x40, obj + 0x30);
    fn_80080E34(obj + 0x40, obj + 0x2c);
}
