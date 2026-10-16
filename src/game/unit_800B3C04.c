#include "types.h"

typedef struct UnkB3C04 {
    /* 0x000 */ u8 pad000[0x0A];
    /* 0x00A */ u8 unk0A;
    /* 0x00B */ u8 pad00B[0x11 - 0x0B];
    /* 0x011 */ u8 unk11;
    /* 0x012 */ u8 pad012[0x19C - 0x12];
    /* 0x19C */ u32 unk19C;
    /* 0x1A0 */ u32 unk1A0;
} UnkB3C04;

void fn_800B6984(void*);
void fn_800B7A28(void*, void*, void*, u32, u32, u32);

void fn_800B3C04(UnkB3C04* obj) {
    fn_800B6984(obj);
    if ((1 << obj->unk11) & 0x13) {
        u32* p = &obj->unk19C;
        fn_800B7A28((u8*)obj + 0x60, (u8*)obj + 0xD0, p, *p, p[1],
                    ((obj->unk0A << 14) & 0x40000) | 0x180800);
    }
}
