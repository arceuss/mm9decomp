#include "types.h"
#include "game/obj.h"

typedef struct Unk8005C8CC {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 pad0A[7];
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
} Unk8005C8CC;

extern void (*lbl_80266DC8[])(Unk8005C8CC*);
void fn_800C7C24(s32, s32, s32);
void fn_800E9758(Obj*);
s32 fn_800EB16C(s32, s32);

void fn_8005C8CC(Unk8005C8CC* obj) {
    s32 x, y, length, scale, speed;

    switch (obj->unk12) {
    case 0:
        fn_800E9244((Obj*)obj);
        obj->unk12++;
    case 1:
        x = obj->unkC8 - obj->unk60;
        y = obj->unkCC - obj->unk64;
        if (obj->unk14 != 3) {
            y += 0xA00;
        }
        length = fn_800EB16C(x, y);
        if (length <= 0x800) {
            fn_80042CF8((Obj*)obj, 2);
            obj->unk11 = 0;
            if (obj->unk14 != 3) {
                fn_800C7C24(obj->unk08, obj->unk09, 0);
            }
            lbl_80266DC8[obj->unk11](obj);
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
