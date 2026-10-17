#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} Unk80280390Entry;

typedef struct Unk800CFC6C {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x30 - 0x1C];
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u8 pad32[0x3C - 0x32];
    /* 0x3C */ void* unk3C;
    /* 0x40 */ u8 pad40[0x60 - 0x40];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 timer;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x7C - 0x70];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 pad7D[0x7F - 0x7D];
    /* 0x7F */ u8 unk7F;
} Unk800CFC6C;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 cam[0x260 - 0x21C];
    /* 0x260 */ s32 unk260;
} Unk80304B90;

extern Unk800CFC6C* lbl_804EE984;
extern u8 lbl_804ED078[8];
extern u8 lbl_803051D8[];
extern Unk80280390Entry* lbl_80280390[];
extern Unk80304B90 lbl_80304B90;

void fn_800E946C(Unk800CFC6C* obj, u8 arg1);
void fn_800E9750(Unk800CFC6C* obj, u16 arg1);
void fn_800E9244(Unk800CFC6C* obj);
s32 fn_800B6450(Unk800CFC6C* player);
s32 fn_800B6010(Unk800CFC6C* player, Unk800CFC6C* obj);
void fn_800B6474(Unk800CFC6C* player);
s32 fn_800B6750(Unk800CFC6C* player);
void fn_800B6464(Unk800CFC6C* player);
u16 fn_8009E894(s32 x, s32 y);
s32 fn_800A36F8(s32 x, s32 y);
u16 fn_800A32FC(s32 x, s32 y);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);

static inline void Kill(Unk800CFC6C* obj) {
    obj->unkA &= ~1;
    obj->unkA &= 0xFD;
    fn_800E9244(obj);
    obj->unk18 = lbl_80280390[obj->unk9]->unkC;
    obj->unk10 = 3;
    obj->unk11 = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800CFC6C(Unk800CFC6C* obj) {
    Unk800CFC6C* player = lbl_804EE984;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 2);
        obj->step++;
        if (fn_800A36F8(obj->x, obj->y) == 0) {
            obj->step = 2;
            obj->y += 0x1200;
        }
    case 1:
        if (lbl_803051D8[2] & 0x20) {
            Kill(obj);
            return;
        }
        if (obj->unk7F == 3) {
            obj->step++;
        }
        break;
    case 2:
        fn_800E946C(obj, 3);
        obj->y -= 0x1200;
        obj->vy = -0x80;
        obj->unkB |= 0x10;
        obj->unk3C = lbl_804ED078;
        obj->unk30 = 4;
        obj->step++;
    case 3:
        if (fn_800B6450(player)) {
            if (obj->unk7C != 5) {
                fn_800B6474(player);
                Kill(obj);
                return;
            }
            obj->y = player->y + 0xB00;
            break;
        }
        obj->y += obj->vy;
        if (fn_800A32FC(obj->x, obj->y - 0xB00) || !(fn_8009E894(obj->x, obj->y - 0xB00) & 0x8000)) {
            obj->step++;
            break;
        }
        if (fn_800B6010(player, obj) && fn_800B6750(player) && player->x >= obj->x - 0x1100 &&
            player->x <= obj->x + 0x1100 && player->y <= obj->y && player->y >= obj->y - 0xE00) {
            fn_800B6464(player);
            fn_800E946C(obj, 5);
            break;
        }
        if (obj->unk7C == 5) {
            fn_800B6474(player);
            fn_800E946C(obj, 3);
        }
        if (obj->y < lbl_80304B90.unk260 - 0x6500) {
            obj->unkB &= 0xEF;
        }
        if (fn_80080484(lbl_80304B90.cam, &obj->x, 1) > 0xB00) {
            Kill(obj);
            return;
        }
        break;
    case 4:
        if (obj->unk7C == 5) {
            fn_800B6474(player);
        }
        fn_800E946C(obj, 4);
        obj->unkB &= 0xEF;
        obj->step++;
    case 5:
        if (obj->unk7F == 3) {
            Kill(obj);
            return;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
