#include "types.h"

u32 fn_800B66B0(u8* obj) {
    return (*(u32*)(obj + 0x104) >> 8) & 1;
}
