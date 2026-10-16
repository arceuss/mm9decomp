#include "game/work_8031BF70.h"
extern u8 lbl_8043CA80[];
extern u32 fn_8000EECC(u32);
extern void fn_800C8B44(void*, void*, void*, void*, void*, void*);
void fn_8009F0A0(s32 index, u8* descriptor) {
    u8* layer = (u8*)&lbl_8031BF70 + index * 0x94;
    u8 *first, *second;
    u8* data = *(u8**)(descriptor + 0xC);
    *(u16*)(layer + 0x2C) = index;
    layer[0x2F] = 0; layer[0x2E] = 0;
    *(u16*)(layer + 0x32) = 0; *(u16*)(layer + 0x30) = 0;
    *(u32*)(layer + 0x60) = 0x80000001;
    *(u32*)(layer + 0x5C) = 0x80000001;
    *(u32*)(layer + 0x58) = 0x80000001;
    *(u32*)(layer + 0x54) = 0x80000001;
    *(u32*)(layer + 0x78) = 0x80000001;
    *(u32*)(layer + 0x74) = 0x80000001;
    *(u32*)(layer + 0x20) = 0; *(u32*)(layer + 0x24) = 1; *(u32*)(layer + 0x28) = 0;
    first = (u8*)(*(u32*)data + (u32)data);
    second = (u8*)(*(u32*)(data + 8) + (u32)data);
    if (index == 0) {
        fn_800C8B44(layer + 0x34, layer + 0x54, (u8*)&lbl_8031BF70 + 0x4AED0, first, second, *(void**)(descriptor + 0x10 + index * 4));
    } else {
        u32 offset = fn_8000EECC(*(u32*)(layer + 0x7C));
        fn_800C8B44(layer + 0x34, layer + 0x54, *(u8**)(lbl_8043CA80 + 0x258) + offset, first, second, *(void**)(descriptor + 0x10 + index * 4));
    }
}
