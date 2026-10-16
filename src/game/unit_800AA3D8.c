#include "types.h"
extern u8 lbl_80383E70[];
extern s32 fn_8017530C(const char*, const char*);
extern void fn_8009C100(const void*, void*, s32);
u32 fn_800AA3D8(const char* input, u8 bank, void* dst) {
    const char* name = input;
    u32 i;
    char* entry;
    u32 count;
    u32* data;
    if (*name == '.') name++;
    if (*name == '/') name++;
    count = *(u32*)(lbl_80383E70 + 0x2028);
    entry = (char*)lbl_80383E70 + 0x2430;
    for (i = 0; i < count; entry += 0x50, i++) {
        if (fn_8017530C(name, entry) == 0) break;
    }
    data = *(u32**)(lbl_80383E70 + i * 4 + 0x202C);
    fn_8009C100(data, dst, (data[0] + 1) * 4 + 4);
    if (bank == 1 || bank == 2) {
        u32* record = (u32*)(lbl_80383E70 + 0x200C);
        if (bank == 1) record = (u32*)(lbl_80383E70 + 0x2004);
        record[1] = (u32)dst;
        record[0] = i;
    }
    return i;
}
