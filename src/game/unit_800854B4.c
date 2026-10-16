#include "types.h"
#include "game/sound.h"

typedef struct Unk800854B4 {
    /* 0x0000 */ u8 pad0[0xFF4];
    /* 0x0FF4 */ u8 unkFF4;
    /* 0x0FF5 */ u8 padFF5;
    /* 0x0FF6 */ u8 unkFF6;
    /* 0x0FF7 */ u8 padFF7[0x1010 - 0xFF7];
    /* 0x1010 */ s8 unk1010;
} Unk800854B4;

typedef struct Unk80319DA0 {
    /* 0x0000 */ u8 pad0[0x860];
    /* 0x0860 */ u32 trigger;
    /* 0x0864 */ u8 pad864[0x21C0 - 0x864];
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

void fn_800D5234(s32 id);

void fn_800854B4(Unk800854B4* menu) {
    u32 trigger = lbl_80319DA0.trigger;

    if (trigger & 0x50) {
        if (menu->unkFF6 == 1) {
            menu->unkFF6 = 0;
        } else {
            menu->unkFF6 = 1;
        }
        if (menu->unk1010 == 1) {
            fn_800D5234(SE_WEAPON_MENU);
            menu->unkFF4 = 1;
        } else {
            fn_800D5234(SE_SELECT);
        }
    } else if (trigger & 0x20) {
        if (menu->unkFF6 == 0) {
            if (menu->unk1010 == 0) {
                fn_800D5234(SE_CURSOR);
            }
            menu->unk1010 = 1;
        } else {
            menu->unkFF6 = 0;
        }
    } else if (trigger & 0x80) {
        fn_800D5234(SE_WEAPON_MENU);
        menu->unkFF4 = 1;
    }
}
