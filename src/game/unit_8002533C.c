#include "types.h"

extern u8 lbl_80301320[];

void fn_8002533C(void) {
    lbl_80301320[1] = lbl_80301320[0];
    lbl_80301320[0] = 3;
}
