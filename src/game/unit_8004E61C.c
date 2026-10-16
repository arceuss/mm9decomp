#include "types.h"
#include "game/obj.h"

typedef struct Unk8004E61C {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[6];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[3];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ s8 unk17;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7D - 0x68];
    /* 0x7D */ u8 unk7D;
} Unk8004E61C;

void fn_800E947C(Unk8004E61C*, s32, s8, s32);
void fn_80073D54(s32*, s32, s32, s32);

void fn_8004E61C(Unk8004E61C* obj) {
    s32 pos[2];
    s32 d;

    switch (obj->unk12) {
    case 0:
        obj->unk16 = 0xc;
        obj->unk12++;
    case 1:
        fn_800E9758((Obj*)obj);
        if (--obj->unk16 == 0) {
            obj->unk12++;
            obj->unk17 = obj->unk7D;
        }
        break;
    case 2:
        fn_800E947C(obj, 1, obj->unk17, 0);
        obj->unk16 = 8;
        d = ((obj->unk0A >> 4) & 1) * 2 - 1;
        pos[0] = obj->unk60 + d * 0x1800;
        pos[1] = obj->unk64;
        fn_80073D54(pos, -(d * 0x400), 0, 0);
        obj->unk12++;
    case 3:
        fn_800E9758((Obj*)obj);
        if (--obj->unk16 == 0) {
            obj->unk12++;
        }
        break;
    case 4:
        fn_800E947C(obj, 0, obj->unk17, 0);
        obj->unk16 = 0x1e;
        obj->unk12++;
    case 5:
        fn_800E9758((Obj*)obj);
        if (--obj->unk16 == 0) {
            obj->unk11 = 0;
            obj->unk12 = 0;
        }
        break;
    }
}
