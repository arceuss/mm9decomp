#include "types.h"

char* strcpy(char* dst, const char* src);

extern u8 lbl_80316D78[0x3028];
extern u8 lbl_80305210[];
extern char lbl_80272FA4[];
extern char lbl_80272FB0[];

s32 fn_800AABB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 fn_801E171C(void* buf);
void fn_801E1754(void* node, void* buf);

void fn_800840F8(s32 id) {
    char buf[0x108];
    u8* bank;
    u8* res;
    u32 size;
    u32 old;

    if (id == 1) {
        strcpy(buf, lbl_80272FA4);
    } else if (id == 2) {
        strcpy(buf, lbl_80272FB0);
    } else {
        return;
    }
    bank = *(u8**)(lbl_80316D78 + 0x3008);
    res = bank + 0x2819000;
    fn_800AABB8(9, (s32)buf, (s32)res, 0);
    size = (fn_801E171C(res) + 0x1F) & ~0x1F;
    old = *(u32*)(lbl_80305210 + 0x18);
    fn_801E1754((void*)old, res);
    *(u32*)(lbl_80305210 + id * 4) = old;
    old += size;
    *(u32*)(lbl_80305210 + id * 4 + 0xC) = size;
    *(u32*)(lbl_80305210 + 0x18) = old;
}
