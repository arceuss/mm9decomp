#include "types.h"
#include "game/obj.h"

typedef struct Unk800CE5B0 {
    /* 0x00 */ u8 pad00[9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15b[3];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x54 - 0x1C];
    /* 0x54 */ u32 unk54hi : 21;
    /* 0x54 */ u32 unk54bit : 1;
    /* 0x54 */ u32 unk54lo : 10;
    /* 0x58 */ u8 pad58[8];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ s32 unkCC;
} Unk800CE5B0;

typedef struct Unk80280390Entry {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

extern Unk80280390Entry* lbl_80280390[];
void fn_800C7C24(s32, s32, s32);
void fn_800E9758(Obj*);
void fn_800E9CB8(Unk800CE5B0*);
s32 fn_800EB16C(s32, s32);

void fn_800CE5B0(Unk800CE5B0* obj) {
    s32 x, y, length, scale, speed;

    switch (obj->unk12) {
    case 0:
        fn_800E9244((Obj*)obj);
        obj->unk12++;
    case 1:
        x = obj->unkC8 - obj->unk60;
        y = obj->unkCC - obj->unk64;
        length = fn_800EB16C(x, y);
        if (length <= 0x800) {
            obj->unk18 = lbl_80280390[obj->unk9]->unk8;
            obj->unk10 = 2;
            obj->unk12 = 0;
            obj->unk13 = 0;
            obj->unk11 = 0;
            fn_800E9CB8(obj);
            obj->unk0A &= ~1;
            fn_800E9244((Obj*)obj);
            obj->unk18 = lbl_80280390[obj->unk9]->unk10;
            obj->unk10 = 4;
            obj->unk11 = 0;
            obj->unk12 = 0;
            obj->unk13 = 0;
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
