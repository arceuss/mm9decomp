#include "types.h"

extern u8 lbl_80316D78[];

void fn_800948EC(u8* p) {
    switch (p[3]) {
    case 0: {
        u8* q = *(u8**)(lbl_80316D78 + 0x3004);
        q[0xD4102B] = 2;
        q = *(u8**)(lbl_80316D78 + 0x3004);
        q[0xD4102D] = 2;
        p[3]++;
    }
        /* fallthrough */
    case 1: {
        u8* q = *(u8**)(lbl_80316D78 + 0x3004);
        if (q[0xD4102B] == 0) {
            p[2] = 1;
            p[3] = 0;
        }
        break;
    }
    }
}
