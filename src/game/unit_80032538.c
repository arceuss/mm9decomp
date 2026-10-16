#include "types.h"
#include "game/sound.h"

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

void fn_80032538(u8* obj) {
    u8 t = obj[0x26E];
    if (t == 2) {
        fn_800D56A4(BGM_PASSWORD);
        fn_800316C8((Unk316C8*)obj, 6);
        fn_8008C07C(lbl_803140C0, 0);
    } else if (t == 3) {
        obj[0x26E] = 1;
    }
}
