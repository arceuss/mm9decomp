#include "types.h"
extern u8 lbl_80383E70[];
extern s32 fn_8017530C(const char*, const char*);
void* fn_800AAA88(const char* input) {
    const char* name = input;
    u32 i;
    char* entry;
    u32 count;
    if (*name == '.') name++;
    if (*name == '/') name++;
    count = *(u32*)(lbl_80383E70 + 0x2028);
    entry = (char*)lbl_80383E70 + 0x2430;
    for (i = 0; i < count; entry += 0x50, i++) {
        if (fn_8017530C(name, entry) == 0) break;
    }
    return *(void**)(lbl_80383E70 + i * 4 + 0x202C);
}
