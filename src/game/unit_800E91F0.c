#include "types.h"

typedef struct Unk800E91F0 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x60 - 0xB];
    /* 0x60 */ u8 unk60[0x88 - 0x60];
    /* 0x88 */ u8 unk88[0xAC - 0x88];
    /* 0xAC */ s32 unkAC;
    /* 0xB0 */ struct Unk800E91F0* unkB0;
} Unk800E91F0;

void fn_80099918(void* work, s32 arg1, void* pos, s16 arg3);

void fn_800E91F0(Unk800E91F0* obj, s32 arg1, s32 arg2) {
    obj->flagsA |= 4;
    fn_80099918(obj->unk88, arg1, obj->unk60, arg2);
    obj->unkB0 = obj;
    obj->unkAC = 0;
}
