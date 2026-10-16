#include "types.h"
#include "game/obj.h"

typedef struct Vec46344 {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
} Vec46344;
typedef struct Unk46344Obj {
    /* 0x00 */ u8 pad00[0x60];
    /* 0x60 */ Vec46344 unk60;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xC8 - 0xA4];
    /* 0xC8 */ Vec46344 unkC8;
} Unk46344Obj;
typedef struct Unk46344 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ struct Unk46344* unk0C;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 pad18[0x23 - 0x18];
    /* 0x23 */ u8 unk23;
    /* 0x24 */ u8 pad24[4];
    /* 0x28 */ Unk46344Obj* unk28;
} Unk46344;
void fn_800B5ECC(Obj*, Vec46344*);
void fn_800B5F38(Obj*, s32);

void fn_80057448(Unk46344* arg) {
    Unk46344Obj* obj = arg->unk28;
    Unk46344Obj* other = arg->unk0C->unk28;
    if (arg->unk14 & 1) {
        if ((arg->unk23 & 0xFU) == 3) {
            obj->unkC8 = other->unk60;
        } else if ((arg->unk23 & 0xFU) == 8) {
            Vec46344 pos;
            pos.x = obj->unk60.x;
            pos.y = obj->unk60.y - 0x1400;
            fn_800B5ECC((Obj*)other, &pos);
        }
        if ((arg->unk23 & 0xFU) == 2 && (obj->unkA0 & 0x200)) {
            fn_800B5F38((Obj*)other, 0);
        }
    }
}
