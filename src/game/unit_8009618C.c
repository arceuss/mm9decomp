#include "types.h"

typedef struct Unk8009618CGfx {
    /* 0x0000 */ u8 pad0[0x101C];
    /* 0x101C */ u16 owned;
} Unk8009618CGfx;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;

void fn_800D6848(s32 kind, s32 id);

#define GFX ((Unk8009618CGfx*)(lbl_80316D78.unk3004 + 0xD40000))

void fn_8009618C(void) {
    if (GFX->owned & (1 << 0)) {
        fn_800D6848(0, 0);
    }
    if (GFX->owned & (1 << 1)) {
        fn_800D6848(0, 1);
    }
    if (GFX->owned & (1 << 2)) {
        fn_800D6848(0, 2);
    }
    if (GFX->owned & (1 << 3)) {
        fn_800D6848(0, 3);
    }
    if (GFX->owned & (1 << 4)) {
        fn_800D6848(0, 4);
    }
    if (GFX->owned & (1 << 5)) {
        fn_800D6848(0, 5);
    }
    if (GFX->owned & (1 << 6)) {
        fn_800D6848(0, 6);
    }
    if (GFX->owned & (1 << 7)) {
        fn_800D6848(0, 7);
    }
    if (GFX->owned & (1 << 8)) {
        fn_800D6848(0, 8);
    }
    if (GFX->owned & (1 << 9)) {
        fn_800D6848(0, 9);
    }
    if (GFX->owned & (1 << 10)) {
        fn_800D6848(0, 10);
    }
    fn_800D6848(1, 0);
    fn_800D6848(1, 1);
    fn_800D6848(1, 2);
    fn_800D6848(1, 3);
    fn_800D6848(1, 4);
    fn_800D6848(1, 5);
    fn_800D6848(2, 0);
    fn_800D6848(3, 0);
    fn_800D6848(4, 0);
    fn_800D6848(6, 0);
}
