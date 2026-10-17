#include "types.h"

typedef struct Unk8005E1F4 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 padD[0x11 - 0xD];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 pad12[0x14 - 0x12];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x2F - 0x16];
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x64 - 0x30];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(struct Unk8005E1F4*);
    /* 0xB0 */ u8 padB0[0xCC - 0xB0];
    /* 0xCC */ s32 unkCC;
} Unk8005E1F4;

extern u8 lbl_804ECB18[8];
extern u8 lbl_80267258[];

void fn_80042CF8(Unk8005E1F4* obj, s32 arg1);
void fn_800E9424(Unk8005E1F4* obj, u16 anim);
void fn_800E91F0(Unk8005E1F4* obj, void* p, s32 a);
void fn_8005E128(Unk8005E1F4* obj);
void fn_8005E2F4(Unk8005E1F4* obj);

void fn_8005E1F4(Unk8005E1F4* obj) {
    u8* const p = lbl_80267258;

    fn_80042CF8(obj, 1);
    obj->state = lbl_804ECB18[obj->unk14];
    obj->flagsA |= 3;
    if (obj->unk14 == 0) {
        fn_800E9424(obj, 0x2A);
        fn_800E91F0(obj, p + 0x50, 1);
        obj->unkCC = obj->unk64;
        obj->unk2F = obj->unk15;
    } else if (obj->unk14 == 1) {
        fn_800E9424(obj, 0x3A);
        fn_800E91F0(obj, p + 0x80, 1);
        obj->unkCC = obj->unk64;
    } else {
        fn_800E9424(obj, 0x3A);
        fn_800E91F0(obj, p + 0xB0, 1);
        obj->unkC |= 0x10;
    }
    obj->unkAC = fn_8005E128;
    fn_8005E2F4(obj);
}
