#include "game/work_8038DC58.h"

extern u8 lbl_8027F3D8[];

void fn_800E5598(void* p);

typedef struct Unk800C7D00 {
    /* 0x00 */ u8 pad0[0x1E];
    /* 0x1E */ u8 unk1E[0x0A];
} Unk800C7D00;

void fn_800C7D00(u32 v) {
    u32 i = v & 0xFFF;
    u32 n = i - 1;

    if (n < 8) {
        u8* p = &((Unk800C7D00*)&lbl_8038DC58)->unk1E[n];
        s32 a = lbl_8027F3D8[n + 2];
        s32 c = *p;

        a = (c < a - 1) ? c + 1 : a;
        *p = a;
    }
    fn_800E5598(&lbl_8038DC58.unk90);
}
