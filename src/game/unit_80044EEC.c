#include "types.h"
#include "game/obj.h"

typedef struct Unk804EE984 {
    /* 0x00 */ u8 pad00[0x64];
    /* 0x64 */ s32 unk64;
} Unk804EE984;

typedef struct Unk44EEC {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[7];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[3];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
} Unk44EEC;

extern Unk804EE984* lbl_804EE984;
extern u8 lbl_80304B90[];

void fn_80042D30(Unk44EEC*);
void fn_800E946C(Unk44EEC*, s32);
void fn_800E9750(Unk44EEC*, u16);
void fn_800E9758(Obj*);
s32 fn_800A36F8(s32, s32);
s32 fn_800A3CD4(s32, s32);
s32 fn_800A3FAC(s32, s32);
u32 fn_80080484(void*, void*, s32);

void fn_80044EEC(Unk44EEC* obj) {
    s32 d;

    switch (obj->unk12) {
    case 0:
        fn_800E946C(obj, 0);
        obj->unk16 = 0;
        obj->unk17 = 0;
        obj->unk12++;
    case 1:
        if (obj->unk64 - 0x1000 < lbl_804EE984->unk64 && obj->unk64 + 0x200 > lbl_804EE984->unk64) {
            obj->unk68 = 0x200;
        } else {
            obj->unk68 = 0x80;
        }
        obj->unk68 *= (obj->unk16 != 0) ? 1 : -1;
        if (obj->unk17 == 0) {
            obj->unk60 += obj->unk68;
            fn_800E9750(obj, 0xFFFF);
        } else {
            obj->unk17--;
            fn_800E9758((Obj*)obj);
        }
        if (obj->unk16 != 0) {
            if (fn_800A36F8(obj->unk60 + 0x800, obj->unk64 + 0x200) == 0) {
                obj->unk16 = !obj->unk16;
            }
            d = fn_800A3CD4(obj->unk60 + 0x800, obj->unk64);
            if (d != 0) {
                obj->unk60 += d;
                obj->unk16 = !obj->unk16;
            }
        } else {
            if (fn_800A36F8(obj->unk60 - 0x800, obj->unk64 + 0x200) == 0) {
                obj->unk16 = !obj->unk16;
            }
            d = fn_800A3FAC(obj->unk60 - 0x800, obj->unk64);
            if (d != 0) {
                obj->unk60 += d;
                obj->unk16 = !obj->unk16;
            }
        }
        if (fn_80080484(lbl_80304B90 + 0x21C, &obj->unk60, 1) > 0x2000) {
            fn_80042D30(obj);
        }
        break;
    }
}
