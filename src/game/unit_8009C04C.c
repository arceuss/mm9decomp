#include "types.h"

void fn_8009C04C(u32 value, void* dst, u32 size) {
    u32 i;

    for (i = 0; i < size; i += sizeof(u32)) {
        *(u32*)((u32)dst + i) = value;
    }
}
