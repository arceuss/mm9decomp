#include "types.h"

typedef struct Unk80301308Boss {
    /* 0x00 */ u8 pad0[0xB6];
    /* 0xB6 */ s16 unkB6;
} Unk80301308Boss;

typedef struct Unk80301308 {
    /* 0x00 */ void* player;
    /* 0x04 */ Unk80301308Boss* boss;
    /* 0x08 */ void* lifeGauge;
    /* 0x0C */ void* weaponGauge;
    /* 0x10 */ void* bossGauge;
} Unk80301308;

extern Unk80301308 lbl_80301308;

u32 fn_800B5934(void* player);
u32 fn_800B592C(void* player);
BOOL fn_800B5AA4(void* player);
u32 fn_800B59B4(void* player);
u32 fn_800B5990(void* player);
u8 fn_800245F4(void* gauge, u8 max);
u8 fn_800245D4(void* gauge, u8 value);
void fn_8002461C(void* gauge);
u8 fn_80024614(void* gauge);
void fn_8002458C(void* gauge, s32 mode);

void fn_80024058(BOOL force) {
    u8 a;

    if (lbl_80301308.player != NULL) {
        a = fn_800245F4(lbl_80301308.lifeGauge, fn_800B5934(lbl_80301308.player) >> 2);
        if ((u8)(a | fn_800245D4(lbl_80301308.lifeGauge, fn_800B592C(lbl_80301308.player))) || force == TRUE) {
            fn_8002461C(lbl_80301308.lifeGauge);
        }
    }
    if (lbl_80301308.player != NULL) {
        if (fn_800B5AA4(lbl_80301308.player)) {
            a = fn_800245F4(lbl_80301308.weaponGauge, fn_800B59B4(lbl_80301308.player) >> 10);
            if ((u8)(a | fn_800245D4(lbl_80301308.weaponGauge, (fn_800B5990(lbl_80301308.player) + 0xFF) >> 8)) || force == TRUE) {
                fn_8002461C(lbl_80301308.weaponGauge);
            }
            if (!fn_80024614(lbl_80301308.weaponGauge)) {
                fn_8002458C(lbl_80301308.weaponGauge, 1);
            }
        } else if (fn_80024614(lbl_80301308.weaponGauge)) {
            fn_8002458C(lbl_80301308.weaponGauge, 2);
        }
    }
    if (lbl_80301308.boss != NULL) {
        if (fn_800245D4(lbl_80301308.bossGauge, lbl_80301308.boss->unkB6) || force == TRUE) {
            fn_8002461C(lbl_80301308.bossGauge);
        }
    }
}
