#include "types.h"

void fn_8009BF98(u16 value, void* dst, u32 size) {
    u32 i;

    for (i = 0; i < size; i += sizeof(u16)) {
        *(u16*)((u32)dst + i) = value;
    }
}
