#include "types.h"

typedef struct Unk8004C0E8 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 kind;
    /* 0x15 */ u8 pad15[0x2F - 0x15];
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x54 - 0x30];
    /* 0x54 */ struct {
        u32 hi : 21;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 angleX;
    /* 0x6C */ s32 angleY;
    /* 0x70 */ s32 speedX;
    /* 0x74 */ s32 speedY;
    /* 0x78 */ u8 pad78[0xCC - 0x78];
    /* 0xCC */ s32 baseX;
    /* 0xD0 */ s32 baseY;
} Unk8004C0E8;

typedef struct Unk804EE984 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 x;
} Unk804EE984;

extern Unk804EE984* lbl_804EE984;
extern const s16 lbl_802537E8[256];

void fn_800E946C(Unk8004C0E8* obj, s32 anim);
void fn_800E9750(Unk8004C0E8* obj, u16 arg1);

void fn_8004C0E8(Unk8004C0E8* obj) {
    u32 f;
    s32 a;
    s32 d;
    Unk804EE984* pl;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->angleX = 0;
        obj->speedX = 0x100;
        obj->angleY = 0;
        obj->speedY = 0x100;
        if ((u8)(obj->kind + 0xFE) <= 1) {
            obj->unk2F = 1;
        }
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        pl = lbl_804EE984;
        d = pl->x - obj->x;
        f = d > 0;
        if (d > 0) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->bits54.flip = f;
        if (obj->kind == 0 || obj->kind == 2) {
            obj->y = obj->baseY + lbl_802537E8[(obj->angleY >> 8) & 0xFF] * 0x17FF / 256;
            obj->angleY += obj->speedY;
        } else {
            obj->x = obj->baseX + lbl_802537E8[(obj->angleX >> 8) & 0xFF] * 0x17FF / 256;
            obj->angleX += obj->speedX;
        }
        break;
    }
}
