#include "types.h"

void fn_8009BF14(u8 value, void* dst, u32 size) {
    u32 i;

    for (i = 0; i < size; i += sizeof(u8)) {
        *(u8*)((u32)dst + i) = value;
    }
}
