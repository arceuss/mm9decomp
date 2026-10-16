#include "types.h"

extern u8 lbl_80301308[];
void fn_80024614(u8* work);

void fn_80024048(void) {
    fn_80024614(*(u8**)(lbl_80301308 + 0x10));
}
