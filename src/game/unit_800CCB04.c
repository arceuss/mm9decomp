#include "types.h"

typedef struct Vec2s32 {
    s32 x;
    s32 y;
} Vec2s32;

typedef struct Unk800CCB04Boss {
    /* 0x00 */ u8 pad0[0x17];
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0xC8 - 0x18];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 unkC9;
    /* 0xCA */ u8 unkCA;
} Unk800CCB04Boss;

typedef struct Unk800CCB04Obj {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ Unk800CCB04Boss* boss;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0xAB - 0x64];
    /* 0xAB */ u8 unkAB_hi : 4;
    /* 0xAB */ u8 unkAB_lo : 4;
} Unk800CCB04Obj;

typedef struct Unk800CCB04Hit {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk800CCB04Hit* other;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u32 flags14;
    /* 0x18 */ u8 pad18[0x28 - 0x18];
    /* 0x28 */ void* obj;
} Unk800CCB04Hit;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x260];
    /* 0x260 */ s32 unk260;
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

void fn_800B5ECC(void* target, Vec2s32* pos);
void fn_800D5458(s32 id);

void fn_800CCB04(Unk800CCB04Hit* hit) {
    void* target = hit->other->obj;
    Unk800CCB04Obj* self = hit->obj;
    Unk800CCB04Boss* boss = self->boss;
    Vec2s32 pos;

    if (hit->flags14 & 1) {
        if (self->unkAB_lo == 8) {
            pos.x = self->unk60;
            pos.y = lbl_80304B90.unk260 - 0x8000;
            fn_800B5ECC(target, &pos);
            boss->unkC8 = 1;
            boss->unkCA = 1;
            boss->unk17 = 0xB4;
            fn_800D5458(0x3B);
        }
        if (self->unkAB_lo == 6) {
            boss->unkC9 = 1;
        }
    }
}
