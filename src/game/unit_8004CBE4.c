#include "types.h"
#include "game/obj.h"

typedef struct Unk8004CBE4 {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[7];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x60 - 0x15];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAB - 0x68];
    /* 0xAB */ u8 unkAB_hi : 4;
    /* 0xAB */ u8 hitType : 4;
    /* 0xAC */ u8 padAC[0xD0 - 0xAC];
    /* 0xD0 */ u8 unkD0;
} Unk8004CBE4;

extern u8 lbl_80304B90[];

void fn_800E9244(Obj*);
void fn_80040AD0(s32, s32*, s32, s32);
void fn_80042CF8(Obj*, s32);
void fn_8004BC78(Unk8004CBE4*, s32, s32);

#define DIR (((obj->unk0A >> 4) & 1) * 2 - 1)

void fn_8004CBE4(Unk8004CBE4* obj) {
    s32 pos[2];

    if (obj->unk12 == 0) {
        fn_800E9244((Obj*)obj);
        obj->unk0A &= ~1;
        pos[0] = obj->unk60;
        pos[1] = obj->unk64;
        fn_80040AD0(2, pos, 0, 0);
        if (obj->hitType != 3) {
            switch (obj->unk14) {
            case 0:
                fn_8004BC78(obj, DIR * 0x700, -0x700);
                fn_8004BC78(obj, DIR * 0x900, 0x500);
                fn_8004BC78(obj, DIR * 0x500, 0x900);
                break;
            case 1:
                fn_8004BC78(obj, DIR * 0x500, -0x900);
                fn_8004BC78(obj, DIR * 0xb00, 0x500);
                fn_8004BC78(obj, DIR * 0x700, 0x700);
                break;
            case 2:
                fn_8004BC78(obj, DIR * 0xb00, -0xb00);
                fn_8004BC78(obj, DIR * 0x500, -0x500);
                fn_8004BC78(obj, DIR * 0x500, -0x900);
                fn_8004BC78(obj, DIR * 0x900, -0x700);
                break;
            case 3:
                fn_8004BC78(obj, DIR * 0x500, -0xb00);
                fn_8004BC78(obj, DIR * 0x900, -0x900);
                fn_8004BC78(obj, DIR * 0xb00, -0x500);
                fn_8004BC78(obj, DIR * 0xb00, 0);
                break;
            }
        }
        if (obj->unk14 == 4) {
            fn_80042CF8((Obj*)obj, 4);
        } else {
            obj->unkD0 = 0;
            obj->unk12 = 1;
            obj->unk60 = *(s32*)(lbl_80304B90 + 0x25C);
            obj->unk64 = *(s32*)(lbl_80304B90 + 0x260);
        }
    } else {
        if (obj->unkD0 == 0) {
            fn_80042CF8((Obj*)obj, 4);
        } else {
            obj->unk60 = *(s32*)(lbl_80304B90 + 0x25C);
            obj->unk64 = *(s32*)(lbl_80304B90 + 0x260);
        }
        obj->unkD0 = 0;
    }
}
