#include "types.h"

typedef struct Unk316C8 {
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u32 unk8;
} Unk316C8;

extern u8 lbl_803140C0[];
void fn_800316C8(Unk316C8* obj, u32 arg);
void fn_8008C07C(u8* p, u32 v);
void fn_800D56A4(s32 a);
void fn_80036130(u8* o, s32 a);

void fn_800330D0(u8* obj) {
    if (obj[0x28E] == 1) {
        u8 kind = obj[0x26E];
        if (kind == 2) {
            fn_800D56A4(7);
            fn_800316C8((Unk316C8*)obj, 6);
            fn_8008C07C(lbl_803140C0, 0x300);
        } else if (kind == 3) {
            obj[0x26E] = 1;
        }
    } else {
        fn_80036130(obj, 0);
    }
}
