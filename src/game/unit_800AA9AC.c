#include "types.h"
extern u8 lbl_80383E70[];
extern s32 fn_8017530C(const char*, const char*);
extern void fn_8009C100(const void*, void*, s32);
s32 fn_800AA9AC(const char* input, void* dst, u32 size, u32 offset) {
    const char* name = input;
    u32 i;
    char* entry;
    u32 count;
    u32 start, limit, end;
    s32 length;
    if (*name == '.') name++;
    if (*name == '/') name++;
    count = *(u32*)(lbl_80383E70 + 0x2028);
    entry = (char*)lbl_80383E70 + 0x2430;
    for (i = 0; i < count; entry += 0x50, i++) {
        if (fn_8017530C(name, entry) == 0) break;
    }
    start = *(u32*)(lbl_80383E70 + i * 4 + 0x202C);
    limit = *(u32*)(lbl_80383E70 + i * 4 + 0x2030);
    start += offset;
    end = start + size;
    if (end > limit) end = limit;
    length = end - start;
    if (length > 0) {
        fn_8009C100((void*)start, dst, length);
        return length;
    }
    return 0;
}
