#include "types.h"

void* memcpy(void* dst, const void* src, u32 n);

void fn_8009C110(const void* src, void* dst, u32 size) {
    memcpy(dst, src, size);
}
