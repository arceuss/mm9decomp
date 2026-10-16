#include "types.h"

void fn_8008DEF0(u8* p) {
    switch (*(u8*)(p + 3)) {
    case 0:
        *(u8*)(p + 0x1015) = 4;
        *(u8*)(p + 0x1017) = 2;
        *(u8*)(p + 0xFF7) = 0;
        *(u8*)(p + 3) += 1;
        /* fallthrough */
    case 1:
        if (*(u8*)(p + 0x1015) != 0) {
            return;
        }
        *(u8*)(p + 1) = 5;
        *(u8*)(p + 2) = 0;
        *(u8*)(p + 3) = 0;
        return;
    }
}
