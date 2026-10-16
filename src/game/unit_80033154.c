#include "types.h"
#include "game/sound.h"

extern u8 lbl_803140C0[];

extern void fn_800D56A4(s32 a);
extern void fn_800316C8(u8* o, u32 v);
extern void fn_8008C07C(u8* p, u32 v);
extern void fn_80036130(u8* o, s32 a);

void fn_80033154(u8* o) {
    if (o[0x28E] == 1) {
        if (o[0x26E] == 2) {
            fn_800D56A4(BGM_PASSWORD);
            fn_800316C8(o, 6);
            fn_8008C07C(lbl_803140C0, 0x10400);
        } else if (o[0x26E] == 3) {
            o[0x26E] = 1;
        }
    } else {
        fn_80036130(o, 0);
    }
}
