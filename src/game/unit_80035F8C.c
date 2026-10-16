#include "types.h"

typedef struct Unk80035F8C {
    /* 0x000 */ u8 pad0[0x26C];
    /* 0x26C */ u8 unk26C;
    /* 0x26D */ u8 unk26D;
    /* 0x26E */ u8 unk26E;
    /* 0x26F */ u8 unk26F;
    /* 0x270 */ u8 unk270;
    /* 0x271 */ u8 unk271;
    /* 0x272 */ u8 unk272;
    /* 0x273 */ u8 unk273;
    /* 0x274 */ u8 unk274;
    /* 0x275 */ u8 unk275;
    /* 0x276 */ u8 unk276;
    /* 0x277 */ u8 unk277;
    /* 0x278 */ u8 unk278;
    /* 0x279 */ u8 unk279;
    /* 0x27A */ u8 unk27A;
    /* 0x27B */ u8 unk27B;
    /* 0x27C */ u8 unk27C;
    /* 0x27D */ u8 unk27D;
    /* 0x27E */ u8 unk27E;
    /* 0x27F */ u8 unk27F;
    /* 0x280 */ u8 unk280;
    /* 0x281 */ u8 unk281;
    /* 0x282 */ u8 unk282;
    /* 0x283 */ u8 unk283;
    /* 0x284 */ u8 unk284;
    /* 0x285 */ u8 unk285;
    /* 0x286 */ u8 unk286;
    /* 0x287 */ u8 unk287;
    /* 0x288 */ u8 unk288;
    /* 0x289 */ u8 unk289;
} Unk80035F8C;

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

void fn_800D9228(Unk80035F8C* menu, Vec2i* size, s32 arg2, s32 arg3);

void fn_80035F8C(Unk80035F8C* menu) {
    Vec2i size;

    size.x = 0x10;
    size.y = 0x10;
    fn_800D9228(menu, &size, 0, 0);
    switch (menu->unk288) {
    case 10:
        menu->unk26C = 0;
        if (menu->unk289 == 0) {
            menu->unk277 = 1;
        } else if (menu->unk289 == 1) {
            menu->unk277 = 4;
        } else if (menu->unk289 == 2) {
            menu->unk277 = 3;
        }
        break;
    case 11:
        menu->unk277 = 2;
        menu->unk26C = 3;
        if (menu->unk289 == 0) {
            menu->unk27E = 0;
            menu->unk26C = 1;
            menu->unk278 = 1;
            menu->unk277 = 0;
        } else if (menu->unk289 == 1) {
            menu->unk27F = 0;
            menu->unk279 = 0;
        } else if (menu->unk289 == 2) {
            menu->unk27F = 0;
            menu->unk279 = 1;
        } else if (menu->unk289 == 3) {
            menu->unk27F = 0;
            menu->unk279 = 2;
        }
        break;
    case 12:
        menu->unk26C = 9;
        menu->unk277 = 0;
        if (menu->unk289 == 0) {
            menu->unk280 = 0;
            menu->unk27A = 0;
            menu->unk278 = 2;
        } else if (menu->unk289 == 1) {
            menu->unk280 = 0;
            menu->unk27A = 1;
            menu->unk278 = 2;
        } else if (menu->unk289 == 2) {
            menu->unk281 = 0;
            menu->unk27B = 1;
            menu->unk26C = 10;
            menu->unk278 = 3;
        }
        break;
    }
}
