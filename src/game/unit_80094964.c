#include "types.h"

extern u8 lbl_80316D78[];

void fn_80097864(u8*);
void fn_800965A8(u8*);

void fn_80094964(u8* p) {
    switch (p[3]) {
    case 0:
        p[3]++;
        /* fallthrough */
    case 1:
        if (*(u8*)(*(u8**)(lbl_80316D78 + 0x3004) + 0xD41024) != 0) {
            fn_80097864(p);
        } else {
            fn_800965A8(p);
        }
        break;
    }
}
