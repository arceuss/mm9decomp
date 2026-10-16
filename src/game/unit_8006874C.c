#include "types.h"
#include "game/obj.h"

typedef struct Unk8006874C {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[6];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x54 - 0x15];
    /* 0x54 */ u32 unk54hi : 21;
    /* 0x54 */ u32 unk54bit : 1;
    /* 0x54 */ u32 unk54lo : 10;
    /* 0x58 */ u8 pad58[8];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ s32 unkCC;
} Unk8006874C;

extern void (*lbl_804ECBD0)(Unk8006874C*);
void fn_800C7C24(s32, s32, s32);
void fn_800E9758(Obj*);
void fn_80040AD0(s32, s32*, s32, s32);
s32 fn_800EB16C(s32, s32);

void fn_8006874C(Unk8006874C* obj) {
    s32 x, y, length, scale, speed;
    s32 pos[2];

    switch (obj->unk12) {
    case 0:
        fn_800E9244((Obj*)obj);
        obj->unk12++;
    case 1:
        x = obj->unkC8 - obj->unk60;
        y = obj->unkCC - obj->unk64;
        length = fn_800EB16C(x, y);
        if (length <= 0x800) {
            fn_80042CF8((Obj*)obj, 2);
            pos[0] = obj->unk60;
            pos[1] = obj->unk64;
            fn_80040AD0(2, pos, 0, 0);
            fn_800E9244((Obj*)obj);
            obj->unk0A &= ~1;
            fn_80042CF8((Obj*)obj, 4);
        } else {
            scale = 256 - (length * 256) / 0x2000;
            if (scale < 0x40) {
                scale = 0x40;
            }
            speed = (scale * 1024) / 256;
            x = (x * 256) / length;
            y = (y * 256) / length;
            x = (x * speed) / 256;
            y = (y * speed) / 256;
            obj->unk60 += x;
            obj->unk64 += y;
            fn_800E9758((Obj*)obj);
        }
        break;
    }
}
