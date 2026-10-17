#include "types.h"

typedef struct Unk80037398 {
    /* 0x000 */ u8 pad0[0x26D];
    /* 0x26D */ u8 unk26D;
    /* 0x26E */ u8 unk26E;
    /* 0x26F */ u8 unk26F;
    /* 0x270 */ u8 unk270;
} Unk80037398;

extern u8 lbl_80316D78[];

u32 fn_800BB6C8(u32 a);
void fn_800BB7B8(s32 arg0);
void fn_8000ECB8(s32 arg0, u32 data, s32 arg2, s32 arg3, s32 arg4);
void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

void fn_80037398(Unk80037398* obj) {
    u32 R;
    u32 a;
    u32 b;

    if ((fn_800BB6C8(1) & 0xFF) == 3) {
        fn_800BB7B8(1);
        if (obj->unk26E == 0) {
            switch (obj->unk26D) {
            case 0:
                R = *(u32*)(lbl_80316D78 + 0x3004) + 0xC29000;
                a = *(u32*)(R + 8) >> 1;
                fn_8000ECB8(0x38, a + R, 1, 2, 10);
                break;
            case 1:
                R = *(u32*)(lbl_80316D78 + 0x3004) + 0xC29000;
                a = *(u32*)(R + 8) >> 1;
                fn_8000ECB8(0x38, a + R, 2, 2, 10);
                break;
            case 2:
                R = *(u32*)(lbl_80316D78 + 0x3004) + 0xC29000;
                a = *(u32*)(R + 8) >> 1;
                fn_8000ECB8(0x38, a + R, 3, 2, 10);
                break;
            }
            obj->unk26E++;
        }
        R = *(u32*)(lbl_80316D78 + 0x3004) + 0xC29000;
        a = *(u32*)(R + 0x10) >> 1;
        b = (*(u32*)(R + 0x14) >> 1) + R;
        fn_800BB4E8(0, 0, a + R + *(u32*)(a + R), b + *(u32*)b, 0x20, 0, b, a + R);
        obj->unk26F = 2;
        obj->unk270 = 0;
    }
}
